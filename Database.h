#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <memory>
#include <list>
#include <iostream>
#include "MultimediaObject.h"
#include "Group.h"
#include "Film.h"
#include "VideoObject.h"
#include "PhotoObject.h"

class Database
{
private:
    map<string, shared_ptr<MultimediaObject>> mObjMap;
    map<string, shared_ptr<Group>> groupMap;
public:
    Database();
    ~Database();
    Database(const Database&_db);
    shared_ptr<PhotoObject> newPhoto(string _name, string _path, float _lat, float _longit);
    shared_ptr<VideoObject> newVideo(string _name, string _path, int _duration);
    shared_ptr<Film> newFilm(string _name, string _path, int _duration, int _nChs, int *_chList);
    shared_ptr<Group> newGroup(string _name);

    void reproduceFromName(string name);
    void printObjectFromName(string name, ostream &outStream);
    void printGroupFromName(string name);
};

#endif // DATABASE_H
