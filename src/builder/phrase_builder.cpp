#include "phrase_builder.h"
#include "data.h"

std::string pick_adj() {
    return adjectives[rnd_gen() % adjectives.size()];
}

std::string pick_noun() {
    return nouns[rnd_gen() % nouns.size()];
}

std::string pick_verb() {
    return verbs[rnd_gen() % verbs.size()];
}

std::vector<std::string> pick_phrase() {
    int type = rnd_gen() % 4;
    std::vector<std::string> words;

    switch (type) {
    case 0:
        words.emplace_back(pick_adj());
        words.emplace_back(pick_noun());
        words.emplace_back(pick_verb());
        break;
    case 1:
        words.emplace_back(pick_noun());
        words.emplace_back(pick_verb());
        words.emplace_back(pick_adj());
        break;
    case 2:
        words.emplace_back(pick_adj());
        words.emplace_back(pick_noun());
        break;
    case 3:
        words.emplace_back(pick_noun());
        words.emplace_back(pick_verb());
        break;
    }
    return words;
}

