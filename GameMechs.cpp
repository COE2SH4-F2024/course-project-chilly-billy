#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
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
        for(int j = 0; j < boardSizeX-1; j++) // leave null char termination string
        {
            if(j == 0 || j == boardSizeX-2 || i == 0 || i == boardSizeY-1)
            {
                board[i][j] = 35;
            }
            else
            {
                board[i][j] = 32;
            }
        }
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

}

bool GameMechs::getLoseFlagStatus() const
{

}
    

char GameMechs::getInput() const
{

}

int GameMechs::getScore() const
{

}

void GameMechs::incrementScore()
{
    
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

}

void GameMechs::setLoseFlag()
{
    
}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}

// More methods should be added here