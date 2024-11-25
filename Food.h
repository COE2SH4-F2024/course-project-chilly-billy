#include <iostream>
#include "objPos.h"
#include "GameMechs.h"

class Food
{
    Food(GameMechs* gamemechs);
    ~Food();
    Food(const Food &a);
    Food& operator=(const Food &a);

    public:
        void generateFood(objPos blockOff);
        void getFoodPos(objPos const); 
    private:
        objPos* foodPos;
        GameMechs* mainmech;

};