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

/**
 * @brief The Database class
 * Class for handling objects for the application.
 * It's the only one which can create new objects, so it has to be instanciated first,
 * and then create objects by using the methods here defined.
 * File information are stored in two maps.
 */
class Database
{
private:
    map<string, shared_ptr<MultimediaObject>> mObjMap;  /**< The multimedia object map - store here the files */
    map<string, shared_ptr<Group>> groupMap;            /**< The group map - add here groups already created  */
public:
    Database(){}
    ~Database();
    Database(const Database&_db);
    shared_ptr<PhotoObject> newPhoto(string _name, string _path, float _lat, float _longit);
    shared_ptr<VideoObject> newVideo(string _name, string _path, int _duration);
    shared_ptr<Film> newFilm(string _name, string _path, int _duration, int _nChs, int *_chList);
    shared_ptr<Group> newGroup(string _name);

    void reproduceFromName(string name);
    void printObjectFromName(string name, ostream &outStream);
    void printGroupFromName(string name, ostream &outStream);
};

#endif // DATABASE_H
