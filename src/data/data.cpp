#include "data.h"
#include <random>
#include <chrono>

std::mt19937_64 rnd_gen{
    std::random_device{}() ^
    std::mt19937_64::result_type(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()
    )
};

const std::vector<std::string> adjectives{
    "bright", "dark", "fast", "slow", "happy", "sad", "big", "small",
    "red", "blue", "green", "strong", "weak", "quiet", "loud", "old", "new",
    "clever", "brave", "funny", "wise", "mysterious", "gentle", "wild", "smooth"
};

const std::vector<std::string> nouns{
    "sun", "moon", "star", "cat", "dog", "bird", "tree", "flower",
    "river", "ocean", "mountain", "cloud", "book", "music", "house", "city",
    "computer", "phone", "car", "road", "mouse", "keyboard", "table", "chair",
    "journey", "secret", "dream", "whisper", "shadow", "thunder", "diamond"
};

const std::vector<std::string> verbs{
    "run", "jump", "sleep", "read", "write", "draw", "play",
    "love", "think", "watch", "listen", "speak", "laugh", "cry",
    "discover", "imagine", "explore", "create", "travel", "remember", "fly"
};

const std::string special_chars{"!@#$%^&*|/\\"};

const std::map<char, std::vector<char>> leet_map = {
    {'a', {'@', '4'}},
    {'e', {'3'}},
    {'i', {'1', '!'}},
    {'o', {'0'}},
    {'s', {'$', '5'}},
    {'t', {'7', '+'}},
    {'l', {'1'}}
};