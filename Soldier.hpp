#ifndef WARGAME_SOLDIER_HPP
#define WARGAME_SOLDIER_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <math.h>
using namespace std;


class Soldier
{
    public:
    int _x,_y; // coordinates on board
    int _team, _health, _impact, _ohp; // ohp = original health points
    string _type;
   
   //Constructor
    Soldier(int team,int health, int impact, string type, int ohp): _team(team), _health(health), _impact(impact), _type(type), _ohp(ohp){};
    
    
    Soldier* find_closest_target(std::vector<std::vector<Soldier*>>& board,int x, int y)
    {
    double min_distance = 0;
    Soldier* s = nullptr;
    int target_x,target_y;
    
    for(int i = 0; i<board.size(); i++)
    {
     
         
      for(int j=0; j<board[i].size(); j++)
      {
          
        if(board[i][j] != nullptr && board[i][j]->_team != _team)
        {
            double distance = sqrt(pow(x-i , 2) + pow(y-j , 2));
            if(distance<min_distance || min_distance==0)
            {
             min_distance = distance;
             s = board[i][j];
             target_x = i;
             target_y = j;
            }
             
        }
      }
    }
     if(s!=nullptr)
     {
      s->_x = target_x;
      s->_y = target_y;
     }
     return s;
    };
    
    
    Soldier* find_healthy_target(std::vector<std::vector<Soldier*>>& board,int x, int y)
    {
        int max_health = 0;
        Soldier* s = nullptr;
        int target_x,target_y;
    
    for(int i = 0; i<board.size(); i++)
    {
     
      for(int j=0; j<board[i].size(); j++)
      {
          if(board[i][j] != nullptr && board[i][j]->_team != _team)
        {
            int health = board[i][j]->_health;
            if(health > max_health)
            {
                max_health = health;
                s = board[i][j];
                target_x = i;
                target_y = j;
            }
        }
    
      }
      
    }
    if(s!=nullptr)
     {
      s->_x = target_x;
      s->_y = target_y;
     }
     return s;  
        
    };
    
     Soldier* find_close_ally(std::vector<std::vector<Soldier*>>& board,int x, int y)
    {
         //Soldier* s = nullptr;
         
         for(int i=0; i<board.size(); i++)
          {
     
           for(int j=0; j<board[i].size(); j++)
           {
               if(board[i][j] != nullptr && board[i][j]->_team == _team && board[i][j]->_health != board[i][j]->_ohp)
               {
                   if(abs(x-i)==1 && abs(y-j)==1)
                   {
                    board[i][j]->_x = i;
                    board[i][j]->_y = j;
                    return board[i][j];
                   }
               }
           }
           
          }
          return nullptr;
    };
    
    void basic_action(std::vector<std::vector<Soldier*>>& board,int x, int y)
    {
    Soldier* s = find_target(board,x,y);
    s->_health = s->_health - _impact; //general formula for offensive soldiers
    if(s->_health < 1)
     {
      delete s;
      board[s->_x][s->_y]=nullptr;
      s = nullptr;
      if(s==nullptr)
      cout<< "hi" << endl;
     }
    };
    
    void basic_heal(std::vector<std::vector<Soldier*>>& board,int x, int y)
{
    Soldier* s = find_target(board,x,y);
    if(s != nullptr)
     s->_health = s->_ohp;
}
    
    virtual void main_action(std::vector<std::vector<Soldier*>>& board,int x, int y)
    {
    basic_action(board,x,y);
    };
    
    
    virtual Soldier* find_target(std::vector<std::vector<Soldier*>>& board,int x, int y) =0;
    
    virtual ~Soldier(){};
};

#endif
