#pragma once

#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <map>

extern std::mt19937_64 rnd_gen;
extern std::vector<std::string> adjectives;
extern std::vector<std::string> nouns;
extern std::vector<std::string> verbs;
extern std::string special_chars;
extern std::map<char, std::vector<char>> leet_map;

// функции для выбора какого-то слова
std::string pick_adj();
std::string pick_noun();
std::string pick_verb();

// выбираем вид осмысленной фразы "adj_noun_verb", "noun_verb_adj", "adj_noun", "noun_verb"
std::vector<std::string> pick_phrase();

// Вспомогательные функции для объединения слов
int sum_sizes(std::vector<std::string> &words);
void heading(std::string &word);
void pascal_case(std::vector<std::string> &words, std::string &pwd);
void camel_case(std::vector<std::string> &words, std::string &pwd);
void snake_case(std::vector<std::string> &words, std::string &pwd);
void kebab_case(std::vector<std::string> &words, std::string &pwd);
void special_case(std::vector<std::string> &words, std::string &pwd);

// соеденияем слова в фразу с каким-то разделителем (cклеивание, -, _, спец симмволы !@#$%^&*)
std::string join(std::vector<std::string> &words);

// Функция для применения leet-speak замен
void leet_speak(std::string &pwd);

// генерация паролья
std::string generate_password(int prob = 20);