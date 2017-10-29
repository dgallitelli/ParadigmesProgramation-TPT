#include "Group.h"

// Group::Group(string _groupName) : std::list<MultimediaObject*>(), groupName(_groupName){}
Group::Group(string _groupName) :list<shared_ptr<MultimediaObject>>(), groupName(_groupName){}

string *Group::getGroupName() const
{
    return groupName;
}

void Group::setGroupName(string *value)
{
    groupName = value;
}

void Group::print()
{
    std::cout << "#### PRINTING CONTENT OF GROUP " << groupName << "####" << endl;
    for (std::list<shared_ptr<MultimediaObject>>::const_iterator i = this->begin(); i != this->end(); ++i)
        (*i)->print(std::cout);
}
