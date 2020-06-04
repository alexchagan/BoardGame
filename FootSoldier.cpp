
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


    
