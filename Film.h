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
        unsigned int const * chapters, unsigned int nb_chapters);
    
        
    Film(const  Film & from);
public:
    Film & operator=(const Film & from);
    ~Film();



    void set_chapters(unsigned int const * chapters,unsigned int nb_chapters);

    const unsigned int * get_chapters() const;

    unsigned int get_nb_chapters() const;

    void disp(ostream & out) const override ;
    
    string get_class_name() const override;

    void serial_chapters(ostream & f) const;

    void deserial_chapters(istream & f) ;

    void write(ostream & f) const override;
    
    void read(istream & f) override;


};

#endif