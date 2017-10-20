#ifndef PHOTOOBJECT_H
#define PHOTOOBJECT_H

#include "MultimediaObject.h"

/**
 * @brief The PhotoObject class
 * Handler for Photo objects.
 * Contains methods to set latitude and longitude of the photo, as well as method for its reproduction.
 */

class PhotoObject : public MultimediaObject
{
    friend class Database;
private:
    float longitude = 0;    /**< latitude of the photo */
    float latitude = 0;     /**< longitude of the photo */
    /**
     * @brief PhotoObject constructor
     */
    PhotoObject() {}
    /**
     * @brief PhotoObject constructor
     * @param _name name of the photo object
     * @param _pathname full path to the photo file
     */
    PhotoObject(string _name, string _pathname) : MultimediaObject(_name, _pathname){}
    /**
     * @brief PhotoObject constructor
     * @param _name name of the photo object
     * @param _pathname full path to the photo file
     * @param lat latitude of the photo
     * @param longit longitude of the photo
     */
    PhotoObject(string _name, string _path, float lat, float longit) : MultimediaObject(_name, _path), latitude(lat), longitude(longit) {}

public:
    ~PhotoObject() {}
    float getLatitude() const;
    void setLatitude(float value);
    float getLongitude() const;
    void setLongitude(float value);
    virtual void reproduce();
};

#endif // PHOTOOBJECT_H
