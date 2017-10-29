#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <memory>
#include "MultimediaObject.h"

// class Group : public std::list<MultimediaObject*>

class Group : public std::list<shared_ptr<MultimediaObject>>
{
    friend class Database;
private:
    string* groupName;
    Group(string _groupName);
public:
    string *getGroupName() const;
    void setGroupName(string *value);
    void print();
    ~Group();
};

#endif // GROUP_H
