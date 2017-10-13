#include "VideoObject.h"

int VideoObject::getDuration() const
{
    return duration;
}

void VideoObject::setDuration(int value)
{
    duration = value;
}

void VideoObject::reproduce()
{
    string command = "mpv "+getPath()+" &";
    system(command.c_str());
}
