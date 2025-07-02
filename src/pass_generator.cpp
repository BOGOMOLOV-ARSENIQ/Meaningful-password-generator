#include "pass_generator.h"

std::mt19937_64 rnd_gen{
    std::random_device{}() ^ 
    std::mt19937_64::result_type(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()
    ) 
};

std::vector<std::string> adjectives{
    "bright", "dark", "fast", "slow", "happy", "sad", "big", "small",
    "red", "blue", "green", "strong", "weak", "quiet", "loud", "old", "new",
    "clever", "brave", "funny", "wise", "mysterious", "gentle", "wild", "smooth"
};

std::vector<std::string> nouns{
    "sun", "moon", "star", "cat", "dog", "bird", "tree", "flower",
    "river", "ocean", "mountain", "cloud", "book", "music", "house", "city",
    "computer", "phone", "car", "road", "mouse", "keyboard", "table", "chair",
    "journey", "secret", "dream", "whisper", "shadow", "thunder", "diamond"
};

std::vector<std::string> verbs{
    "run", "jump", "sleep", "read", "write", "draw", "play",
    "love", "think", "watch", "listen", "speak", "laugh", "cry",
    "discover", "imagine", "explore", "create", "travel", "remember", "fly"
};

std::string special_chars{"!@#$%^&*|/\\"};

std::map<char, std::vector<char>> leet_map = {
    {'a', {'@', '4'}},
    {'e', {'3'}},
    {'i', {'1', '!'}},
    {'o', {'0'}},
    {'s', {'$', '5'}},
    {'t', {'7', '+'}},
    {'l', {'1'}}
};


std::string pick_adj() {
    return adjectives[rnd_gen() % adjectives.size()];
}

std::string pick_noun() {
    return nouns[rnd_gen() % nouns.size()];
}

std::string pick_verb() {
    return verbs[rnd_gen() % verbs.size()];
}


// "adj_noun_verb", "noun_verb_adj", "adj_noun", "noun_verb"
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


int sum_sizes(std::vector<std::string> &words) {
    int sum = 0;
    for (auto &i : words) {
        sum += i.size();
    }
    return sum;
}

void heading(std::string &word) {
    word[0] = std::toupper(word[0]);
}

void pascal_case(std::vector<std::string> &words, std::string &pwd) {
    pwd.reserve(sum_sizes(words));

    for (auto &i : words) {
        heading(i);
        pwd += i;
    }
}

void camel_case(std::vector<std::string> &words, std::string &pwd) {
    pwd.reserve(sum_sizes(words));

    pwd += words[0];
    for (int i = 1; i < words.size(); i++) {
        heading(words[i]);
        pwd += words[i];
    }
}

void snake_case(std::vector<std::string> &words, std::string &pwd) {
    pwd.reserve(sum_sizes(words) + words.size() - 1);

    pwd += words[0];
    for (int i = 1; i < words.size(); i++) {
        pwd += '_';
        pwd += words[i];
    }
}

void kebab_case(std::vector<std::string> &words, std::string &pwd) {
    pwd.reserve(sum_sizes(words) + words.size() - 1);

    pwd += words[0];
    for (int i = 1; i < words.size(); i++) {
        pwd += '-';
        pwd += words[i];
    }
}

void special_case(std::vector<std::string> &words, std::string &pwd) {
    pwd.reserve(sum_sizes(words) + words.size() - 1);

    pwd += words[0];
    for (int i = 1; i < words.size(); i++) {
        pwd += special_chars[rnd_gen() % special_chars.size()];
        pwd += words[i];
    }
}

//  соеденияем слова в фразу с каким-то разделителем (cклеивание, -, _, спец симмволы !@#$%^&*)
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


// Функция для применения leet-speak замен
void leet_speak(std::string &pwd, int prob) {
    std::uniform_int_distribution<int> prob_dist(0, 99);

    for (char &c : pwd) {
        auto it = leet_map.find(c);
        if (it != leet_map.end()) {
            if (prob_dist(rnd_gen) < prob) {
                const std::vector<char>& vars = it->second;
                c = vars[rnd_gen() % vars.size()];
            }
        }
    }
}


// генерация паролья
std::string generate_password(int prob) {
    std::string pwd = join(pick_phrase());
    leet_speak(pwd, prob);
    return pwd;
}