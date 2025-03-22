#ifndef COLLECTION_H
#include "MultiMedia.h"
class Collection : public list<MultiMedia *>
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
