#include <iostream>
#include "MacUILib.h"
#include "objPos.h" // fundamental building block for project
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;

objPos myPos;

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
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

    myGM = new GameMechs(30, 15); // make the board size 30x15
    myPlayer = new Player(myGM);

    objPos tempPos;
    myGM->generateFood(tempPos);

}

void GetInput(void)
{
    myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput(); // so to not repeatedly process the input
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    bool drawn = false; // boolean flag

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos tempFoodPos;
    myGM->getFoodPos(tempFoodPos);


    for(int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for(int j = 0; i < myGM->getBoardSizeX(); j++)
        {
            drawn = false;
            
            // iterate through every element in the list
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if(tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn =  true;
                    break;
                }
            }
            
            if(drawn) continue;
            // if player body was already drawn, dont draw anything below

            // draw border
            if(i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || myGM->getBoardSizeX() - 1)
            {
                MacUILib_printf("%c", '#');
            }
            
            else if(j == tempFoodPos.x && i == tempFoodPos.y)
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }

        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d\n", myGM->getScore());

    MacUILib_printf("Food Pos: <%d, %d>\n", tempFoodPos.x, tempFoodPos.y); 

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1 second delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    // remove heap instances
    delete myGM;
    delete myPlayer;
}
