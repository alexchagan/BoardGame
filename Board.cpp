#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"
using namespace std;
using namespace WarGame;

 Soldier*& Board::operator[](std::pair<int,int> location)
 {
    board[location.first][location.second]->_x = location.first;
    board[location.first][location.second]->_y = location.second;
    return board[location.first][location.second];
 }
 
 Soldier* Board::operator[](std::pair<int,int> location) const
 {
     return board[location.first][location.second];
 }
 
 void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
 {
     Soldier* s = board[source.first][source.second];
     
     if(s==nullptr)
      throw std::invalid_argument("no soldier in this location");
      
     if(s->_team != player_number)
      throw std::invalid_argument("soldier belongs to other player");
      
     int x,y; // new coordinates
     
     switch(direction)
     {
       case Up:
       {
        if(board[source.first+1][source.second] != nullptr)
         throw std::invalid_argument("there's already a soldier in the wanted position");
         
        board[source.first+1][source.second] = s;
        board[source.first][source.second] = nullptr;
        x = source.first+1;
        y = source.second;
        break;
       }
       
        case Down:
       {
        if(board[source.first-1][source.second] != nullptr)
         throw std::invalid_argument("there's already a soldier in the wanted position");
         
        board[source.first-1][source.second] = s;
        board[source.first][source.second] = nullptr;
        x = source.first-1;
        y = source.second;
        break;
       }
       
        case Right:
       {
        if(board[source.first][source.second+1] != nullptr)
         throw std::invalid_argument("there's already a soldier in the wanted position");
         
        board[source.first][source.second+1] = s;
        board[source.first][source.second] = nullptr;
        x = source.first;
        y = source.second+1;
        break;
       }
       
       case Left:
       {
        if(board[source.first][source.second-1] != nullptr)
         throw std::invalid_argument("there's already a soldier in the wanted position");
         
        board[source.first][source.second-1] = s;
        board[source.first][source.second] = nullptr;
        x = source.first;
        y = source.second-1;
        break;
       }
       
       default:
       {
         throw std::invalid_argument("no such direction");
       }
     }
     board[x][y]->main_action(board,x,y);
 }
 
 bool Board::has_soldiers(uint player_number) const
 {
   for(int i=0; i<board.size(); i++)
   {
    for(int j=0; j<board[i].size(); j++)
    {
     if(board[i][j]!=nullptr && board[i][j]->_team == player_number)
      return true;
    }
   }
  return false;
 }