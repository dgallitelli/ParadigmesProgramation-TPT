#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <memory>
#include "MultimediaObject.h"

// class Group : public std::list<MultimediaObject*>
/**
 * @brief The Group class
 * Collects multiple multimedia objects in a named group.
 * Allows for multiple reproduction - information printing.
 * It inherits methods from the std::list library, meaning it shares its methods.
 */
class Group : public std::list<shared_ptr<MultimediaObject>>
{
    friend class Database;
private:
    string groupName;          /**< The name of the group */
    Group(string _groupName);
public:
    void print();
    ~Group(){}
    string getGroupName() const;
    void setGroupName(const string &value);
};

#endif // GROUP_H
