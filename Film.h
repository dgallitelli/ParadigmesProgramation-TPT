#ifndef FILM_H
#define FILM_H

#include "VideoObject.h"
#include <vector>

class Film : public VideoObject
{
private:
    int elemNum = 0;
    int *chListDur;
public:
    Film(int _elemNum, int *_chListDur, string _objectName, string _fileName, int _duration);
    ~Film();

    int getElemNum() const;
    void setElemNum(int value);
    int *getChListDur() const;
    void setChListDur(int *value);

    void printChInfo();
};

#endif // FILM_H
