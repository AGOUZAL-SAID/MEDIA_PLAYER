#ifndef MEDIA_MANAGER_H
#define MEDIA_MANAGER_H
#include "MultiMedia.h"
#include <map>
#include "Collection.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

/**
 * @typedef MediaPtr
 * @brief Shared pointer to a MultiMedia object.
 */
typedef std::shared_ptr<MultiMedia> MediaPtr;

/**
 * @typedef CollectPtr
 * @brief Shared pointer to a Collection object.
 */
typedef std::shared_ptr<Collection> CollectPtr;

/**
 * @typedef SharPhotoPtr
 * @brief Shared pointer to a Photo object.
 */
typedef std::shared_ptr<Photo> SharPhotoPtr;

/**
 * @typedef SharVideoPtr
 * @brief Shared pointer to a Video object.
 */
typedef std::shared_ptr<Video> SharVideoPtr;

/**
 * @typedef SharFilmPtr
 * @brief Shared pointer to a Film object.
 */
typedef std::shared_ptr<Film> SharFilmPtr;

/**
 * @typedef SharCollectPtr
 * @brief Shared pointer to a Collection object.
 */
typedef std::shared_ptr<Collection> SharCollectPtr;

/**
 * @typedef Dict_collection
 * @brief Map of collection names to Collection shared pointers.
 */
typedef std::map<string, CollectPtr> Dict_collection;

/**
 * @typedef Dict_Media
 * @brief Map of media names to MultiMedia shared pointers.
 */
typedef std::map<string, MediaPtr> Dict_Media;

/**
 * @class MediaManager
 * @brief Manages collections of multimedia objects and their operations.
 * 
 * This class provides functionality to create, display, play, and delete
 * various types of media objects (photos, videos, films) and collections.
 */
class MediaManager
{
private:
    Dict_collection groups {}; ///< Map storing all collections
    Dict_Media  medias {};    ///< Map storing all media objects
    
public:
    /**
     * @brief Default constructor for MediaManager.
     */
    MediaManager(){};
    
    /**
     * @brief Destructor for MediaManager.
     */
    ~MediaManager(){};
    
    /**
     * @brief Creates a new Photo object.
     * 
     * @param name Name of the photo.
     * @param path File path of the photo.
     * @param width Width of the photo in pixels.
     * @param height Height of the photo in pixels.
     * @return Shared pointer to the created Photo object.
     */
    SharPhotoPtr create_photo(string name, string path, double width, double height);
    
    /**
     * @brief Creates a new Video object.
     * 
     * @param name Name of the video.
     * @param path File path of the video.
     * @param duration Duration of the video in seconds.
     * @return Shared pointer to the created Video object.
     */
    SharVideoPtr create_video(string name, string path, unsigned int duration);
    
    /**
     * @brief Creates a new Film object.
     * 
     * @param name Name of the film.
     * @param path File path of the film.
     * @param duration Total duration of the film in seconds.
     * @param chapters Array of chapter durations.
     * @param nb_chapters Number of chapters in the film.
     * @return Shared pointer to the created Film object.
     */
    SharFilmPtr create_Film(string name, string path, unsigned int duration, 
        unsigned int const* chapters, unsigned int nb_chapters);
    
    /**
     * @brief Creates a new Collection object.
     * 
     * @param name Name of the collection.
     * @return Shared pointer to the created Collection object.
     */
    SharCollectPtr create_collection(string name);
    
    /**
     * @brief Displays information about a specific media object.
     * 
     * @param out Output stream to display the information.
     * @param name Name of the media object to display.
     */
    void disp_media(ostream& out, string name) const;
    
    /**
     * @brief Displays information about a specific collection.
     * 
     * @param out Output stream to display the information.
     * @param name Name of the collection to display.
     */
    void disp_collection(ostream& out, string name) const;
    
    /**
     * @brief Plays a media object.
     * 
     * @param name Name of the media object to play.
     */
    void play_media(string name) const;
    
    /**
     * @brief Deletes a media object.
     * 
     * @param name Name of the media object to delete.
     */
    void delete_media(string name);
    
    /**
     * @brief Deletes a collection.
     * 
     * @param name Name of the collection to delete.
     */
    void delete_collection(string name);
    
    /**
     * @brief Displays information about all media objects and collections.
     * 
     * @param out Output stream to display the information.
     */
    void disp_all(ostream& out) const;
    
    /**
     * @brief Writes the manager's data to an output stream.
     * 
     * @param f Output stream to write the data to.
     */
    void write(ostream& f) const;
    
    /**
     * @brief Reads the manager's data from an input stream.
     * 
     * @param f Input stream to read the data from.
     */
    void read(istream& f);
};

#endif