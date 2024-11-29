#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP; // default

    aList = new objPos[arrayCapacity];
    listSize = 0;
    //aList

}



objPosArrayList::~objPosArrayList()
{
    delete aList; // CHECK FOR LEAKS
}

// add 2 more for rule of 4

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(arrayCapacity > listSize)
    {
        objPos* newlist = new objPos[arrayCapacity];
        newlist[0] = thisPos;
        for(int i=0; i < listSize; i++)
        {
            newlist[i+1] = aList[i];
        }
        delete[] aList;
        aList = newlist;
        listSize++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(arrayCapacity > listSize)
    {
        aList[listSize] = thisPos; // listsize-1 is last element in the list, + 1 is appending
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    if(listSize > 0)
    {
        objPos* newlist = new objPos[arrayCapacity];
        for(int i=0; i < listSize-1; i++)
        {
            newlist[i] = aList[i+1];
        }
        delete[] aList;
        aList = newlist;
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if(listSize > 0)
    {
        objPos* newlist = new objPos[arrayCapacity];
        for(int i=0; i < listSize-1; i++)
        {
            newlist[i] = aList[i];
        }
        delete[] aList;
        aList = newlist;
        listSize--;
    }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0].getObjPos();
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1].getObjPos();
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index].getObjPos();
}