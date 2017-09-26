#include "PhotoObject.h"

float PhotoObject::getLatitude() const
{
    return latitude;
}

void PhotoObject::setLatitude(float value)
{
    latitude = value;
}

float PhotoObject::getLongitude() const
{
    return longitude;
}

void PhotoObject::setLongitude(float value)
{
    longitude = value;
}

void PhotoObject::reproduce()
{
    string command = "mpv "+getFileName()+" &";
    system(command.c_str());
}
