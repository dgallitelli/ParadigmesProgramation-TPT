#ifndef FILM_H
#define FILM_H

#include "VideoObject.h"
#include <vector>

class Film : public VideoObject
{
private:
    int elemNum = 0;
    int *chListDur = new int[10];
    string *chListName = new string[10];
public:
    Film(int _elemNum, int *_chListDur, string *_chListName, string _objectName, string _fileName, int _duration) :
        VideoObject(_objectName, _fileName, _duration), elemNum(_elemNum), chListDur(_chListDur), chListName(_chListName) {}
    ~Film();

    int getElemNum() const;
    void setElemNum(int value);
    int *getChListDur() const;
    void setChListDur(int *value);
    string *getChListName() const;
    void setChListName(string *value);

    void printChInfo();
};

#endif // FILM_H
