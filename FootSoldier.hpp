#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;
#include "Soldier.hpp"


class FootSoldier : public Soldier
{
 
  public:
  FootSoldier(int team): Soldier(team,100,10,"Foot Soldier",100){};
  Soldier* find_target (std::vector<std::vector<Soldier*>>& board,int x, int y);
};

