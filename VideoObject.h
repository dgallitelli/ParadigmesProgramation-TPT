#ifndef VIDEOOBJECT_H
#define VIDEOOBJECT_H

#include "MultimediaObject.h"

class VideoObject : public MultimediaObject
{
private:
    int duration = 0;
public:
    VideoObject() {}
    VideoObject(string _name, string _path) : MultimediaObject(_name, _path){}
    VideoObject(string _name, string _path, int _duration) : MultimediaObject(_name, _path), duration(_duration){}
    ~VideoObject() {}

    int getDuration() const;
    void setDuration(int value);
    virtual void reproduce();
};

#endif // VIDEOOBJECT_H
