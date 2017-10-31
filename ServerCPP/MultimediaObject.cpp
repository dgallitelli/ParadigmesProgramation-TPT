#include "MultimediaObject.h"

/**
 * @brief MultimediaObject::getName
 * Getter method for the name variable
 * @return the name of the object
 */
string MultimediaObject::getName() const
{
    return name;
}

/**
 * @brief MultimediaObject::setName
 * Setter method for the name of the object
 * @param _objectName - a string containing the new name of the object
 */
void MultimediaObject::setName(const string &_objectName)
{
    name = _objectName;
}

/**
 * @brief MultimediaObject::getPath
 * Getter method for the path of the file
 * @return the path of the file
 */
string MultimediaObject::getPath() const
{
    return path;
}

/**
 * @brief MultimediaObject::setPath
 * Setter method for the path of the file
 * @param _fileName - a string containing the full path to the file
 */
void MultimediaObject::setPath(const string &_fileName)
{
    path = _fileName;
}

/**
 * @brief MultimediaObject::print - Function to print on an outstream the values of the object
 * Attaches on an output stream the values of the private variable name and path.
 * @param outStream has to point to a valid output stream, eg cout or a stringstream
 */
void MultimediaObject::print(ostream &outStream)
{
    if (outStream.rdbuf() == cout.rdbuf()){
        // output on stdout
        cout << "Objectname: " << name << " | Filename: "  << path << endl;
    } else {
        // output on a different output stream
        outStream << "Objectname: " << name << " | Filename: "  << path << endl;
    }
}
