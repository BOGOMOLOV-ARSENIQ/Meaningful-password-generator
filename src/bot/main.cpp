#include <tgbm/bot.hpp>
#include "pass_generator.h"
#include <iostream>
#include <sstream>

dd::task<void> coro_main(tgbm::bot& bot) {
    co_foreach(tgbm::api::Update upd, bot.updates()) {
        if (auto *msg = upd.get_message(); msg && msg->text) {
            const std::string &txt = *msg->text;
            if (txt.rfind("/pass", 0) == 0) {
                int prob = 20;
                bool valid = true;
                std::istringstream iss(txt);
                std::string cmd;
                iss >> cmd;
                if (!iss.eof()) {
                    iss >> prob;
                    if (iss.fail() || prob < 0 || prob > 100) {
                        valid = false;
                    }
                }
                if (!valid) {
                    co_await bot.api.sendMessage({
                        .chat_id = msg->chat->id,
                        .text = "Пожалуйста, укажите вероятность от 0% до 100% после /pass, например: /pass 20"
                    });
                } else {
                    auto pwd = generate_password(prob);
                    co_await bot.api.sendMessage({
                        .chat_id = msg->chat->id,
                        .text = "🔐 Сгенерированный пароль: " + pwd
                    });
                }
            } else {
                co_await bot.api.sendMessage({
                    .chat_id = msg->chat->id,
                    .text = "Отправь /pass чтобы сгенерировать пароль или /pass <вероятность замены символов по умолчанию 20%>"
                });
            }
        }
    }
}

int main() {
    const char* token_cstr = std::getenv("BOT_TOKEN");
    if (!token_cstr) {
        std::cerr << "Нет переменной окружения BOT_TOKEN" << std::endl;
        return 1;
    }
    std::string token(token_cstr);
    tgbm::bot bot{token};

    // bot.commands.add("pass", [&bot](tgbm::api::Message msg) {
    //     auto pwd = generate_password();
    //     bot.api.sendMessage({
    //             .chat_id = msg.chat->id,
    //             .text = "🔐 Сгенерированный пароль: " + pwd
    //         })
    //         .start_and_detach();
    // });

    coro_main(bot).start_and_detach();
    bot.run();
    
    return 0;
}
