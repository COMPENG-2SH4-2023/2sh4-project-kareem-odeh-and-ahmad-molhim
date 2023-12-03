#include "Player.h"




Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2,
                       mainGameMechsRef->getBoardSizeY() / 2,
                        '@');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;

}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos array list
    return playerPosList;

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
    
    switch(myDir)
    {
        case UP:
            currHead.y--;
            if(currHead.y <= 0) // wraparoud logic
                currHead.y = mainGameMechsRef->getBoardSizeY() - 2;
            break;  

        case DOWN:
            currHead.y++;
            if(currHead.y >= mainGameMechsRef->getBoardSizeY()) // wraparound logic
                currHead.y = 1;
            break;

        case LEFT:
            currHead.x--;
            if(currHead.x <= 0) // wraparound logic
                currHead.x = mainGameMechsRef->getBoardSizeX() - 2;
            break;

        case RIGHT:
            currHead.x++;
            if(currHead.x >= mainGameMechsRef->getBoardSizeX()) // wraparound logic
                currHead.x = 1;
            break;
        
        case STOP:
        default:
            break;

    }


    // new current head should be inserted to the head of the list.
    playerPosList->insertHead(currHead);

    // then, remove tail
    playerPosList->removeTail();


}


    