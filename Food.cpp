#include "Food.h"
#include <time.h>


Food::Food(GameMechs* gamemechs)
{
    mainmech = gamemechs;
    foodBucket = new objPosArrayList();
}

Food::~Food()
{
    delete foodBucket;
}

Food::Food(const Food &a)
{
    mainmech = a.mainmech;
    foodBucket = a.foodBucket;
}
Food& Food::operator=(const Food &a)
{
    if(this != &a)
    {
        mainmech = a.mainmech;
        foodBucket = a.foodBucket;
    }
    return *this;
}

void Food::generateFood(objPosArrayList *blockOff)
{
    srand((time(NULL)));
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    int width = mainmech->getBoardSizeX();
    int height = mainmech->getBoardSizeY();
    int maxExcluded = blockOff->getSize();

    for (i = foodBucket->getSize(); i > 0; i--)
    {
        objPos clearpos =  foodBucket->getTailElement();
        if(mainmech->getBoard(clearpos.pos->x,clearpos.pos->y) == 'o' || mainmech->getBoard(clearpos.pos->x,clearpos.pos->y) == 'O')
        {
            mainmech->setBoard(clearpos.pos->x,clearpos.pos->y,' ');
        }
        foodBucket->removeTail();
    }
    
    while (j < 3)
    {
        //randomly generate coords
        int randX = (rand() % (width-2)) + 1;
        int randY = (rand() % (height-2))+ 1;

        // Checks for snake body overlap
        bool posfilled = false;
        while(posfilled == false)
        {
            randX = (rand() % (width-2)) + 1;
            randY = (rand() % (height-2))+ 1;
            posfilled = true;
            for (i = 0; i < maxExcluded; i++)
            {
                objPos snakeBody = blockOff->getElement(i);
                if (snakeBody.pos->x == randX && snakeBody.pos->y == randY)
                {
                    posfilled = false;
                    break;
                }
            }
                    // Checks for other food overlap
            for (i = 0; i < j; i++)
            {
                objPos foodPos = foodBucket->getElement(i);
                if (foodPos.pos->x == randX && foodPos.pos->y == randY)
                {
                    posfilled = false;
                    break;
                }         
            }
        }

        if (j < 2)
        {
            foodBucket->insertTail(objPos(randX,randY,'o'));
        }
        else
        {
            foodBucket->insertTail(objPos(randX,randY,'O'));  
        }
        j++;
    }
    for(int i = 0; i < foodBucket->getSize(); i++)
    {
        objPos curfood = foodBucket->getElement(i);
        mainmech->setBoard(curfood.pos->x,curfood.pos->y,curfood.getSymbol());
    }
    
}

objPosArrayList* Food::getFoodPos() const
{ 
    return foodBucket;
}