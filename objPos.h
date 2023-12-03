#ifndef OBJPOS_H
#define OBJPOS_H

class objPos
{
    public:
        int x;
        int y;
        char symbol;

        objPos(); // default constructor
        objPos(objPos &o); // copy constructor
        objPos(int xPos, int yPos, char sym); // specialized constructor

        // setter method
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        // getter method
        void getObjPos(objPos &returnPos); // pass by reference
        char getSymbol();

        // pass by pointer... 
        bool isPosEqual(const objPos* refPos);
        char getSymbolIfPosEqual(const objPos* refPos);
};

#endif