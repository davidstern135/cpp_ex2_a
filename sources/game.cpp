#include "player.hpp"
#include "game.hpp"
#include <string>

using namespace std;
namespace ariel {
    Game::Game(Player& p1, Player& p2):pl1(p1),pl2(p2) {
        this->pl1 = p1;
        this->pl2 = p2;
    }
    void Game::playTurn(){}
    void Game::printLastTurn(){}
    void Game::playAll(){}
    void Game::printWiner(){}
    void Game::printLog(){}
    void Game::printStats(){}
}

