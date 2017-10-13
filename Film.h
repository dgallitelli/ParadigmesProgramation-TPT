#ifndef FILM_H
#define FILM_H

#include "VideoObject.h"
#include <vector>

class Film : public VideoObject
{
private:
    int nChs = 0;
    int *chList;
public:
    Film(string _name, string _path) : VideoObject(_name, _path){}
    Film(string _name, string _path, int _duration, int _nChs, int *_chList);
    ~Film();

    void printChInfo();

    int getNChs() const;
    void setNChs(int value);
    int *getChList() const;
    void setChList(int *value);
};

#endif // FILM_H
