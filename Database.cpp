#include "Database.h"

Database::Database()
{
}

Database::~Database()
{
    mObjMap.clear();
    groupMap.clear();
}

shared_ptr<PhotoObject> Database::newPhoto(string _name, string _path, float _lat, float _longit)
{
    shared_ptr<PhotoObject> p(new PhotoObject(_name, _path, _lat, _longit));
    mObjMap[_name] = p;
    return p;
}

shared_ptr<VideoObject> Database::newVideo(string _name, string _path, int _duration)
{
    shared_ptr<VideoObject> v(new VideoObject(_name, _path, _duration));
    mObjMap[_name] = v;
    return v;
}

shared_ptr<Film> Database::newFilm(string _name, string _path, int _duration, int _nChs, int *_chList)
{
   shared_ptr<Film> f(new Film(_name, _path, _duration, _nChs, _chList));
   mObjMap[_name] = f;
   return f;
}

shared_ptr<Group> Database::newGroup(string _name)
{
    shared_ptr<Group> g(new Group(_name));
    groupMap[_name] = g;
    return g;
}

void Database::reproduceFromName(string name)
{
    auto it=mObjMap.find(name);
    if (it == mObjMap.end()){
        cout << "No multimedia object found with that name." << endl;
    } else {
        (it->second)->reproduce();
    }
}

void Database::printObjectFromName(string name)
{
    auto it=mObjMap.find(name);
    if (it == mObjMap.end()){
        cout << "No multimedia object found with that name." << endl;
    } else {
        (it->second)->print(std::cout);
    }
}

void Database::printGroupFromName(string name)
{
    auto it=groupMap.find(name);
    if (it == groupMap.end()){
        cout << "No multimedia object found with that name." << endl;
    } else {
        (it->second)->print();
    }
}
