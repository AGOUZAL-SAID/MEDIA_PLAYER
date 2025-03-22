#ifndef FILM_H
#define FILM_H
#include "Video.h"
class Film : public Video
{
    friend class MediaManager;
private:
    unsigned int * chapters {};
    unsigned int nb_chapters {};
    Film();
    
    Film(string name , string path , unsigned int duration , 
        unsigned int * chapters, unsigned int nb_chapters);
    
        
    Film(const  Film & from);
    Film & operator=(const Film & from);
public:
    ~Film();



    void set_chapters(unsigned int * chapters,unsigned int nb_chapters);

    const unsigned int * get_chapters() const;

    unsigned int get_nb_chapters() const;

    void disp(ostream & out) const override ;

};

#endif