#ifndef WARGAME_A_PARAMEDIC_CPP
#define WARGAME_A_PARAMEDIC_CPP


#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <math.h>
#include "Paramedic.hpp"
using namespace std;



Soldier* Paramedic::find_target(std::vector<std::vector<Soldier*>> board,int x, int y)
{
    return find_close_ally(board,x,y);
}

void Paramedic::basic_action(std::vector<std::vector<Soldier*>> board,int x, int y)
{
    Soldier* s = find_target(board,x,y);
    s->_health = s->_ohp;
}


#endif