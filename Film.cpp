#include "Film.h"

Film::Film(string name , string path , unsigned int duration , unsigned int *
    chapters,unsigned int  nb_chapters):
    Video::Video(name,path,duration) , nb_chapters{nb_chapters} {
        {
            this->chapters = new unsigned int[nb_chapters]; // Allocation dynamique
            for (unsigned int i = 0; i < nb_chapters; ++i) {
                this->chapters[i] = chapters[i]; // Copie des données
            }
        }
    };

Film::~Film( ) { delete[] chapters;}

void Film::set_chapters(unsigned int * chapters , unsigned int nb_chapters){
    if (this->chapters) {
        delete[] this->chapters; 
    }
    unsigned int * new_chapters = new unsigned int[nb_chapters];
    for (unsigned int i = 0; i < nb_chapters; i++) new_chapters[i] = chapters[i] ; 
    this->nb_chapters = nb_chapters;
    this->chapters = new_chapters; 
}


const unsigned int * Film::get_chapters() const{
    return chapters;    
}

unsigned int Film::get_nb_chapters() const{
    return nb_chapters;
}

void Film::disp(ostream & out) const{
    Video::disp(out);
    out << "Chapters duration are: ";
    for (unsigned int i = 0; i < nb_chapters; ++i) {
        out << chapters[i] << " "; // Affiche chaque élément du tableau
    }
    out << ", Number of chapters: " << nb_chapters << endl;
}

