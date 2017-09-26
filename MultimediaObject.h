#ifndef MULTIMEDIAOBJECT_H
#define MULTIMEDIAOBJECT_H

#include <string>
#include <iostream>

using namespace std;

class MultimediaObject
{
private:
    string objectName;
    string fileName;
public:
    MultimediaObject() {}
    MultimediaObject(string _objectName, string _fileName) : objectName(_objectName), fileName(_fileName){}
    virtual ~MultimediaObject() {}

    virtual string getObjectName() const;
    virtual void setObjectName(const string &value);
    virtual string getFileName() const;
    virtual void setFileName(const string &value);

    virtual void writeOnStream(ostream& outStream);
    virtual void reproduce() = 0;
};

#endif // MULTIMEDIAOBJECT_H
