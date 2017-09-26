#include "Film.h"


int *Film::getChListDur() const
{
    return chListDur;
}

void Film::setChListDur(int *value)
{
    chListDur = value;
}

string *Film::getChListName() const
{
    return chListName;
}

void Film::setChListName(string *value)
{
    chListName = value;
}

void Film::printChInfo()
{
    std::cout << "------------------" << endl;
    std::cout << "Printing chapter information about Film " << getFileName() << ": "<< endl;
    for (int i = 0; i < elemNum; i++){
        std::cout << "Ch" << i+1 <<": "<<chListName[i] << " - " <<chListDur[i]<<endl;
    }
    std::cout << "------------------" << endl;
}

Film::~Film()
{
}

int Film::getElemNum() const
{
    return elemNum;
}

void Film::setElemNum(int value)
{
    elemNum = value;
}
