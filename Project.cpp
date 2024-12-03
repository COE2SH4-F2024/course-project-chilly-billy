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
    apple = new Food(gamemechs);
    player1 = new Player(gamemechs,apple);
    apple->generateFood(player1->getPlayerPos());
    for(int i = 0; i < apple->getFoodPos()->getSize(); i++)
    {
        objPos curfood = apple->getFoodPos()->getElement(i);
        gamemechs->setBoard(curfood.pos->x,curfood.pos->y,curfood.getSymbol());
    }
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
        MacUILib_printf("%s\n", gamemechs->getBoardLine(i));
    }
    MacUILib_printf("Use WASD to move. SPACE to quit.\n");
    MacUILib_printf("Food types: O - +10 score, o - +1 score and +1 length.\n");
    MacUILib_printf("Score: %d\n",gamemechs->getScore());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delays
}

void CleanUp(void)
{
    MacUILib_clearScreen();
    MacUILib_printf("Game Over! Your score was %d!\n",gamemechs->getScore());
    MacUILib_uninit();
    delete apple;
    delete gamemechs;
    delete player1;
}