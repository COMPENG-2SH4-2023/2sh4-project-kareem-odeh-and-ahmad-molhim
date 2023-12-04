#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    exitFlag = false;
    score = 0;
    input = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    exitFlag = false; 
    score = 0;
    input = 0;
    boardSizeX = boardX; 
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{

}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        char input = MacUILib_getChar();
        setInput(input);

        if(input == ' ') 
        {
            setExitTrue();
        }

    }

    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseflag;
}

void GameMechs::setLoseFlag()
{
    loseflag = true;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getScore()
{
    return score;
}