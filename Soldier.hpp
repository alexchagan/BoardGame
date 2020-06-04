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
    
    /*
    finds the closest enemy target based on pythagoras function
    used by foot soldier
    */
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
            double distance = sqrt(pow(x-i , 2) + pow(y-j , 2)); // pythagoras
            if(distance < min_distance || min_distance==0)
            {
                // update the new minimum distance, the pointer and the coordinates of the new candidate
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
         //we define the coordinates of a Soldier only when we interact with it.
      s->_x = target_x;
      s->_y = target_y;
     }
     return s;
    };
    
    
    /*
     finds the healthiest enemy target.  same logic as in find_closest_target
     used by sniper
    */
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
    
    /*
    finds a close ally that doesn't have full health
    used by the paramedic
    */
     Soldier* find_close_ally(std::vector<std::vector<Soldier*>>& board,int x, int y)
    {         
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
    
    /*
    the basic attack function. sets enemy target to null if it's health goes below 0.
    used by foot soldier and sniper.
    */
    void basic_attack(std::vector<std::vector<Soldier*>>& board,int x, int y)
    {
    Soldier* s = find_target(board,x,y);
    if(s!=nullptr)
    {
     s->_health = s->_health - _impact; //general formula for offensive soldiers
     if(s->_health < 1)
      {
       delete s;
        board[s->_x][s->_y]=nullptr;
       s = nullptr;
      }
     }
    };
    
    /*
    the basic heal function. sets ally health to full.
    used by paramedic.
    */
    void basic_heal(std::vector<std::vector<Soldier*>>& board,int x, int y)
   {
    Soldier* s = find_target(board,x,y);
    if(s != nullptr)
     s->_health = s->_ohp;
   }
    
    /*
    wrapper virtual function . implemented based on soldier type. default set to basic_attack since it's the most common
    */
    virtual void main_action(std::vector<std::vector<Soldier*>>& board,int x, int y)
    {
    basic_attack(board,x,y);
    };
    
    /*
    pure virtual wrapper function . must implement based on soldier type 
    */
    virtual Soldier* find_target(std::vector<std::vector<Soldier*>>& board,int x, int y) =0;
    
    virtual ~Soldier(){};
};

#endif
