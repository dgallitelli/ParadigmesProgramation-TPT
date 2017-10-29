#include "Film.h"


int Film::getNChs() const
{
    return nChs;
}

void Film::setNChs(int value)
{
    nChs = value;
}

int *Film::getChList(int *_nChs) const
{
	*_nChs, nChs;
	int *_chList = new int[nChs];
	for (int i = 0; i<nChs; i++)
    	_chList[i] = chList[i];
	return _chList;
}

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

Film::Film(string _name, string _path, int _duration, int _nChs, int *_chList) :
    VideoObject(_name, _path, _duration), nChs(_nChs) {
        chList = new int[nChs];
		for (int i = 0; i<nChs; i++)
        	chList[i] = _chList[i];
}

void Film::printChInfo()
{
    std::cout << "------------------" << endl;
    std::cout << "Printing chapter information about Film " << getPath() << ": "<< endl;
    for (int i = 0; i < nChs; i++){
        std::cout << "Ch" << i+1 <<": "<< chList[i]<<endl;
    }
    std::cout << "------------------" << endl;
}

Film::~Film()
{
    delete [] chList;
    chList = nullptr;
}
