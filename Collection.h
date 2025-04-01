#ifndef COLLECTION_H
#define COLLECTION_H
#include "MultiMedia.h"
typedef std::shared_ptr<MultiMedia> MediaPtr;
typedef std::shared_ptr<Photo> SharPhotoPtr;
typedef std::shared_ptr<Video> SharVideoPtr;
typedef std::shared_ptr<Film> SharFilmPtr;
class Collection : public list<MediaPtr>
{
    friend class MediaManager;
private:
    string name {};
    Collection(string name);
    Collection();
public:
    ~Collection(){};
    string get_name() const;
    string get_class_name() const;
    void write(ostream & f) const;
    void read(istream & f ) ;
    void disp(ostream & out) const ;
};
#endif
