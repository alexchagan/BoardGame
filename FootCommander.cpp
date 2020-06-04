

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "FootCommander.hpp"

using namespace std;

Soldier* FootCommander::find_target(std::vector<std::vector<Soldier*>>& board,int x, int y)
{
    return find_closest_target(board,x,y);
}

void FootCommander::main_action(std::vector<std::vector<Soldier*>>& board,int x, int y)
{
    basic_action(board,x,y);
    
    for(int i = 0; i<board.size(); i++)
    {
      for(int j=0; j<board[i].size(); j++)
      {
          if(board[i][j] != nullptr)
           if(board[i][j]->_team == _team && board[i][j]->_type == "Foot Soldier")
            board[i][j]->main_action(board,x,y);
          
      }
    }
}




int main()
{
     std::vector<std::vector<Soldier*>>  board(3, std::vector<Soldier*>(3, nullptr));
     FootCommander* s = new FootCommander(1);
    FootCommander* s1 = new FootCommander(2);
    FootCommander* s2 = new FootCommander(2);
    board[0][2] = s;
     board[1][1] = s1;
      board[2][0] = s2;
      //cout << s->_type << endl;
      
      
      for(int i=0 ; i<10; i++)
      {
      s->main_action(board,0,2);
      cout<<"s "<< s->_health <<endl;
      cout<<"s1 "<< s1->_health <<endl;
      cout<<"s2 "<< s2->_health <<endl;
      cout<<"------------"<<endl;
      

      }
     //board[1][1] = nullptr;
      s->main_action(board,0,2);
      cout<<"s "<< s->_health <<endl;
      cout<<"s2 "<< s2->_health <<endl;
      cout<<"------------"<<endl;
    
    //==========================================
    
    // FootSoldier* s = new FootSoldier(1);
    // FootSoldier* s1 = new FootSoldier(2);
    // FootSoldier* s2 = new FootSoldier(2);
    // board[0][2] = s;
    //  board[1][1] = s1;
    //   board[2][0] = s2;
    //   s->_x = 0;
    //   s->_y = 2;
    //   s1->_x = 1;
    //   s1->_y = 1;
    //   s2->_x = 2;
    //   s2->_y = 0;
      
      
    //   for(int i=0 ; i<10; i++)
    //   {
    //   s->main_action(board,0,2);
    //   cout<<"s "<< s->_health <<endl;
    //   cout<<"s1 "<< s1->_health <<endl;
    //   cout<<"s2 "<< s2->_health <<endl;
    //   cout<<"------------"<<endl;
      

    //   }
    //  //board[1][1] = nullptr;
    //   s->main_action(board,0,2);
    //   cout<<"s "<< s->_health <<endl;
    //   cout<<"s2 "<< s2->_health <<endl;
    //   cout<<"------------"<<endl;
      
      return 0;
      }