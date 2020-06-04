

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;
#include "Soldier.hpp"


class Sniper : public Soldier
{
 
  public:
  Sniper(int team): Soldier(team,100,50,"Sniper",100){};
  Soldier* find_target (std::vector<std::vector<Soldier*>>& board,int x, int y);
};

