#ifndef COLLECTION_H
#include "MultiMedia.h"
typedef std::shared_ptr<MultiMedia> MediaPtr;

class Collection : public list<MediaPtr>
{
private:
    string name {};
public:
    Collection(string name);
    ~Collection(){};
    string get_name() const;
    void disp(ostream & out) const ;
};
#endif
