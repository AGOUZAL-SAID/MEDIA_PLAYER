#ifndef FILM_H
#define FILM_H
#include "Video.h"
class Film : public Video
{
private:
    unsigned int * chapters {};
public:
    Film(){}
    
    Film(string name , string path , unsigned int duration , unsigned int * chapters);
    
    ~Film( );

    void set_chapters(unsigned int * chapters);

    unsigned int * get_chapters() const;

    unsigned int get_nb_chapters() const;

    void disp() const ;

};

#endif