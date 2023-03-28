#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("setting up the game and giving each player a half a deck (26 cards each and 0 cards won at this point)"){

    Player p1("David");
    Player p2("Stern");
    Game game(p1,p2);
    CHECK(p1.stacksize()==26);
    CHECK(p2.stacksize()==26);
    CHECK(p1.cardesTaken()==0);
    CHECK(p2.cardesTaken()==0);
}
TEST_CASE("playing one round"){
    Player p1("David");
    Player p2("Stern");
    Game game(p1,p2);
    game.playTurn();
    CHECK(p1.stacksize()==p1.stacksize());//they have the same amount.
    CHECK(p1.stacksize()<26);//used there cards
    CHECK((p1.cardesTaken()>0||p2.cardesTaken()>0));
    //at least one of the playes won some cards(if its a tie for all 26 cards so they will have the same amount.
    CHECK(p1.stacksize()+p2.stacksize()+p1.cardesTaken()+p2.cardesTaken()==52);
    //making sure that both players didn't win the same cards.
}
TEST_CASE("playing the full game"){
    Player p1("David");
    Player p2("Stern");
    Game game(p1,p2);
    game.playAll();
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
    CHECK(p1.cardesTaken()+p2.cardesTaken()==52);
}
TEST_CASE("errors- player plays himself"){
    Player p1("David");
    CHECK_THROWS(Game(p1,p1));
}

TEST_CASE("eroors- befor strting the game"){
    Player p1("David");
    Player p2("Stern");
    Game game(p1,p2);
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printWiner());
}
TEST_CASE("eroors- after ending the game") {
    Player p1("David");
    Player p2("Stern");
    Game game(p1, p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
}

TEST_CASE("no errors"){
    Player p1("David");
    Player p2("Stern");
    Player p3("Alice");
    Player p4("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLog());
    game.playAll();
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    Game game2(p3,p4);
    game2.playTurn();
    CHECK_NOTHROW(game2.printLastTurn());
    CHECK_NOTHROW(game2.printStats());
    CHECK_NOTHROW(game2.printLog());
}





