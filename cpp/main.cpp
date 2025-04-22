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

/**
 * @brief Main function for server mode of the multimedia application.
 * 
 * Creates a MediaManager with sample data and starts a TCP server to handle client requests.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return int Returns 0 on success, 1 on server startup failure.
 */
int main(int argc, char* argv[])
{
    // Create media manager with sample data
    MediaManager* manager = new MediaManager();
    {
        std::shared_ptr<Video> media1 = manager->create_video("video1", "tralalelo.mp4", 50);
        std::shared_ptr<Photo> media2 = manager->create_photo("photo1", "photo1.jpg", 50, 50);
        std::shared_ptr<Film> media3 = manager->create_Film("Film2", "film.mp4", 50, nullptr, 0);
        std::shared_ptr<Collection> groupe = manager->create_collection("HAPPY");
        groupe->push_back(media1);
        groupe->push_back(media2);
        groupe->push_back(media3);
    }

    // Create TCP server with request handler
    auto* server =
        new TCPServer([&manager](std::string const& request, std::string& response) {

            // Log the incoming request
            cout << "request: " << request << endl;

            // Parse the request into commands
            stringstream ss(request);
            string word;
            string cmd_1 = "";
            string cmd_2 = "";
            string cmd_3 = "";
            int i = 1;

            while (getline(ss, word, ' ')) {
                if (i == 1) { cmd_1 = word; i++; }
                else if (i == 2) { cmd_2 = word; i++; }
                else { cmd_3 = word; break; }
            }
            cout << "ma commande : " << cmd_1 << endl;

            // Handle different commands
            if (cmd_1 == "FIND_MEDIA") {
                stringstream ss;
                string moha;
                string disp = "";
                manager->disp_media(ss, cmd_2);
                while (getline(ss, moha)) {
                    disp = disp + moha + '_';
                };
                response = disp;
            }
            else if (cmd_1 == "FIND_GROUPE") {
                stringstream ss;
                string moha;
                string disp = "";
                manager->disp_collection(ss, cmd_2);
                while (getline(ss, moha)) {
                    disp = disp + moha + '_';
                };
                response = disp;
            }
            else if (cmd_1 == "PLAY_MEDIA") {
                manager->play_media(cmd_2);
            }
            else if (cmd_1 == "DELETE_MEDIA") {
                manager->delete_media(cmd_2);
            }
            else if (cmd_1 == "DELETE_COLLECTION") {
                manager->delete_collection(cmd_2);
            }
            else if (cmd_1 == "DISP_ALL") {
                stringstream ss;
                string moha;
                string disp = "";
                manager->disp_all(ss);
                while (getline(ss, moha)) {
                    disp = disp + moha + '_';
                };
                response = disp;
            }
            else {
                response = "Waiting or try again the server block two seconds some times";
            }
            // return false would close the connection with the client
            return true;
        });

    // Start the server
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // Handle server startup error
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}

#else

/**
 * @brief Main function for local testing mode of the multimedia application.
 * 
 * Creates a MediaManager with sample data and performs various operations for testing.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return int Returns 0 on success.
 */
int main(int argc, const char* argv[]) {
    // Create media manager with test data
    MediaManager* manager = new MediaManager();
    manager->create_photo("p1", "d:", 50, 50);
    manager->create_video("v1", "c:", 50);
    manager->create_video("v2", "c:", 60);
    manager->create_collection("vacances");
    unsigned int chapters[6] = { 0,1,2,3,4,5 };
    manager->create_Film("johncena", "c:/www", 50, chapters, 6);

    // Display test data
    manager->disp_collection(cout, "vacances");
    manager->disp_media(cout, "p1");
    manager->disp_media(cout, "v1");
    manager->disp_media(cout, "v2");
    manager->disp_media(cout, "john cena");

    // Serialization test
    std::ofstream file("serialisation.txt");
    if (!file) { cout << "failed open file " << endl; return 0; }
    manager->write(file);

    // Deletion test
    manager->delete_media("p1");
    manager->delete_media("v1");
    manager->delete_media("v2");
    manager->delete_media("john cena");
    file.close();
    cout << " deleting excuted succefully :)" << endl;

    // Recreate and deserialize test
    manager->create_Film("john cena", "c:/www", 50, chapters, 6);
    cout << "deletion excuted succefully :) " << endl;
    std::ifstream p("serialisation.txt");
    if (!p) { cout << "failed open file " << endl; return 0; }
    manager->read(p);

    // Display after deserialization
    manager->disp_collection(cout, "vacances");
    manager->disp_media(cout, "p1");
    manager->disp_media(cout, "v1");
    manager->disp_media(cout, "v2");
    manager->disp_media(cout, "john cena");
}
#endif