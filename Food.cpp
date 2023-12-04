#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"


Food::Food()
{
    foodPos.setObjPos(-1,-1,'o');
}

Food::~Food()
{

}

void Food::generateFood(GameMechs* gameMechs, objPosArrayList* playerPosList)
{
    objPos snakePos;
    srand(static_cast<unsigned int>(time(0)));

    do {
        foodPos.x = rand() % (gameMechs->getBoardSizeX() - 2) + 1;
        foodPos.y = rand() % (gameMechs->getBoardSizeY() - 2) + 1;
        foodPos.symbol = 'o';

        bool onSnake = false;
        for (int i = 0; i < playerPosList->getSize(); i++) {
            playerPosList->getElement(snakePos, i);
            if (snakePos.isPosEqual(&foodPos)) {
                onSnake = true;
                break;
            }
        }

        if (!onSnake) {
            break; // If not on the snake, break out of the loop
        }
    } while (true);
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}