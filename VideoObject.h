#ifndef VIDEOOBJECT_H
#define VIDEOOBJECT_H

#include "MultimediaObject.h"

/**
 * @brief The VideoObject class
 * Handler for Video objects.
 * Contains methods for information about the video, as well as method for its reproduction.
 */

class VideoObject : public MultimediaObject
{
    friend class Database;
private:
    int duration = 0; /**< Duration of the movie */
protected:
    /**
     * @brief VideoObject constructor
     */
    VideoObject() {}
    /**
     * @brief VideoObject constructor
     * @param _name string containing the name of the video
     * @param _path string containing the full path of the video
     */
    VideoObject(string _name, string _path) : MultimediaObject(_name, _path){}
    /**
     * @brief VideoObject constructor
     * @param _name string containing the name of the video
     * @param _path string containing the full path of the video
     * @param _duration integer value for the duration of the video
     */
    VideoObject(string _name, string _path, int _duration) : MultimediaObject(_name, _path), duration(_duration){}
public:
    ~VideoObject() {}
    int getDuration() const;
    void setDuration(int value);
    virtual void reproduce();
};

#endif // VIDEOOBJECT_H
