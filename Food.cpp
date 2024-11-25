#include "Food.h"
#include <time.h>


Food::Food(GameMechs* gamemechs)
{
    mainmech = gamemechs;
    foodPos = new objPos();
}

Food::~Food()
{
    delete foodPos;
    delete mainmech;
}

Food::Food(const Food &a)
{
    // deep copy
}
Food& Food::operator=(const Food &a)
{

}

void Food::generateFood(objPos blockOff)
{
    srand((time(NULL)));
    int maxExcluded = 1;

    int xTaken[maxExcluded];
    int yTaken[maxExcluded];
    char symbolTaken[maxExcluded];
    symbolTaken[0] = blockOff.getSymbol();
    xTaken[0] = blockOff.pos->x;
    yTaken[0] = blockOff.pos->y;
 
    /*int j;
    for(j=0;j<listSize;j++)
    {
        xTaken[j] = list[j].x;
        yTaken[j] = list[j].y;
    }
    j++;*/
    int width = mainmech->getBoardSizeX();
    int height = mainmech->getBoardSizeY();

    int i;
    //randomly generate coords
    int randx = rand() % width;
    int randy = rand() % height;
        
    int available = 0;
    while(available == 0)
    {
        available = 1;
        randx = (rand() % width-2) + 1; // can never be 0 or width-1
        randy = (rand() % height-2)+1; // can never be 0 or height-1
        int xi;
        for(xi=0;xi<maxExcluded;xi++)
        {
            if(xTaken[xi] == randx)
            {
                    available = 0;
            }
        }
        int yi;
        for(yi=0;yi<maxExcluded;yi++)
        {
            if(xTaken[yi] == randy)
            {
                available = 0;
            }
        }
    }
        //randomly select chars from the goalstring

    int freeChar = 0;
    int randchar = 0;
    while(freeChar == 0)
    {
        freeChar = 1;
        randchar = (rand() % 93)+33; // 126-33 is the range, add 33 to it for ascii alphanumeric
        int g;
        for(g=0;g<1;g++)
        {
            if(symbolTaken[g] == randchar)
            {
                freeChar = 0;
            }
        }
    }
    // set objpos to randomly generated x,y,char
    foodPos->setObjPos(randx,randy,randchar);
}

void Food::getFoodPos(objPos const)
{

}