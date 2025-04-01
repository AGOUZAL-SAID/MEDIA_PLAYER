#include "Film.h"

Film::Film(string name , string path , unsigned int duration , unsigned int const * 
    chapters,unsigned int  nb_chapters):
    Video::Video(name,path,duration) , nb_chapters{nb_chapters} {
        {
            this->chapters = new unsigned int[nb_chapters]; // Allocation dynamique
            for (unsigned int i = 0; i < nb_chapters; ++i) {
                if (!chapters){this->chapters=nullptr;this->nb_chapters=0;break;}
                this->chapters[i] = chapters[i]; // Copie des données
            }
        }
    };

Film::~Film( ) { delete[] chapters;}

void Film::set_chapters(unsigned int const * chapters , unsigned int nb_chapters){
    delete[] this->chapters; 
    if (!chapters){this->chapters=nullptr;this->nb_chapters=0;return;}
    this->chapters = new unsigned int[nb_chapters];
    for (unsigned int i = 0; i < nb_chapters; i++) this->chapters[i] = chapters[i] ; 
    this->nb_chapters = nb_chapters;
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


Film::Film(const Film & from) : Video::Video(from.get_name(),from.get_path(),
    from.get_duration()) , nb_chapters{from.get_nb_chapters()} {
        this->chapters = new unsigned int[nb_chapters]; // Allocation dynamique
                for (unsigned int i = 0; i < nb_chapters; ++i) {
                    if (!chapters){this->chapters=nullptr;this->nb_chapters=0;break;}
                    this->chapters[i] = from.get_chapters()[i]; // Copie des données
                }
    };


Film & Film::operator=(const Film & from){
    Video::operator=(from);
    if (this->chapters) delete[] chapters;
    this->chapters = new unsigned int[nb_chapters]; // Allocation dynamique
    for (unsigned int i = 0; i < nb_chapters; ++i) {
        if (!chapters){this->chapters=nullptr;this->nb_chapters=0;break;}
        this->chapters[i] = from.get_chapters()[i]; // Copie des données
    }
    return *this;
}


string Film::get_class_name() const {
    return "Film";
}

void Film::write(ostream &f) const{
    Video::write(f);
    this->serial_chapters(f);
    f << nb_chapters << endl ; 
}

void Film::serial_chapters(ostream & f) const{
    for (int64_t i = 0 ; i<nb_chapters;i++){
        f << chapters[i] << '\n';
    }
}

void Film::deserial_chapters(istream & f) {
    chapters = new unsigned int [nb_chapters];
    for (int64_t i = 0 ; i<nb_chapters ; i++){
        unsigned int chapter ;
        f >> chapter;
        chapters[i] = chapter;
    }
}

void Film::read(istream & f){
    Video::read(f);
    deserial_chapters(f);
    f >> nb_chapters;
}