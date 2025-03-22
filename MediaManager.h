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
typedef std::weak_ptr<const MultiMedia> WeakMediaPtr;
typedef std::weak_ptr<const Collection> WeakCollectPtr;

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
    WeakMediaPtr create_photo(string name, string path, double width, double height);
    WeakMediaPtr create_video(string name, string path, unsigned int duration);
    WeakMediaPtr create_Film(string name , string path , unsigned int duration , 
        unsigned int * chapters, unsigned int nb_chapters) ;
    WeakCollectPtr creat_collection(string name);
    void disp_media(ostream & out, string name) const;
    void disp_collection(ostream & out, string name) const ;
    void play_media(string name) const;
    void delete_media(string name) ;
};

#endif