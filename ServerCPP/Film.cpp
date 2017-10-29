#include "Film.h"

/**
 * @brief Getter method for the number of chapters
 * @return An integer containing the number of chapters
 */
int Film::getNChs() const
{
    return nChs;
}

/**
 * @brief Setter method for the number of chapters
 * @param value - new number of chapters
 */
void Film::setNChs(int value)
{
    nChs = value;
}

/**
 * @brief Getter method for the list of chapters duration
 * @param _n - pointer to the int containing the number of chapters
 * @return the list of chapters duration
 */
int *Film::getChList(int *_n) const
{
    *_n = nChs;
	int *_chList = new int[nChs];
	for (int i = 0; i<nChs; i++)
    	_chList[i] = chList[i];
	return _chList;
}

/**
 * @brief Setter method for the list of chapters duration
 * @param value - the list of chapters duration
 * @param _nChs - number of chapters
 */
void Film::setChList(int *value, int _nChs)
{
	if (chList != nullptr){
		delete [] chList;
		chList = nullptr;
	}
    nChs = _nChs;
	for (int i = 0; i<nChs; i++)
    	chList[i] = value[i];
}

/**
 * @brief Film complete constructor
 * @param _name - name of the movie
 * @param _path - path to the movie file
 * @param _duration - duration of the movie
 * @param _nChs - number of chapters in the movie
 * @param _chList - list of chapters duration
 */
Film::Film(string _name, string _path, int _duration, int _nChs, int *_chList) :
    VideoObject(_name, _path, _duration), nChs(_nChs) {
        chList = new int[nChs];
		for (int i = 0; i<nChs; i++)
        	chList[i] = _chList[i];
}

/**
 * @brief Method for printing chapter information
 */
void Film::printChInfo()
{
    std::cout << "------------------" << endl;
    std::cout << "Printing chapter information about Film " << getPath() << ": "<< endl;
    for (int i = 0; i < nChs; i++){
        std::cout << "Ch" << i+1 <<": "<< chList[i]<<endl;
    }
    std::cout << "------------------" << endl;
}

/**
 * @brief Film::~Film
 * Destructor for the Film class, has to free the memory for the chapters duration list
 * as well as destroy the pointer itself, in order to avoid dangling references.
 */
Film::~Film()
{
    delete [] chList;
    chList = nullptr;
}
