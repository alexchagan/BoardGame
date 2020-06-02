#ifndef WARGAME_A_FOOTCOMMANDER_CPP
#define WARGAME_A_FOOTCOMMANDER_CPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "FootCommander.hpp"
using namespace std;

Soldier* FootCommander::find_target(std::vector<std::vector<Soldier*>> board,int x, int y)
{
    return find_closest_target(board,x,y);
}

void FootCommander::main_action(std::vector<std::vector<Soldier*>> board,int x, int y)
{
    basic_action(board,x,y);
    
    for(int i = 0; i<board.size(); i++)
    {
      for(int j=0; j<board[i].size(); j++)
      {
          if(board[i][j]->_team == _team && board[i][j]->_type == "Foot Soldier")
           board[i][j]->basic_action(board,x,y);
      }
    }
}


// int main()
// {
//     FootCommander* s = new FootCommander(1);
//     return 0;
// }

#endif