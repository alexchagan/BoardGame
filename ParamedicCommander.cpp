#ifndef WARGAME_A_PARAMEDICCOMMANDER_CPP
#define WARGAME_A_PARAMEDICCOMMANDER_CPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "ParamedicCommander.hpp"
using namespace std;

void ParamedicCommander::basic_action(std::vector<std::vector<Soldier*>> board,int x, int y)
{
    Soldier* s = find_target(board,x,y);
    s->_health = s->_ohp;
}

Soldier* ParamedicCommander::find_target(std::vector<std::vector<Soldier*>> board,int x, int y)
{
    return find_close_ally(board,x,y);
}

void ParamedicCommander::main_action(std::vector<std::vector<Soldier*>> board,int x, int y)
{
    basic_action(board,x,y);
    
    for(int i = 0; i<board.size(); i++)
    {
      for(int j=0; j<board[i].size(); j++)
      {
          if(board[i][j]->_team == _team && board[i][j]->_type == "Paramedic")
           board[i][j]->basic_action(board,x,y);
      }
    }
}

#endif