#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    int width = mainGameMechsRef->getBoardSizeX();
    int height = mainGameMechsRef->getBoardSizeY();
    playerPos.setObjPos(width/2,height/2,'*');
    
    

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete[] mainGameMechsRef;
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic   
    char input = mainGameMechsRef->getInput();
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;

            // Add more key processing here
            case 'w':
                if(myDir != DOWN && myDir != UP)
                {
                    myDir = UP;
                    dy = -1;
                    dx = 0;
                }
                break;
            case 'W':
                if(myDir != DOWN && myDir != UP)
                {
                    myDir = UP;
                    dy = -1;
                    dx = 0;
                }
                break;
            case 'a':
                if(myDir != LEFT && myDir != RIGHT)
                {
                    myDir = LEFT;
                    dx = -1;
                    dy = 0;
                }
                break;
            case 'A':
                if(myDir != LEFT && myDir != RIGHT)
                {
                    myDir = LEFT;
                    dx = -1;
                    dy = 0;
                }
                break;
            case 's':
                if(myDir != DOWN && myDir != UP)
                {
                    myDir = DOWN;
                    dy = 1;
                    dx = 0;
                }
                break;
            case 'S':
                if(myDir != DOWN && myDir != UP)
                {
                    myDir = DOWN;
                    dy = 1;
                    dx = 0;
                }
                break;
            case 'd':
                if(myDir != LEFT && myDir != RIGHT)
                {
                    myDir = RIGHT;
                    dx = 1;
                    dy = 0;
                }
                break;
            case 'D':
                if(myDir != LEFT && myDir != RIGHT)
                {
                    myDir = RIGHT;
                    dx = 1;
                    dy = 0;
                }
                break;
        }
    }
    mainGameMechsRef->clearInput();  
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    // clear previous spot
    mainGameMechsRef->setBoard(playerPos.pos->x,playerPos.pos->y,' ');
    
    playerPos.setObjPos(playerPos.getObjPos().pos->x+dx,playerPos.getObjPos().pos->y+dy,playerPos.getSymbol());
    if(playerPos.pos->x == 0)
    {
        playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()-2,playerPos.pos->y,playerPos.getSymbol());
    }
    else if(playerPos.pos->x == mainGameMechsRef->getBoardSizeX()-1)
    {
        playerPos.setObjPos(1,playerPos.pos->y,playerPos.getSymbol());

    }
    else if (playerPos.pos->y == 0)
    {
        playerPos.setObjPos(playerPos.pos->x,mainGameMechsRef->getBoardSizeY()-2,playerPos.getSymbol());
    }
    else if(playerPos.pos->y == mainGameMechsRef->getBoardSizeY()-1)
    {
        playerPos.setObjPos(playerPos.pos->x,1,playerPos.getSymbol());
    }

    mainGameMechsRef->setBoard(playerPos.pos->x,playerPos.pos->y,playerPos.symbol);
}

// More methods to be added