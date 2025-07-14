#include <string>
#include <vector>
#include <map>
#include <random>
#include <chrono>

// гпсч
extern std::mt19937_64 rnd_gen;

// списки слов
extern const std::vector<std::string> adjectives;
extern const std::vector<std::string> nouns;
extern const std::vector<std::string> verbs;

// спец символы
extern const std::string special_chars;

// таблица замен
extern const std::map<char, std::vector<char>> leet_map;