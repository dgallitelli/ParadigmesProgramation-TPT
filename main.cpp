#include "MultimediaObject.h"
#include "PhotoObject.h"
#include "VideoObject.h"
#include "Film.h"

int main(){

    /* SECTION 1 - Testing Multimedia Object */

    std::string objectName ("Testing");
    std::string fileName ("world");

    /*MultimediaObject *mo = new MultimediaObject(objectName, fileName);
    mo->writeOnStream(std::cout);
    delete mo;
    mo = nullptr;*/

    /* SECTION 2 - Testing Photo Object */

    std::string fileName2 ("./DNI.png");
    PhotoObject *po = new PhotoObject(objectName, fileName2, 0, 0);
    //po->reproduce();
    delete po;
    po = nullptr;

    /* SECTION 2.1 - Testing Video Object */

    std::string fileName3 ("./video1.mkv");
    VideoObject *vo = new VideoObject(objectName, fileName3, 10);
    //vo->reproduce();
    delete vo;
    vo = nullptr;

    /* SECTION 3 - Testing Array of pics/movies */
    int valueNum = 4;
    string moObjNameArray[] = {"obj1", "obj2","obj3","obj4"};
    string moFileNameArray[] = {"./vr.jpg", "./video1.mkv", "./video2.mp4", "./DNI.png"};
    MultimediaObject* moArray[] = {
        new PhotoObject(moObjNameArray[0], moFileNameArray[0], 0, 0),
        new VideoObject(moObjNameArray[1], moFileNameArray[1], 10),
        new VideoObject(moObjNameArray[2], moFileNameArray[2], 20),
        new PhotoObject(moObjNameArray[3], moFileNameArray[3], 0, 0)
    };

    //for (int i = 0; i < valueNum; i++)
        //moArray[i]->reproduce();

    for (int i = 0; i < valueNum; i++)
        delete moArray[i];


    /* SECTION 4 - Testing Film Object */
    int elemNum = 2;
    int chListDur[] = {10, 20};
    string chListName[] = {"OnlyOne", "nope"};

    Film *myFilm = new Film(elemNum, chListDur, chListName, objectName, fileName3, 10);
    myFilm->printChInfo();
    delete myFilm;
    myFilm = nullptr;

    return 0;
}
