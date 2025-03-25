#ifndef MEDIA_MANAGER_H
#define MEDIA_MANAGER_H
#include "MultiMedia.h"
#include <map>
#include "Collection.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

typedef std::shared_ptr<MultiMedia> MediaPtr;
typedef std::shared_ptr<Collection> CollectPtr;

typedef std::shared_ptr<Photo> SharPhotoPtr;
typedef std::shared_ptr<Video> SharVideoPtr;
typedef std::shared_ptr<Film> SharFilmPtr;
typedef std::shared_ptr<Collection> SharCollectPtr;

typedef std::map<string, CollectPtr > Dict_collection;
typedef std::map<string, MediaPtr > Dict_Media;

class MediaManager
{
private:
    Dict_collection groups {};
    Dict_Media  medias {};  
public:
    MediaManager(){};
    ~MediaManager(){};
    SharPhotoPtr create_photo(string name, string path, double width, double height);
    SharVideoPtr create_video(string name, string path, unsigned int duration);
    SharFilmPtr create_Film(string name , string path , unsigned int duration , 
        unsigned int const * chapters, unsigned int nb_chapters) ;
    SharCollectPtr create_collection(string name);
    void disp_media(ostream & out, string name) const;
    void disp_collection(ostream & out, string name) const ;
    void play_media(string name) const;
    void delete_media(string name) ;
    void delete_collection(string name) ;
    void disp_all(ostream & out) const ;
};

#endif