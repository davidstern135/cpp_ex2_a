#include "player.hpp"


namespace ariel {
//    Player::Player(ariel::Player p1) {
//        this=p1.name;
//    }
    Player::Player(std::string name) {
            this->name = name;
    }


    int Player::stacksize() {
        return 1;
    }

    int Player::cardesTaken() {
        return 1;
    }
}