#include "utils.h"
#include "data.h"

int sum_sizes(const std::vector<std::string>& words) {
    int sum = 0;
    for (const auto& i : words) { // Используем const auto& для эффективности
        sum += i.size();
    }
    return sum;
}

void heading(std::string& word) {
    if (!word.empty()) { // Проверяем, что слово не пустое
        word[0] = std::toupper(static_cast<unsigned char>(word[0])); // Приводим к unsigned char для std::toupper
    }
}

std::string join(std::vector<std::string> words) {
    int type = rnd_gen() % 5;
    std::string pwd;

    switch (type) {
    case 0:
        pascal_case(words, pwd);
        break;
    case 1:
        camel_case(words, pwd);
        break;
    case 2:
        snake_case(words, pwd);
        break;
    case 3:
        kebab_case(words, pwd);
        break;
    case 4:
        special_case(words, pwd);
        break;
    }
    return pwd;
}

void pascal_case(std::vector<std::string>& words, std::string& pwd) {
    pwd.reserve(sum_sizes(words));
    for (auto& i : words) {
        heading(i);
        pwd += i;
    }
}

void camel_case(std::vector<std::string>& words, std::string& pwd) {
    pwd.reserve(sum_sizes(words));
    pwd += words[0];
    for (size_t i = 1; i < words.size(); i++) {
        heading(words[i]);
        pwd += words[i];
    }
}

void snake_case(std::vector<std::string>& words, std::string& pwd) {
    pwd.reserve(sum_sizes(words) + words.size() - 1);
    pwd += words[0];
    for (size_t i = 1; i < words.size(); i++) {
        pwd += '_';
        pwd += words[i];
    }
}

void kebab_case(std::vector<std::string>& words, std::string& pwd) {
    pwd.reserve(sum_sizes(words) + words.size() - 1);
    pwd += words[0];
    for (size_t i = 1; i < words.size(); i++) {
        pwd += '-';
        pwd += words[i];
    }
}

void special_case(std::vector<std::string>& words, std::string& pwd) {
    pwd.reserve(sum_sizes(words) + words.size() - 1);
    pwd += words[0];
    for (size_t i = 1; i < words.size(); i++) {
        pwd += special_chars[rnd_gen() % special_chars.size()];
        pwd += words[i];
    }
}