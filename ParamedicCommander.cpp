
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "ParamedicCommander.hpp"
using namespace std;


Soldier* ParamedicCommander::find_target(std::vector<std::vector<Soldier*>>& board,int x, int y)
{
    return find_close_ally(board,x,y);
}

/*
new implemtation to main_action for commander soldier to trigger all non-commander soldiers from the same type. 
same logic as in foot commander and sniper commander
*/
void ParamedicCommander::main_action(std::vector<std::vector<Soldier*>>& board,int x, int y)
{
    basic_heal(board,x,y);
    
    for(int i = 0; i<board.size(); i++)
    {
      for(int j=0; j<board[i].size(); j++)
      {
          if(board[i][j] != nullptr)
           if(board[i][j]->_team == _team && board[i][j]->_type == "Paramedic")
            board[i][j]->basic_heal(board,x,y);
      }
    }
}

