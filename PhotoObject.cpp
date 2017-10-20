#include "PhotoObject.h"

/**
 * @brief Getter method for the latitude variable
 * @return latitude of the photo
 */
float PhotoObject::getLatitude() const
{
    return latitude;
}
/**
 * @brief Setter method for the latitude variable
 * @param value integer latitude of the photo
 */
void PhotoObject::setLatitude(float value)
{
    latitude = value;
}
/**
 * @brief Getter method for the longitude variable
 * @return longitude of the photo
 */
float PhotoObject::getLongitude() const
{
    return longitude;
}
/**
 * @brief Setter method for the longitude variable
 * @param value integer longitude of the photo
 */
void PhotoObject::setLongitude(float value)
{
    longitude = value;
}

/**
 * @brief PhotoObject::reproduce
 * Reproduce the photo viq the mpv command
 */
void PhotoObject::reproduce()
{
    string command = "mpv "+getPath()+" &";
    system(command.c_str());
}
