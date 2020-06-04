
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <math.h>
#include "Sniper.hpp"
using namespace std;



Soldier* Sniper::find_target(std::vector<std::vector<Soldier*>>& board,int x, int y)
{
    return find_healthy_target(board,x,y);
}


