#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"

using namespace std;
using namespace WarGame;

TEST_CASE("2 v 2 Foot Soldiers")
{
    Board b(3,3);
    CHECK(b.has_soldiers(1) == false); //1
    CHECK(b.has_soldiers(2) == false); //2
    
    
    b[{0,1}] = new FootSoldier(1);
    
    CHECK(b.has_soldiers(1) == true); //3
    CHECK(b.has_soldiers(2) == false); //4
    
    b[{2,0}] = new FootSoldier(1);
    
    CHECK(b.has_soldiers(2) == true); //7
    CHECK(b.has_soldiers(1) == true); //8
    
    b[{0,0}] = new FootSoldier(1);
    b[{2,2}] = new FootSoldier(2);
    
    
    for(int i=0 ; i<5 ; i++)
    {
    CHECK_NOTHROW(b.move(2, {2,2}, Board::MoveDIR::Down)); //52
    CHECK_NOTHROW(b.move(2, {1,2}, Board::MoveDIR::Up)); //53
    }
    
    CHECK_THROWS(b.move(1, {0,1}, Board::MoveDIR::Up)); //9 - should be dead 
    CHECK(b.has_soldiers(1) == true); //10 - player 1 has another soldier
    
    for(int i=0 ; i<5 ; i++)
    {
    CHECK_NOTHROW(b.move(1, {0,0}, Board::MoveDIR::Up)); //54
    CHECK_NOTHROW(b.move(1, {1,0}, Board::MoveDIR::Down)); //55
    }
    
    CHECK_THROWS(b.move(1, {0,0}, Board::MoveDIR::Down)); //11 - should be dead 
    CHECK(b.has_soldiers(2) == true); //12 - player 2 has another soldier
    
     for(int i=0 ; i<5 ; i++)
    {
    CHECK_NOTHROW(b.move(1, {0,0}, Board::MoveDIR::Up)); //56
    CHECK_NOTHROW(b.move(1, {0,0}, Board::MoveDIR::Down)); //57
    CHECK_NOTHROW(b.move(2, {2,2}, Board::MoveDIR::Down)); //58
    CHECK_NOTHROW(b.move(2, {2,2}, Board::MoveDIR::Up)); //59
    }
    
    CHECK_THROWS(b.move(2, {2,2}, Board::MoveDIR::Down)); //13 - should be dead
    CHECK(b.has_soldiers(2) == false); //14 - all soldiers of player 2 are dead
    CHECK(b.has_soldiers(1) == true); //15 - player 1 soldier survived
    
}

