#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

Player* player1;
GameMechs* gamemechs;
Food* apple;

int main(void)
{

    Initialize();

    while(gamemechs->getExitFlagStatus() == false && gamemechs->getLoseFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    gamemechs = new GameMechs();
    player1 = new Player(gamemechs);
    apple = new Food(gamemechs);
    //apple->generateFood(player1->getPlayerPos());
    //gamemechs->setBoard(apple->getFoodPos().pos->x,apple->getFoodPos().pos->y,apple->getFoodPos().getSymbol());
}

void GetInput(void)
{
    if(MacUILib_hasChar())
    {
        gamemechs->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    player1->updatePlayerDir();
    player1->movePlayer();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    for(int i = 0; i < gamemechs->getBoardSizeY(); i++)
    {
        printf("%s\n", gamemechs->getBoardLine(i));
    }
    //printf("food char pos %d %d %c\n", apple->getFoodPos().pos->x,apple->getFoodPos().pos->y,apple->getFoodPos().getSymbol());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delays
}

void CleanUp(void)
{
    MacUILib_clearScreen();
    MacUILib_uninit();

}