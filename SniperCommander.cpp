#ifndef WARGAME_A_SNIPERCOMMANDER_CPP
#define WARGAME_A_SNIPERCOMMANDER_CPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "SniperCommander.hpp"
using namespace std;

Soldier* SniperCommander::find_target(std::vector<std::vector<Soldier*>> board,int x, int y)
{
    return find_healthy_target(board,x,y);
}

void SniperCommander::main_action(std::vector<std::vector<Soldier*>> board,int x, int y)
{
    basic_action(board,x,y);
    
    for(int i = 0; i<board.size(); i++)
    {
      for(int j=0; j<board[i].size(); j++)
      {
          if(board[i][j]->_team == _team && board[i][j]->_type == "Sniper")
           board[i][j]->basic_action(board,x,y);
      }
    }
}

#endif