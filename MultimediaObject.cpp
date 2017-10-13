#include "MultimediaObject.h"

string MultimediaObject::getName() const
{
    return name;
}

void MultimediaObject::setName(const string &_objectName)
{
    name = _objectName;
}

string MultimediaObject::getPath() const
{
    return path;
}

void MultimediaObject::setPath(const string &_fileName)
{
    path = _fileName;
}

void MultimediaObject::print(ostream &outStream)
{
    if (outStream.rdbuf() == cout.rdbuf()){
        // output on stdout
        cout << "Objectname: " << name << " | Filename: "  << path << endl;
    } else {
        // output on a different output stream
        outStream << "Objectname: " << name << " | Filename: "  << path;
    }
}
