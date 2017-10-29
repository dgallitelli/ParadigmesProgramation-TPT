#include "Group.h"

// Group::Group(string _groupName) : std::list<MultimediaObject*>(), groupName(_groupName){}
/**
 * @brief Group::Group
 * Constructor of the Group object, given the object name
 * @param _groupName - the name of the group object
 */
Group::Group(string _groupName) :list<shared_ptr<MultimediaObject>>(), groupName(_groupName){}

/**
 * @brief Group::getGroupName
 * Getter method for the group name
 * @return A string containing the group name
 */
string Group::getGroupName() const
{
    return groupName;
}

/**
 * @brief Group::setGroupName
 * Setter method for the group name
 * @param value - A string containing the new group name
 */
void Group::setGroupName(const string &value)
{
    groupName = value;
}

/**
 * @brief Group::print
 * Method for printing information about the group
 * Iterates over the elements of the group and calls their print methods, printing on stdout.
 */
void Group::print()
{
    std::cout << "#### PRINTING CONTENT OF GROUP " << groupName << "####" << endl;
    for (std::list<shared_ptr<MultimediaObject>>::const_iterator i = this->begin(); i != this->end(); ++i)
        (*i)->print(std::cout);
}
