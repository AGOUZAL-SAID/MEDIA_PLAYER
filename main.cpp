//
// main.cpp
// Created on 21/10/2018
//
#include <iostream>
#include <memory>
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Collection.h"
#include "MediaManager.h"
#include <fstream>

using namespace std;
#define SERVER_v

#ifdef SERVER_v
#include <sstream>
#include "tcpserver.h"
const int PORT = 3331;


int main(int argc, char* argv[])
{

    MediaManager * manager = new MediaManager();
    {
    std::shared_ptr<Video> media1 = manager->create_video("video1","tralalelo.mp4",50);
    std::shared_ptr<Photo> media2 = manager->create_photo("photo1","photo1.jpg",50,50);
    std::shared_ptr<Film> media3 = manager->create_Film("Film2","film.mp4",50,nullptr,0);
    std::shared_ptr<Collection> groupe = manager->create_collection("HAPPY");
    groupe->push_back(media1);
    groupe->push_back(media2);
    groupe->push_back(media3);
    }

  // cree le TCPServer
  auto* server =
  new TCPServer( [&manager](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    cout << "request: " << request << endl;

    stringstream ss(request);
    string word;
    string cmd_1 = "" ; 
    string cmd_2 = "" ;
    string cmd_3 = "" ;
    int i = 1;

    while(getline(ss,word,' ')){
        if(i==1){cmd_1 = word;i++;}
        else if(i==2){cmd_2 = word;i++;}
        else {cmd_3 = word;break;}
    }
    cout<<"ma commande : "<<cmd_1<<endl;
    if(cmd_1 == "FIND_MEDIA"){
        stringstream ss;
        string moha;
        string disp = "";
        manager->disp_media(ss,cmd_2);
        while (getline(ss,moha)){
            disp = disp + moha + '_';
        };
        response = disp;
    }
    else if (cmd_1 == "FIND_GROUPE")
    {
        stringstream ss;
        string moha;
        string disp = "";
        manager->disp_collection(ss,cmd_2);
        while (getline(ss,moha)){
            disp = disp + moha + '_';
        };
        response = disp;
    }
    else if (cmd_1 =="PLAY_MEDIA")
    {
        manager->play_media(cmd_2);
    }
    else if (cmd_1 == "DELETE_MEDIA")
    {
        manager->delete_media(cmd_2);
    }
    else if (cmd_1 == "DELETE_COLLECTION")
    {
        manager->delete_collection(cmd_2);
    }
    else if (cmd_1 == "DISP_ALL"){
        stringstream ss;
        string moha;
        string disp = "";
        manager->disp_all(ss);
        while (getline(ss,moha)){
            disp = disp + moha + '_';
        };
        response = disp;
    }
    else{
        response = "Invalide commande";
    }
    // return false would close the connecytion with the client
    return true;
  });
  
  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;
  
  int status = server->run(PORT);
  
  // en cas d'erreur
  if (status < 0) {
      std::cerr << "Could not start Server on port " << PORT << std::endl;
      return 1;
    }
    
    return 0;
}

#else

int main(int argc, const char* argv[]){
    MediaManager * manager = new MediaManager();
    manager->create_photo("p1","d:",50,50);
    manager->create_video("v1","c:",50);
    manager->create_video("v2","c:",60);
    manager->create_collection("vacances");
    unsigned int chapters[6] = {0,1,2,3,4,5};
    manager->create_Film("johncena","c:/www",50,chapters,6);
    manager->disp_collection(cout,"vacances");
    manager->disp_media(cout,"p1");
    manager->disp_media(cout,"v1");
    manager->disp_media(cout,"v2");
    manager->disp_media(cout,"john cena");
    std::ofstream file("serialisation.txt");
    if (!file){ cout << "failed open file "<< endl; return 0;}
    manager->write(file);
    manager->delete_media("p1");
    manager->delete_media("v1");
    manager->delete_media("v2");
    manager->delete_media("john cena");
    file.close();
    cout << " deleting excuted succefully :)"<<endl;
    manager->create_Film("john cena","c:/www",50,chapters,6);
    //delete manager;
    cout << "deletion excuted succefully :) " << endl;
    std::ifstream p("serialisation.txt");
    if (!p){ cout << "failed open file "<< endl; return 0;}
    manager->read(p);
    manager->disp_collection(cout,"vacances");
    manager->disp_media(cout,"p1");
    manager->disp_media(cout,"v1");
    manager->disp_media(cout,"v2");
    manager->disp_media(cout,"john cena");
}
#endif
