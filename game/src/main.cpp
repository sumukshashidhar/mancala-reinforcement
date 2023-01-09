//
// Created by Sumuk Shashidhar on 1/9/23.
//

#include "board.h"
#include <cstdlib>

void play_infinite() {
    Board b;
    int rounds = 0;
    bool test;
    std::vector<short> options;
    short choice;
    while (true) {
        // Providing a seed value
        srand((unsigned) time(nullptr));
        options = b.get_moves(0);
        choice = options[rand() % options.size()];
        test = b.play(0, choice);
        if (!test) {
            break;
        }
        rounds++;
        srand((unsigned) time(nullptr));
        options = b.get_moves(1);
        choice = options[rand() % options.size()];
        test = b.play(1, choice);
        if (!test) {
            break;
        }
        rounds++;
        // print scores now
        std::cout << "Scores: " << b.get_score(0) << " " << b.get_score(1) << std::endl;
    }
    // print scores now
    std::cout << "Scores: " << b.get_score(0) << " " << b.get_score(1) << std::endl;
    // print num rounds played
    std::cout << "Rounds: " << rounds << std::endl;
}

int main() {
    play_infinite();
}
