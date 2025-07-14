#include "formatter.h"
#include "data.h"

void leet_speak(std::string& pwd, int prob) {
    std::uniform_int_distribution<int> prob_dist(0, 99);

    for (char& c : pwd) {
        auto it = leet_map.find(c);
        if (it != leet_map.end()) {
            if (prob_dist(rnd_gen) < prob) {
                const std::vector<char>& vars = it->second;
                if (!vars.empty()) {
                    c = vars[rnd_gen() % vars.size()];
                }
            }
        }
    }
}