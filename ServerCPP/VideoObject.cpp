#include "VideoObject.h"

/**
 * @brief Getter method for the duration variable
 * @return An integer with the duration of the video
 */
int VideoObject::getDuration() const
{
    return duration;
}

/**
 * @brief Setter method for the duration variable
 * @param value integer for the duration of the movie
 */
void VideoObject::setDuration(int value)
{
    duration = value;
}

/**
 * @brief Method to reproduce the movie
 * It uses the mpv command.
 */
void VideoObject::reproduce()
{
    string command = "mpv "+getPath()+" &";
    system(command.c_str());
}
