#ifndef WARGAME_A_PARAMEDICCOMMANDER_HPP
#define WARGAME_A_PARAMEDICCOMMANDER_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Soldier.hpp"
using namespace std;

class ParamedicCommander : public Soldier
{
  public:
   ParamedicCommander(int team): Soldier(team,200,0,"Paramedic Commander",200){};
   Soldier* find_target (std::vector<std::vector<Soldier*>> board,int x, int y);
   void main_action(std::vector<std::vector<Soldier*>>& board,int x, int y);
   
   
};

#endif