TEST_CASE("Illegal Moves")
{
    Board b(3,3);
    
    
    b[{0,1}] = new FootSoldier(1);
    b[{0,2}] = new FootSoldier(1);
    b[{0,3}] = new FootSoldier(1);
    b[{1,0}] = new FootSoldier(1);
    b[{1,2}] = new FootSoldier(1);
    b[{2,0}] = new FootSoldier(1);
    b[{2,1}] = new FootSoldier(1);
    CHECK(b.has_soldiers(2) == false);
    b[{2,2}] = new FootSoldier(2);
    CHECK(b.has_soldiers(2) == true);
    
    CHECK(b.has_soldiers(1) == true); //99
    CHECK(b.has_soldiers(2) == true); //100
    
    CHECK_THROWS(b.move(1, {0,1}, Board::MoveDIR::Down)); // 16
    CHECK_THROWS(b.move(1, {0,1}, Board::MoveDIR::Left)); // 17
    CHECK_THROWS(b.move(1, {0,1}, Board::MoveDIR::Right)); // 18
    CHECK_THROWS(b.move(2, {0,1}, Board::MoveDIR::Up)); // 19 -wrong team
    
    
    CHECK_THROWS(b.move(1, {0,0}, Board::MoveDIR::Left)); // 20
    CHECK_THROWS(b.move(1, {0,0}, Board::MoveDIR::Right)); // 21
    CHECK_THROWS(b.move(1, {0,0}, Board::MoveDIR::Down)); // 22
    CHECK_THROWS(b.move(1, {0,0}, Board::MoveDIR::Up)); // 23
   
    
    CHECK_THROWS(b.move(1, {0,2}, Board::MoveDIR::Up)); // 24
    CHECK_THROWS(b.move(1, {0,2}, Board::MoveDIR::Left)); // 25
    CHECK_THROWS(b.move(1, {0,2}, Board::MoveDIR::Down)); // 26
    CHECK_THROWS(b.move(1, {0,2}, Board::MoveDIR::Right)); // 27
    
    
    CHECK_THROWS(b.move(1, {1,0}, Board::MoveDIR::Up)); // 28
    CHECK_THROWS(b.move(1, {1,0}, Board::MoveDIR::Left)); // 29
    CHECK_THROWS(b.move(1, {1,0}, Board::MoveDIR::Down)); // 30
    CHECK_THROWS(b.move(2, {1,0}, Board::MoveDIR::Right)); // 31 - wrong team
    
    
    CHECK_THROWS(b.move(1, {1,1}, Board::MoveDIR::Up)); // 32 -empty space
    CHECK_THROWS(b.move(1, {1,1}, Board::MoveDIR::Left)); // 33 -empty space
    CHECK_THROWS(b.move(1, {1,1}, Board::MoveDIR::Down)); // 34 -empty space
    CHECK_THROWS(b.move(1, {1,1}, Board::MoveDIR::Right)); // 35 -empty space
    
    
    CHECK_THROWS(b.move(1, {1,2}, Board::MoveDIR::Up)); // 36
    CHECK_THROWS(b.move(1, {1,2}, Board::MoveDIR::Right)); // 37
    CHECK_THROWS(b.move(1, {1,2}, Board::MoveDIR::Down)); //  38
    CHECK_THROWS(b.move(2, {1,2}, Board::MoveDIR::Left)); // 39 - wrong team
    
    
    CHECK_THROWS(b.move(1, {2,0}, Board::MoveDIR::Up)); // 40
    CHECK_THROWS(b.move(1, {2,0}, Board::MoveDIR::Left)); // 41
    CHECK_THROWS(b.move(1, {2,0}, Board::MoveDIR::Down)); // 42
    CHECK_THROWS(b.move(1, {2,0}, Board::MoveDIR::Right)); // 43
    
    
    CHECK_THROWS(b.move(1, {2,1}, Board::MoveDIR::Up)); // 44
    CHECK_THROWS(b.move(1, {2,1}, Board::MoveDIR::Right)); // 45
    CHECK_THROWS(b.move(1, {2,1}, Board::MoveDIR::Left)); //  46
    CHECK_THROWS(b.move(2, {2,1}, Board::MoveDIR::Down)); // 47 - wrong team
    
    
    CHECK_THROWS(b.move(2, {2,2}, Board::MoveDIR::Up)); // 48
    CHECK_THROWS(b.move(2, {2,2}, Board::MoveDIR::Left)); // 49
    CHECK_THROWS(b.move(2, {2,2}, Board::MoveDIR::Down)); // 50
    CHECK_THROWS(b.move(2, {2,2}, Board::MoveDIR::Right)); // 51
    
}

