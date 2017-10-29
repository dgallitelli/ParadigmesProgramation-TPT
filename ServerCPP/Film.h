#ifndef FILM_H
#define FILM_H

#include "VideoObject.h"
#include <vector>

/**
 * @brief The Film class
 * Class intheriting from VideoObject class
 * Used to define movie information, namely the number of chapters and their duration
 */
class Film : public VideoObject
{
    friend class Database;
private:
    int nChs = 0;   /**< number of chapters in a movie */
    int *chList;    /**< list with duration chapters */
    /**
     * @brief Film constructor
     * Film constructor, given name and path.
     * @param _name - name of the movie
     * @param _path - path to the movie file
     */
    Film(string _name, string _path) : VideoObject(_name, _path){}
    /**
     * @brief Film complete constructor
     * @param _name - name of the movie
     * @param _path - path to the movie file
     * @param _duration - duration of the movie
     * @param _nChs - number of chapters in the movie
     * @param _chList - list of chapters duration
     */
    Film(string _name, string _path, int _duration, int _nChs, int *_chList);

public:
    void printChInfo();
    ~Film();

    // GETTERS and SETTERS
    int getNChs() const;
    void setNChs(int value);
    int *getChList(int *_n) const;
    void setChList(int *value, int _nChs);
};

#endif // FILM_H
