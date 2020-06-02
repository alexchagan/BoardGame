#ifndef WARGAME_A_PARAMEDIC_HPP
#define WARGAME_A_PARAMEDIC_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;
#include "Soldier.hpp"


class Paramedic : public Soldier
{
 
  public:
  Paramedic(int team): Soldier(team,100,0,"Paramedic",100){};
  Soldier* find_target (std::vector<std::vector<Soldier*>> board,int x, int y);
  void basic_action(std::vector<std::vector<Soldier*>> board,int x, int y);
};

#endif