#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* foodPtr)
{ 
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                    mainGameMechsRef->getBoardSizeY()/2,
                    '*');

    // more actions to be included
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    FoodPtr = foodPtr;
    
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
    delete FoodPtr;
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{ 
    // PPA3 input processing logic   

    char input = mainGameMechsRef->getInput();

    switch(input)
    {
        case 'w':
            if(myDir != UP && myDir != DOWN)
                myDir = UP;
            break;

        case 'a':
            if(myDir != LEFT && myDir != RIGHT)
                myDir = LEFT;
            break;

        case 's':
            if(myDir != UP && myDir != DOWN)
                myDir = DOWN;
            break;

        case 'd':
            if(myDir != LEFT && myDir != RIGHT)
                myDir = RIGHT;
            break;

        default:
            break;
    } 
        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    
    objPos currHead; // holding the position of the current head
    playerPosList->getHeadElement(currHead);
    
    // Update player position based on current direction
    
    switch(myDir){

        case LEFT:
            currHead.x--;
            break;

        case RIGHT:
            currHead.x++;
            break;

        case DOWN:
            currHead.y++;
            break;

        case UP:
            currHead.y--;
            break;

        default:
            break;
        }
        if (currHead.x < 1){
        currHead.x = mainGameMechsRef->getBoardSizeX() - 2;
        }
        else if (currHead.x >= mainGameMechsRef->getBoardSizeX()-1){
            currHead.x = 1;
        }

        if (currHead.y >= mainGameMechsRef->getBoardSizeY()-1) {
            currHead.y = 1;
        }
        else if (currHead.y < 1){
            currHead.y = mainGameMechsRef->getBoardSizeY() - 2;
        
        }

    
    objPos FoodPos;
    FoodPtr->getFoodPos(FoodPos);
    if (currHead.isPosEqual(&FoodPos)) {
        playerPosList->insertHead(currHead);
        FoodPtr->generateFood(mainGameMechsRef, playerPosList);
    }
    else{
    playerPosList->insertHead(currHead);
    playerPosList-> removeTail();
    }

    for(int i = 1; i < playerPosList->getSize(); i++){
        objPos tempPlayer;
        playerPosList->getElement(tempPlayer, i);
        if(currHead.isPosEqual(&tempPlayer)){
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
        }
    }

}

    
    

