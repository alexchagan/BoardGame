#ifndef WARGAME_A_SNIPERCOMMANDER_HPP
#define WARGAME_A_SNIPERCOMMANDER_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Soldier.hpp"
using namespace std;

class SniperCommander : public Soldier
{
  public:
   SniperCommander(int team): Soldier(team,120,100,"Sniper Commander",120){};
   Soldier* find_target (std::vector<std::vector<Soldier*>> board,int x, int y);
   void main_action(std::vector<std::vector<Soldier*>> board,int x, int y);
   
};

#endif