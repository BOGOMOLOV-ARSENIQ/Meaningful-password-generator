#include <string>
#include <vector>

// функции для выбора какого-то слова
std::string pick_adj();
std::string pick_noun();
std::string pick_verb();

// выбираем вид осмысленной фразы "adj_noun_verb", "noun_verb_adj", "adj_noun", "noun_verb"
std::vector<std::string> pick_phrase();