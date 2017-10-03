#include "Film.h"

Film::Film(int _elemNum, int *_chListDur, string _objectName, string _fileName, int _duration) :
    VideoObject(_objectName, _fileName, _duration), elemNum(_elemNum) {
    chListDur = new int[elemNum];
    *chListDur = *_chListDur;
}

int *Film::getChListDur() const
{
    return chListDur;
}

void Film::setChListDur(int *value)
{
    chListDur = value;
}

void Film::printChInfo()
{
    std::cout << "------------------" << endl;
    std::cout << "Printing chapter information about Film " << getFileName() << ": "<< endl;
    for (int i = 0; i < elemNum; i++){
        std::cout << "Ch" << i+1 <<": "<< chListDur[i]<<endl;
    }
    std::cout << "------------------" << endl;
}

Film::~Film()
{
    delete [] chListDur;
}

int Film::getElemNum() const
{
    return elemNum;
}

void Film::setElemNum(int value)
{
    elemNum = value;
}
