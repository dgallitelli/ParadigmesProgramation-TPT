#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "MultimediaObject.h"
#include "PhotoObject.h"
#include "VideoObject.h"
#include "Film.h"
#include "Group.h"
#include "Database.h"

using namespace std;
using namespace cppu;

const int PORT = 3331;

class MyBase {

    stringstream myss;
    Database *myDB = nullptr;
public:
    MyBase(Database &_db){
        // TODO define constructor by copy
        myDB = new Database(_db);
    }

    /* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
   * Ca doit etre une methode de la classe qui gere les données, afin qu'elle
   * puisse y accéder.
   *
   * Arguments:
   * - 'request' contient la requête
   * - 'response' sert à indiquer la réponse qui sera renvoyée au client
   * - si la fonction renvoie false la connexion est close.
   *
   * Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
   * un thread par client).
   *
   * Pour eviter les problemes de concurrence on peut créer un verrou en creant
   * une variable Lock **dans la pile** qui doit etre en mode WRITE (2e argument = true)
   * si la fonction modifie les donnees.
   */
    bool processRequest(TCPConnection& cnx, const string& request, string& response)
    {
        cerr << "\nRequest: '" << request << "'" << endl;

        bool fileFound = false;

        // 1) pour decouper la requête:
        // on peut par exemple utiliser stringstream et getline()
        myss.str(std::string());
        char split_char = ' ';
        istringstream split(request);

        vector<string> tokens;
        for (string each; getline(split, each, split_char); tokens.push_back(each));

        // 2) faire le traitement:
        // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
        // - sinon juste: TCPLock lock(cnx);
        TCPLock lock(cnx);

        myDB->printObjectFromName(tokens[1], myss);
        if (myss.rdbuf()->in_avail() == 0){
            // The file is not in the db
            response = "ERR - File not found";
        } else {
            fileFound = true;
            response = myss.str();
        }

        if (tokens[0] == "play" && fileFound){
            myDB->reproduceFromName(tokens[1]);
            response = "OK - File is beADDITIONAL_CPPing reproduced.";
        }

        // 3) retourner la reponse au client:
        // - pour l'instant ca retourne juste OK suivi de la requête
        // - pour retourner quelque chose de plus utile on peut appeler la methode print()
        //   des objets ou des groupes en lui passant en argument un stringstream
        // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
        //   ils servent à délimiter les messages entre le serveur et le client
        cerr << "response: " << response << endl;

        // renvoyer false si on veut clore la connexion avec le client
        return true;
    }
};


int main(int argc, char* argv[])
{
    /* SECTION 0 - Define datatypes for smart pointer */
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
    // Smart Pointer for Group
    using GroupPtr = std::shared_ptr<Group>;
    typedef std::shared_ptr<Group> GroupPtr;

    int elemNum = 2;
    int chListDur[] = {10, 20};

    Database *db = new Database();
    PhotoPtr pdb = db->newPhoto("test", "test.png", 0, 0);
    VideoPtr vdb = db->newVideo("video1", "./video1.avi", 10);
    FilmPtr fdb = db->newFilm("film1", "./movie1.avi", 10, elemNum, chListDur);
    GroupPtr gdb = db->newGroup("gdbName");
    gdb->push_back(pdb);
    gdb->push_back(vdb);
    gdb->push_back(fdb);

    // cree le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());

    // cree l'objet qui gère les données
    shared_ptr<MyBase> base(new MyBase(*db));

    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*base, &MyBase::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        cerr << "Could not start Server on port " << PORT << endl;
        return 1;
    }

    return 0;
}

