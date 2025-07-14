#include <string>
#include <vector>
#include <cctype>

// сумма слов
int sum_sizes(const std::vector<std::string>& words);

// делаем с заглавной функции
void heading(std::string& word);

// соеденияем слова в фразу с каким-то разделителем (cклеивание, -, _, спец симмволы !@#$%^&*)
std::string join(std::vector<std::string> words);

// способы соединения слов
void pascal_case(std::vector<std::string>& words, std::string& pwd);
void camel_case(std::vector<std::string>& words, std::string& pwd);
void snake_case(std::vector<std::string>& words, std::string& pwd);
void kebab_case(std::vector<std::string>& words, std::string& pwd);
void special_case(std::vector<std::string>& words, std::string& pwd);