#include "MediaManager.h"
#include <fstream>
#include <iostream>
#include <memory>
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Collection.h"
#include <fstream>

/**
 * @brief Creates a new Photo object and adds it to the media collection.
 * 
 * @param name Name of the photo.
 * @param path File path of the photo.
 * @param width Width of the photo in pixels.
 * @param height Height of the photo in pixels.
 * @return Shared pointer to the created Photo object.
 */
SharPhotoPtr MediaManager::create_photo(string name, string path, double width, double height) {
    SharPhotoPtr photo(new Photo(name, path, width, height));
    this->medias[name] = photo;
    return photo;
}

/**
 * @brief Creates a new Video object and adds it to the media collection.
 * 
 * @param name Name of the video.
 * @param path File path of the video.
 * @param duration Duration of the video in seconds.
 * @return Shared pointer to the created Video object.
 */
SharVideoPtr MediaManager::create_video(string name, string path, unsigned int duration) {
    SharVideoPtr video(new Video(name, path, duration));
    this->medias[name] = video;
    return video;
}

/**
 * @brief Creates a new Film object and adds it to the media collection.
 * 
 * @param name Name of the film.
 * @param path File path of the film.
 * @param duration Total duration of the film in seconds.
 * @param chapters Array of chapter durations.
 * @param nb_chapters Number of chapters in the film.
 * @return Shared pointer to the created Film object.
 */
SharFilmPtr MediaManager::create_Film(string name, string path, unsigned int duration,
    unsigned int const* chapters, unsigned int nb_chapters) {
    SharFilmPtr film(new Film(name, path, duration, chapters, nb_chapters));
    this->medias[name] = film;
    return film;
}

/**
 * @brief Creates a new Collection object and adds it to the groups collection.
 * 
 * @param name Name of the collection.
 * @return Shared pointer to the created Collection object.
 */
SharCollectPtr MediaManager::create_collection(string name) {
    SharCollectPtr groupe(new Collection(name));
    this->groups[name] = groupe;
    return groupe;
}

/**
 * @brief Displays information about a specific media object.
 * 
 * @param out Output stream to display the information.
 * @param name Name of the media object to display.
 */
void MediaManager::disp_media(ostream& out, string name) const {
    auto it = medias.find(name);
    if (it == medias.end()) {
        std::cout << "pas trouvé" << std::endl;
    }
    else {
        it->second->disp(out);
    }
}

/**
 * @brief Displays information about a specific collection.
 * 
 * @param out Output stream to display the information.
 * @param name Name of the collection to display.
 */
void MediaManager::disp_collection(ostream& out, string name) const {
    auto it = groups.find(name);
    if (it == groups.end()) {
        std::cout << "pas trouvé" << std::endl;
    }
    else {
        it->second->disp(out);
    }
}

/**
 * @brief Plays a media object using its associated player.
 * 
 * @param name Name of the media object to play.
 */
void MediaManager::play_media(string name) const {
    auto it = medias.find(name);
    if (it == medias.end()) {
        std::cout << "pas trouvé" << std::endl;
    }
    else {
        it->second->run();
    }
}

/**
 * @brief Deletes a media object from the manager.
 * 
 * Also removes the media from any collections that contain it.
 * @param name Name of the media object to delete.
 */
void MediaManager::delete_media(string name) {
    size_t count = medias.erase(name);
    if (!count) {
        std::cout << "No media with this name" << std::endl;
        return;
    }
    for (const auto& pair : groups) {
        for (auto it = pair.second->begin(); it != pair.second->end(); ) {
            if ((*it)->get_name() != name) it++;
            else {
                auto it2 = pair.second->erase(it);;
                it = it2;
            }
        }
    }
}

/**
 * @brief Deletes a collection from the manager.
 * 
 * @param name Name of the collection to delete.
 */
void MediaManager::delete_collection(string name) {
    size_t count = groups.erase(name);
    if (!count) {
        std::cout << "No media with this name" << std::endl;
        return;
    }
}

/**
 * @brief Displays information about all collections.
 * 
 * @param out Output stream to display the information.
 */
void MediaManager::disp_all(ostream& out) const {
    for (const auto& pair : groups) {
        pair.second->disp(out);
    }
}

/**
 * @brief Serializes all media and collections to an output stream.
 * 
 * @param f Output stream to write the data to.
 */
void MediaManager::write(ostream& f) const {
    f << "MediaManager" << '\n';
    for (const auto& pair : groups) {
        pair.second->write(f);
    }
    for (const auto& pair : medias) {
        pair.second->write(f);
    }
}

/**
 * @brief Deserializes media and collections from an input stream.
 * 
 * @param f Input stream to read the data from.
 */
void MediaManager::read(istream& f) {
    string get_name;
    f >> get_name;
    if (get_name != "MediaManager") {
        cout << "reading the object is impossible not Manager " << endl;
    }
    else {
        while (true)
        {
            if (f.eof()) {
                cout << "end of file LOL :)" << '\n';
                break;
            }

            std::getline(f, get_name);

            if (get_name == "Video") {
                SharVideoPtr p(new Video());
                p->read(f);
                medias[p->get_name()] = p;
            }
            else if (get_name == "Photo") {
                SharPhotoPtr p(new Photo());
                p->read(f);
                medias[p->get_name()] = p;
            }
            else if (get_name == "Film") {
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