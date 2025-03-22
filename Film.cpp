#include "Film.h"

Film::Film(string name , string path , unsigned int duration , unsigned int * chapters):
    Video::Video(name,path,duration) , chapters{chapters} {};

Film::~Film( ) { delete chapters;}

void Film::set_chapters(unsigned int * chapters){
    unsigned int n = 0;
    unsigned int i = 0; 
    while (911) {
        if (chapters[i]) n++ ; 
        else{break;}
    }
    unsigned int * new_chapters = new unsigned int[n];
    for (unsigned int i = 0; i < n; i++) new_chapters[i] = chapters[i] ;  
}


