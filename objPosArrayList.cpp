#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    list = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] list;
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity){
        //if list size == array capacity don't insert
        return;
    }
    for (int i =listSize; i>0;i--){
        list[i].setObjPos(list[i-1]);
    }
    list[0].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize == arrayCapacity){
        //if list size == array capacity don't insert
        return;
    }
    list[listSize].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::removeHead()
{
    if (listSize > 0) {
        for (int i = 0; i < listSize - 1; i++) {
            list[i].setObjPos(list[i + 1]);
        }
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if (listSize > 0) {
        list[listSize - 1].setObjPos(0, 0, 0);
        listSize--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(list[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(list[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{

    if(index>=0 && index<listSize && listSize>0){
        returnPos.setObjPos(list[index]);
    }
}