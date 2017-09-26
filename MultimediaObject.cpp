#include "MultimediaObject.h"

string MultimediaObject::getObjectName() const
{
    return objectName;
}

void MultimediaObject::setObjectName(const string &_objectName)
{
    objectName = _objectName;
}

string MultimediaObject::getFileName() const
{
    return fileName;
}

void MultimediaObject::setFileName(const string &_fileName)
{
    fileName = _fileName;
}

void MultimediaObject::writeOnStream(ostream &outStream)
{
    if (outStream.rdbuf() == cout.rdbuf()){
        // output on stdout
        cout << "Objectname: " << objectName << " | Filename: "  << fileName << endl;
    } else {
        // output on a different output stream
        outStream << "Objectname: " << objectName << " | Filename: "  << fileName;
    }
}
