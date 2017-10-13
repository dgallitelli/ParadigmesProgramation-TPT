#ifndef PHOTOOBJECT_H
#define PHOTOOBJECT_H

#include "MultimediaObject.h"

class PhotoObject : public MultimediaObject
{
private:
    float latitude = 0;
    float longitude = 0;
public:
    PhotoObject() {}
    PhotoObject(string _name, string _pathname) : MultimediaObject(_name, _pathname){}
    PhotoObject(string _name, string _path, float lat, float longit) : MultimediaObject(_name, _path), latitude(lat), longitude(longit) {}
    ~PhotoObject() {}

    float getLatitude() const;
    void setLatitude(float value);
    float getLongitude() const;
    void setLongitude(float value);
    virtual void reproduce();
};

#endif // PHOTOOBJECT_H
