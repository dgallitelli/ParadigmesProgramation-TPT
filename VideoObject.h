#ifndef VIDEOOBJECT_H
#define VIDEOOBJECT_H

#include "MultimediaObject.h"

class VideoObject : public MultimediaObject
{
private:
    int duration = 0;
public:
    VideoObject() {}
    VideoObject(string _objectName, string _fileName, int _duration) : MultimediaObject(_objectName, _fileName), duration(_duration){}
    ~VideoObject() {}

    int getDuration() const;
    void setDuration(int value);
    virtual void reproduce();
};

#endif // VIDEOOBJECT_H
