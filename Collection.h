#ifndef COLLECTION_H
#include "MultiMedia.h"
typedef std::shared_ptr<MultiMedia> MediaPtr;

class Collection : public list<MediaPtr>
{
    friend class MediaManager;
private:
    string name {};
    Collection(string name);
    ~Collection(){};
public:
    string get_name() const;
    void disp(ostream & out) const ;
};
#endif
