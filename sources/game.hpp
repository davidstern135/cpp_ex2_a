#pragma once
#include "player.hpp"
#include <string>

using namespace std;
namespace ariel{
    class Game{
        Player pl1;
        Player pl2;
        public:
        Game(Player& p1, Player& p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}
