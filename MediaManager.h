#ifndef MEDIA_MANAGER_H
#include "MultiMedia.h"
#include <map>
#include "Collection.h"

typedef std::shared_ptr<MultiMedia> MediaPtr;
typedef std::shared_ptr<Collection> CollectPtr;

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
    void create_photo(string name, string path, double width, double height);
    void create_video(string name, string path, unsigned int duration);
    void create_Film(string name , string path , unsigned int duration , 
        unsigned int * chapters, unsigned int nb_chapters) ;
    void creat_collection(string name);
    void disp_media(string name) const;
    void disp_collection(string name) const ;
    void play_media(string name);
};

#endif