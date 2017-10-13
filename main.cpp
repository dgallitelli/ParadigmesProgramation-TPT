#include <iostream>
#include <memory>

#include "MultimediaObject.h"
#include "PhotoObject.h"
#include "VideoObject.h"
#include "Film.h"
#include "Group.h"

int main(){

    /* SECTION 0 - Define datatypes for smart pointer */
    // Smart Pointer for MultimediaObject
    using MObjPtr = std::shared_ptr<MultimediaObject>;
    typedef std::shared_ptr<MultimediaObject> MObjPtr;
    // Smart Pointer for Photo
    using PhotoPtr = std::shared_ptr<PhotoObject>;
    typedef std::shared_ptr<PhotoObject> PhotoPtr;
    // Smart Pointer for Video
    using VideoPtr = std::shared_ptr<VideoObject>;
    typedef std::shared_ptr<VideoObject> VideoPtr;
    // Smart Pointer for Photo
    using PhotoPtr = std::shared_ptr<PhotoObject>;
    typedef std::shared_ptr<PhotoObject> PhotoPtr;
    // Smart Pointer for Film
    using FilmPtr = std::shared_ptr<Film>;
    typedef std::shared_ptr<Film> FilmPtr;


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
    //string chListName[] = {"OnlyOne", "nope"};

    Film *myFilm = new Film(objectName, fileName3, 10, elemNum, chListDur);
    myFilm->printChInfo();
    delete myFilm;
    myFilm = nullptr;

    /* SECTION 5 - Testing Groups */
    Group *myG1 = new Group("TestGroup1");

    PhotoPtr p1(new PhotoObject("myNewPhoto", "photo1.png", 0, 0));
    VideoPtr v1(new VideoObject("myNewVideo", "video1.avi", 10));
    FilmPtr f1(new Film(objectName, fileName3, 10, elemNum, chListDur));

    myG1->push_back(p1);
    myG1->push_back(v1);
    myG1->push_back(f1);

    myG1->print();

    delete myG1;
    myG1 = nullptr;

    return 0;
}
