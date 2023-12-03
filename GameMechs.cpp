#include "GameMechs.h"
#include "MacUILib.h"
#include <ctime>


GameMechs* gameMechs;


GameMechs::GameMechs()
{

    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 20; // default board size
    boardSizeY = 10;

    foodPos.setObjPos(-1, -1, 'o'); // initialzie foodPos outside of the gameboard

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX; // default board size
    boardSizeY = boardY;
    foodPos.setObjPos(-1, -1, 'o'); // initialzie foodPos outside of the gameboard
}

GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar()) 
    {
        input = MacUILib_getChar();

        if(input == 27) // esacpe
            exitFlag = true;
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

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::incrementScore() 
{
    score++;
}

int GameMechs::getScore()
{
    return score;
}
 
void GameMechs::generateFood(objPos blockOff)
{
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate random positions until a valid food position is found
    objPos foodPos;
    do {
        // Generate random x and y coordinates for the food
        foodPos.x = std::rand() % getBoardSizeX(); 
        foodPos.y = std::rand() % getBoardSizeY(); 
    } while (foodPos.isPosEqual(&blockOff));
   
}
void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
} 

