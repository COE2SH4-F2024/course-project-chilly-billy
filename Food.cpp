#include "Food.h"
#include <time.h>


Food::Food(GameMechs* gamemechs)
{
    mainmech = gamemechs;
}

Food::~Food()
{
    delete mainmech;
}

Food::Food(const Food &a)
{
    mainmech = a.mainmech;
    foodPos = a.foodPos;
}
Food& Food::operator=(const Food &a)
{
    if(this != &a)
    {
        mainmech = a.mainmech;
        foodPos = a.foodPos;
    }
}

void Food::generateFood(objPosArrayList *blockOff)
{
    srand((time(NULL)));
    int maxExcluded = blockOff->getSize();

    int xTaken[maxExcluded];
    int yTaken[maxExcluded];
    char symbolTaken[maxExcluded];
    for(int i = 0; i < maxExcluded; i++)
    {
        symbolTaken[i] = blockOff->getElement(i).getSymbol();
        xTaken[i] = blockOff->getElement(i).pos->x;
        yTaken[i] = blockOff->getElement(i).pos->y;
    }

 

    int width = mainmech->getBoardSizeX();
    int height = mainmech->getBoardSizeY();

    int i;
    //randomly generate coords
    int randx = (rand() % (width-2)) + 1;
    int randy = (rand() % (height-2))+ 1;
    int randchar = randchar = (rand() % 93)+33; // 126-33 is the range, add 33 to it for ascii alphanumeric
        
    int available = 0;
    while(available == 0)
    {
        available = 1;
        randx = (rand() % (width-2)) + 1; // can never be 0 or width-1
        randy = (rand() % (height-2))+1; // can never be 0 or height-1
        randchar = (rand() % 93)+33; // 126-33 is the range, add 33 to it for ascii alphanumeric
        int xi;
        for(xi=0;xi<maxExcluded;xi++)
        {
            if(xTaken[xi] == randx || yTaken[xi] == randy || symbolTaken[xi] == randchar)
            {
                available = 0;
            }
        }
    }
        //randomly select chars from the goalstring
    // set objpos to randomly generated x,y,char
    foodPos.setObjPos(randx,randy,randchar);
}

objPos Food::getFoodPos() const
{ 
    return foodPos.getObjPos();
}