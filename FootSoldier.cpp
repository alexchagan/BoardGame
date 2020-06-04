#ifndef WARGAME_A_FOOTSOLDIER_CPP
#define WARGAME_A_FOOTSOLDIER_CPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <math.h>
#include "FootSoldier.hpp"
using namespace std;



Soldier* FootSoldier::find_target(std::vector<std::vector<Soldier*>>& board,int x, int y)
{
    return find_closest_target(board,x,y);
}


    
int main()
{
    std::vector<std::vector<Soldier*>>  board(3, std::vector<Soldier*>(3, nullptr));
    FootSoldier* s = new FootSoldier(1);
    FootSoldier* s1 = new FootSoldier(2);
    FootSoldier* s2 = new FootSoldier(2);
    // FootSoldier s(1);
    // FootSoldier s1(2);
    // FootSoldier s2(3);
    
    board[0][2] = s;
     board[1][1] = s1;
      board[2][0] = s2;
    //   s->_x = 0;
    //   s->_y = 2;
    //   s1->_x = 1;
    //   s1->_y = 1;
    //   s2->_x = 2;
    //   s2->_y = 0;
      
      for(int i=0 ; i<10; i++)
      {
      s->main_action(board,0,2);
      cout<<"s "<< s->_health <<endl;
      cout<<"s1 "<< s1->_health <<endl;
      cout<<"s2 "<< s2->_health <<endl;
      cout<<"------------"<<endl;
      

      }
    // board[1][1] = nullptr;
   
    
      s->main_action(board,0,2);
      cout<<"s "<< s->_health <<endl;
      //cout<<"s1 "<< s1->_health <<endl;
      cout<<"s2 "<< s2->_health <<endl;
     
      if(s1!=nullptr)
      cout<< "works" << endl;
      cout<<"------------"<<endl;
      
      return 0;
      }
    
      
    
    
    
    
//     //   s->main_action(board,0,2);
    
//     //   cout<<"s "<< s->_health <<endl;
//     //   cout<<"s1 "<< s1->_health <<endl;
//     //   cout<<"s2 "<< s2->_health <<endl;
//     //   cout<<"------------"<<endl;
      
//     //   s->main_action(board,1,1);
    
//     //   cout<<"s "<< s->_health <<endl;
//     //   cout<<"s1 "<< s1->_health <<endl;
//     //   cout<<"s2 "<< s2->_health <<endl;
//     //   cout<<"------------"<<endl;
      
    
//     return 0;
// }

#endif