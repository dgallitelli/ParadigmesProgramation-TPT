#include "Group.h"

Group::Group(string _groupName){
    list<MultimediaObject*>();
    groupName = new string(_groupName);
}

Group::~Group(){
    delete groupName;
}

string *Group::getGroupName() const
{
    return groupName;
}

void Group::setGroupName(string *value)
{
    groupName = value;
}

void Group::reproduce()
{
    std::cout << "#### PRINTING CONTENT OF GROUP " << groupName << "####" << endl;
    for (std::list<MultimediaObject*>::iterator i = this->begin(); i != this->end(); ++i)
        (*i)->reproduce();
}
