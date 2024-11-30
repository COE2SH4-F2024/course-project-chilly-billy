#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
    board = new char*[boardSizeY];

    for(int i = 0; i < boardSizeY; i++)
    {
        board[i] = new char[boardSizeX+1];
        for(int j = 0; j < boardSizeX; j++) // leave null char termination string
        {
            if(j == 0 || j == boardSizeX-1 || i == 0 || i == boardSizeY-1)
            {
                board[i][j] = '#';
            }
            else
            {
                board[i][j] = ' ';
            }
        }
        board[i][boardSizeX] = 0;
    }
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    board = new char*[boardSizeY];

    for(int i = 0; i < boardSizeY; i++)
    {
        board[i] = new char[boardSizeX+1];
        for(int j = 0; j < boardSizeX; j++) // leave null char termination string
        {
            if(j == 0 || j == boardSizeX-1 || i == 0 || i == boardSizeY-1)
            {
                board[i][j] = '#';
            }
            else
            {
                board[i][j] = ' ';
            }
        }
        board[i][boardSizeX] = 0;
    }
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    for(int i = 0; i < boardSizeX; i++)
    {
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
}

GameMechs & GameMechs::operator=(const GameMechs &a)
{
    // deep copy
}
GameMechs::GameMechs(const GameMechs &a)
{

}

void GameMechs::clearBoard()
{
    for(int i = 1; i < boardSizeY-1; i++)
    {
        for(int j = 1; j < boardSizeX-2;j++)
        {
            board[i][j] = ' ';
        }
    }
}

void GameMechs::setBoard(int x, int y, char z)
{
    board[y][x] = z;
}

char GameMechs::getBoard(int x, int y)
{
    return board[y][x];
}

char* GameMechs::getBoardLine(int y)
{
    return board[y];
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score+=1;
}

void GameMechs::boostScore()
{
    score+=10;
}
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here