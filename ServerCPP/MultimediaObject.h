#ifndef MULTIMEDIAOBJECT_H
#define MULTIMEDIAOBJECT_H

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Base abstract class for any multimedia object.
 *
 * Used by the other classes deeper down in the hierarchy.
 * Provides all the methods common to the object derived from this class.
 */
class MultimediaObject
{
    friend class Database;
private:
    string name; /**< name of the multimedia object */
    string path; /**< full path of the multimedia object */
protected:
    /**
     * @brief MultimediaObject
     * Creates a multimedia object without setting the initial values of the private variables.
     */
    MultimediaObject() {}
    /**
     * @brief MultimediaObject
     * Creates a multimedia object provided name and path
     * @param _name name of the multimedia object
     * @param _path full path of the multimedia object
     */
    MultimediaObject(string _name, string _path) : name(_name), path(_path){}
public:
    /**
     * @brief ~MultimediaObject
     * Destructor of the class
     */
    virtual ~MultimediaObject() {}

    // GETTERS AND SETTERS
    virtual string getName() const;
    virtual void setName(const string &value);
    virtual string getPath() const;
    virtual void setPath(const string &value);

    virtual void print(ostream& outStream);
    /**
     * @brief Abstract method for multimedia reproduction
     * Method for reproducing the file. Has to be redefined in every lower level class
     * in order to specify the correct system command to reproduce the appropriate file.
     */
    virtual void reproduce() = 0;
};

#endif // MULTIMEDIAOBJECT_H
