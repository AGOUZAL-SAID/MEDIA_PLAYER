#include "MediaManager.h"


WeakMediaPtr MediaManager::create_photo(string name, string path, double width, double height){
    MediaPtr photo(new Photo(name, path, width, height));
    this->medias[name]=photo;
    WeakMediaPtr photo_weak = photo;
    return photo_weak;
}

WeakMediaPtr MediaManager::create_video(string name, string path, unsigned int duration){
    MediaPtr video(new Video(name, path, duration));
    this->medias[name]=video;
    WeakMediaPtr video_weak = video;
    return video_weak;
}

WeakMediaPtr MediaManager::create_Film(string name , string path , unsigned int duration , 
    unsigned int * chapters, unsigned int nb_chapters) {
        MediaPtr film(new Film(name, path, duration, chapters, nb_chapters));
        this->medias[name]=film;
        WeakMediaPtr film_weak = film;
        return film_weak;

    }

WeakCollectPtr MediaManager::create_collection(string name){
    CollectPtr groupe(new Collection(name));
    this->groups[name]= groupe;
    WeakCollectPtr groupe_weak = groupe;
    return groupe_weak;
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