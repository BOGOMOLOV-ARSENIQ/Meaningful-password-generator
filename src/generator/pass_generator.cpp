#include "pass_generator.h"
#include "phrase_builder.h"
#include "formatter.h"
#include "utils.h"

std::string generate_password(int prob) {
    std::string pwd = join(pick_phrase());
    leet_speak(pwd, prob);
    return pwd;
}