#include <iostream>
#include "objPos.h"
#include "GameMechs.h"

class Food
{
    

    public:
        Food(GameMechs* gamemechs);
        ~Food();
        Food(const Food &a);
        Food& operator=(const Food &a);
        void generateFood(objPos blockOff);
        objPos getFoodPos() const; 
    private:
        objPos foodPos;
        GameMechs* mainmech;

};