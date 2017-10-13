#ifndef MULTIMEDIAOBJECT_H
#define MULTIMEDIAOBJECT_H

#include <string>
#include <iostream>

using namespace std;

class MultimediaObject
{
private:
    string name;
    string path;
public:
    MultimediaObject() {}
    MultimediaObject(string _name, string _path) : name(_name), path(_path){}
    virtual ~MultimediaObject() {}

    virtual string getName() const;
    virtual void setName(const string &value);
    virtual string getPath() const;
    virtual void setPath(const string &value);

    virtual void print(ostream& outStream);
    virtual void reproduce() = 0;
};

#endif // MULTIMEDIAOBJECT_H
