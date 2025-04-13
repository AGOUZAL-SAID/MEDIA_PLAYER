#include "MediaManager.h"
#include <fstream>
#include <iostream>
#include <iostream>
#include <memory>
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Collection.h"
#include "MediaManager.h"
#include <fstream>
SharPhotoPtr MediaManager::create_photo(string name, string path, double width, double height){
    SharPhotoPtr photo(new Photo(name, path, width, height));
    this->medias[name]=photo;
    return photo;
}

SharVideoPtr MediaManager::create_video(string name, string path, unsigned int duration){
    SharVideoPtr video(new Video(name, path, duration));
    this->medias[name]=video;
    return video;
}

SharFilmPtr MediaManager::create_Film(string name , string path , unsigned int duration , 
    unsigned int const * chapters, unsigned int nb_chapters) {
        SharFilmPtr film(new Film(name, path, duration, chapters, nb_chapters));
        this->medias[name]=film;
        return film;

    }

SharCollectPtr MediaManager::create_collection(string name){
    SharCollectPtr groupe(new Collection(name));
    this->groups[name]= groupe;
    return groupe;
}

void MediaManager::disp_media(ostream & out, string name) const{
    auto it = medias.find(name);
    if (it == medias.end()) {
        std::cout << "pas trouvé" << std::endl;} 
    else {it->second->disp(out);}
}

void MediaManager::disp_collection(ostream & out, string name) const {
    auto it = groups.find(name);
    if (it == groups.end()) {
        std::cout << "pas trouvé" << std::endl;} 
    else {it->second->disp(out);}
}

void MediaManager::play_media(string name) const{
    auto it = medias.find(name);
    if (it == medias.end()) {
        std::cout << "pas trouvé" << std::endl;} 
    else {it->second->run();}
}

void MediaManager::delete_media(string name){
    size_t count = medias.erase(name);
    if (!count) {
        std::cout << "No media with this name" << std::endl;
        return;}
    for (const auto& pair : groups) {
        for (auto it = pair.second->begin(); it != pair.second->end(); ) {
            if ( (*it)->get_name() != name ) it++;
            else {
                auto it2 = pair.second->erase(it);;
                it = it2; }
            }
    }
}

void MediaManager::delete_collection(string name){
    size_t count = groups.erase(name);
    if (!count) {
        std::cout << "No media with this name" << std::endl;
        return;}
}

void MediaManager::disp_all(ostream & out) const{
    for (const auto& pair : groups) {
        pair.second->disp(out);
    }
}

void MediaManager::write(ostream & f) const {
    f << "MediaManager"<< '\n';
    for (const auto & pair : groups) {
        pair.second->write(f);
    }
    for (const auto & pair : medias) {
        pair.second->write(f);
    }
}

void MediaManager::read(istream & f){
    string get_name;
    f >> get_name;
    if (get_name != "MediaManager"){
        cout << "reading the object is impossible not Manager " <<endl;
    }
    else {
        while (true)
        {
            if(f.eof()){
                cout << "end of file LOL :)"<< '\n';
                break;}
                
            std::getline(f,get_name);

            if (get_name == "Video"){
                SharVideoPtr p(new Video());
                p->read(f);
                medias[p->get_name()] = p;
            }
            else if (get_name == "Photo"){
                SharPhotoPtr p(new Photo());
                p->read(f);
                medias[p->get_name()] = p;
            }
            else if (get_name == "Film"){
                SharFilmPtr p(new Film());
                p->read(f);
                medias[p->get_name()] = p;
            }
            else if (get_name == "Collection") {
                SharCollectPtr p(new Collection());
                p->read(f);
                groups[p->get_name()] = p;
            }
            else {
                cout << "there is an invalid object in this file U Monster !";
                break;
            }
        }
    }
}