TEST_CASE("3 v 3 With Commanders")
{
    Board b(3,6);
    
    CHECK(b.has_soldiers(1) == false); //87
    CHECK(b.has_soldiers(2) == false); //88
    
    b[{1,0}] = new FootCommander(1);
    b[{0,5}] = new FootCommander(2);
     
    CHECK(b.has_soldiers(1) == true); //75
    CHECK(b.has_soldiers(2) == true); //76
     
    b[{0,0}] = new FootSoldier(1);
    b[{0,1}] = new FootSoldier(1);
    b[{2,0}] = new FootSoldier(2);
    b[{1,5}] = new FootSoldier(2);
    
    CHECK_NOTHROW(b.move(1, {1,0}, Board::MoveDIR::Right)); //68
    CHECK_NOTHROW(b.move(2, {2,0}, Board::MoveDIR::Right)); //69
    CHECK_NOTHROW(b.move(1, {1,1}, Board::MoveDIR::Left)); //70
    CHECK_NOTHROW(b.move(2, {2,1}, Board::MoveDIR::Left)); //71
    CHECK_NOTHROW(b.move(1, {1,0}, Board::MoveDIR::Right)); //72
    CHECK_THROWS(b.move(2, {2,0}, Board::MoveDIR::Right)); //73 - should be dead
    CHECK_NOTHROW(b.move(1, {1,1}, Board::MoveDIR::Left)); //74
    
    CHECK(b.has_soldiers(1) == true); //77
    CHECK(b.has_soldiers(2) == true); //78
    
    CHECK_NOTHROW(b.move(2, {0,5}, Board::MoveDIR::Left)); //79
    CHECK_NOTHROW(b.move(2, {0,4}, Board::MoveDIR::Right)); //80
    CHECK_NOTHROW(b.move(2, {0,5}, Board::MoveDIR::Left)); //81
    CHECK_NOTHROW(b.move(1, {0,1}, Board::MoveDIR::Right)); //82 - should still be alive
    CHECK_NOTHROW(b.move(2, {1,5}, Board::MoveDIR::Left)); //83
    CHECK_NOTHROW(b.move(1, {0,2}, Board::MoveDIR::Right)); //84 - should be deade
    
    CHECK_NOTHROW(b.move(1, {1,0}, Board::MoveDIR::Right)); //87
    
    for(int i=0 ; i<2 ; i++)
    {
        CHECK_NOTHROW(b.move(2, {0,4}, Board::MoveDIR::Right)); //88
        CHECK_NOTHROW(b.move(2, {0,5}, Board::MoveDIR::Left)); //89
    }
    CHECK_NOTHROW(b.move(2, {0,4}, Board::MoveDIR::Left)); //90
    CHECK_THROWS(b.move(1, {1,1}, Board::MoveDIR::Left)); //91 - should be dead
    
    CHECK(b.has_soldiers(1) == true); //92
    CHECK(b.has_soldiers(2) == true); //93
    
    for(int i=0; i<5 ; i++)
    {
        CHECK_NOTHROW(b.move(2, {1,4}, Board::MoveDIR::Right)); //94
        CHECK_NOTHROW(b.move(2, {1,5}, Board::MoveDIR::Left)); //95
    }
    CHECK_THROWS(b.move(1, {0,0}, Board::MoveDIR::Left)); //96 - should be dead
    
    CHECK(b.has_soldiers(1) == false); //97
    CHECK(b.has_soldiers(2) == true); //98 - team 2 wins
    
}

TEST_CASE("Snipers Test")
{
    Board b(3,3);
    b[{0,0}] = new FootCommander(1);
    b[{0,2}] = new FootSoldier(1);
    b[{2,0}] = new Sniper(2);
    b[{2,2}] = new SniperCommander(2);
    
    CHECK(b.has_soldiers(1) == true); 
    CHECK(b.has_soldiers(2) == true);
    
    CHECK_NOTHROW(b.move(2, {2,0}, Board::MoveDIR::Down));
    CHECK_NOTHROW(b.move(1, {0,0}, Board::MoveDIR::Right));
    CHECK_NOTHROW(b.move(1, {0,2}, Board::MoveDIR::Up));
    CHECK_NOTHROW(b.move(2, {1,0}, Board::MoveDIR::Right));
    CHECK_THROWS(b.move(1, {0,1}, Board::MoveDIR::Left)); //dead
    CHECK_THROWS(b.move(1, {1,2}, Board::MoveDIR::Down)); //dead
    
    CHECK(b.has_soldiers(1) == false); 
    CHECK(b.has_soldiers(2) == true);
    
}