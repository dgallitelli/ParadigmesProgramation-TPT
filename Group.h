#ifndef GROUP_H
#define GROUP_H

#include <list>
#include "MultimediaObject.h"

class Group : public std::list<shared_ptr<MultimediaObject>>
{
    string* groupName;
public:
    Group(string _groupName);
    string *getGroupName() const;
    void setGroupName(string *value);
    void reproduce();
    ~Group();
};

#endif // GROUP_H
