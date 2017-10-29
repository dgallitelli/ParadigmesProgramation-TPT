#include "Database.h"

/**
 * @brief Database::~Database
 * Destructor for the class Database.
 * Has to clear the maps in order to free the pointers.
 */
Database::~Database()
{
    mObjMap.clear();
    groupMap.clear();
}

/**
 * @brief Database::Database
 * Database copy constructor, copies the pointers from an already existing database
 * @param _db - the source database object
 */
Database::Database(const Database &_db)
{
    mObjMap = _db.mObjMap;
    groupMap = _db.groupMap;
}

/**
 * @brief Database::newPhoto
 * Method to create a new PhotoObject object in the Database
 * @param _name - name of the object
 * @param _path - path to the photo file
 * @param _lat  - photo latitude
 * @param _longit - photo longitude
 * @return A shared pointer to the PhotoObject object
 */
shared_ptr<PhotoObject> Database::newPhoto(string _name, string _path, float _lat, float _longit)
{
    shared_ptr<PhotoObject> p(new PhotoObject(_name, _path, _lat, _longit));
    mObjMap[_name] = p;
    return p;
}

/**
 * @brief Database::newVideo
 * Method to create a new VideoObject object in the Database
 * @param _name - name of the object
 * @param _path - path to the video file
 * @param _duration - duration of the video file
 * @return A shared pointer to the VideoObject object
 */
shared_ptr<VideoObject> Database::newVideo(string _name, string _path, int _duration)
{
    shared_ptr<VideoObject> v(new VideoObject(_name, _path, _duration));
    mObjMap[_name] = v;
    return v;
}

/**
 * @brief Database::newFilm
 * Method to create a new Film object in the Database
 * @param _name - name of the object
 * @param _path - path to the movie file
 * @param _duration - duration of the movie
 * @param _nChs - number of chapters in the movie
 * @param _chList - list of integers with chapters duration
 * @return A shared pointer to the Film object
 */
shared_ptr<Film> Database::newFilm(string _name, string _path, int _duration, int _nChs, int *_chList)
{
   shared_ptr<Film> f(new Film(_name, _path, _duration, _nChs, _chList));
   mObjMap[_name] = f;
   return f;
}

/**
 * @brief Database::newGroup
 * Method to create a new Group object in the Database
 * @param _name - name of the group
 * @return A shared pointer to the Group object
 */
shared_ptr<Group> Database::newGroup(string _name)
{
    shared_ptr<Group> g(new Group(_name));
    groupMap[_name] = g;
    return g;
}

/**
 * @brief Database::reproduceFromName
 * Method to reproduce a file from the Database, given its name from the map
 * @param name - name of the multimedia object to reproduce
 */
void Database::reproduceFromName(string name)
{
    auto it=mObjMap.find(name);
    if (it == mObjMap.end()){
        cout << "No multimedia object found with that name." << endl;
    } else {
        (it->second)->reproduce();
    }
}

/**
 * @brief Database::reproduceFromName
 * Method to print information about a file from the Database, given its name from the map
 * @param name - name of the multimedia object to print information about
 */
void Database::printObjectFromName(string name, ostream& outStream)
{
    auto it=mObjMap.find(name);
    if (it == mObjMap.end()){
        cout << "No multimedia object found with that name." << endl;
    } else {
        (it->second)->print(outStream);
    }
}

/**
 * @brief Database::printGroupFromName
 * Method to print information about a group of multimedia object from the database,
 * given its name from the map
 * @param name - name of the group object in the map
 */
void Database::printGroupFromName(string name)
{
    auto it=groupMap.find(name);
    if (it == groupMap.end()){
        cout << "No multimedia object found with that name." << endl;
    } else {
        (it->second)->print();
    }
}
