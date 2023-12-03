#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    List = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] List;
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity)
    //if list size == array capacity don't insert
        return;
    
    for(int i = listSize - 1; i > 0; i--)
    {
        List[i].setObjPos(List[i-1]); // this is will shuffle all the elemets towards the tail
    }

    List[0].setObjPos(thisPos);

    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        //if list size == array capacity don't insert
        return;
    }
    List[listSize].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::removeHead()
{
    if (listSize > 0) {
        // Move all elements one position to the left
        for (int i = 0; i < listSize - 1; i++) {
            List[i].setObjPos(List[i+1]);
        }
        // Decrease the size
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if (listSize > 0) {
        List[listSize - 1].setObjPos(0, 0, 0);
        listSize--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(List[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(List[listSize - 1]); 
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if(index>=0 && index<listSize && listSize>0){
        returnPos.setObjPos(List[index]);
    }
}