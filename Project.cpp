#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"  
#include "Player.h" 
#include "Food.h" 
#include "objPosArrayList.h"


using namespace std;

#define DELAY_CONST 100000


// Global variables to be removed
GameMechs* GMPtr;
Player* PlayerPtr;
Food* FoodPtr;

// const int width = 30;
// const int height = 15;
// bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{
    Initialize();

    while(!GMPtr->getExitFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}

// Initialize the game
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    GMPtr = new GameMechs(30, 15); // make the size of the board 30x15
    FoodPtr = new Food();

    objPos playerPos;
    PlayerPtr = new Player(GMPtr, FoodPtr);
    FoodPtr->generateFood(GMPtr, PlayerPtr->getPlayerPos());

    //exitflag = false
}

// Get user input
void GetInput(void)
{
    GMPtr->getInput();
}

// Run game logic
void RunLogic(void)
{
    PlayerPtr->updatePlayerDir(); 
    PlayerPtr->movePlayer();
    GMPtr->clearInput();
}

// Draw the game screen
void DrawScreen(void)
{
    MacUILib_clearScreen();   
    bool drawn; 
    objPos map(0, 0, '#');
    objPosArrayList* playerBody = PlayerPtr->getPlayerPos();
    objPos tempBody;
    objPos playerPos;
    objPos FoodPos;

    // Draw borders
    for (int i = 0; i < GMPtr->getBoardSizeY(); i++) {
        for (int j = 0; j < GMPtr->getBoardSizeX(); j++) {
            drawn = false;
            for (int k=0; k< playerBody->getSize(); k++){
                playerBody->getElement(tempBody, k);
                if(tempBody.x == j && tempBody.y == i){
                    map.setObjPos(i, j, tempBody.symbol);
                    drawn = true;
                    break;
                }
            }
            if(!drawn){
                if (i == 0 || i == GMPtr->getBoardSizeY() - 1 || j == 0 || j == GMPtr->getBoardSizeX() - 1) {
                map.setObjPos(i, j, '#');
                }
                else {
                        FoodPtr->getFoodPos(FoodPos);
                        if (i == FoodPos.y && j == FoodPos.x) {
                            map.setObjPos(i, j, 'o');
                        }
                        else {
                            map.setObjPos(i, j, ' ');
                        }
                }
            }
            map.getObjPos(map);
            MacUILib_printf("%c", map.getSymbol());
        }
        MacUILib_printf("\n");
    }
    
    FoodPtr->getFoodPos(FoodPos);

    MacUILib_printf("Food: Symbol = %c, X = %d, Y = %d\n", 
                    FoodPos.symbol, FoodPos.x, FoodPos.y); // shows the food symbol and x,y coordinate
    MacUILib_printf("\nScore: %d", playerBody->getSize() - 1); // shows the score of the player by finding the size of the list - 1

}

// Introduce a delay between game loops
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


// Clean up resources and exit the game
void CleanUp(void)
{
    MacUILib_clearScreen(); 
    MacUILib_uninit();
   
    delete GMPtr;
    delete PlayerPtr;
    delete FoodPtr;

}