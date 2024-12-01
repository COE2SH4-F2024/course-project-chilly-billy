#ifndef FOOD_H
#define FOOD_H

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
        void generateFood(objPosArrayList *blockOff);
        objPosArrayList* getFoodPos() const; 
    private:
        objPosArrayList* foodBucket;
        GameMechs* mainmech;

};

#endif