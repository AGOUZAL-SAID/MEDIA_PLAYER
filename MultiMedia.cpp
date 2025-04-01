#include "MultiMedia.h"
using namespace std;

MultiMedia::MultiMedia() {};

MultiMedia::MultiMedia(string name , string path) : 
    name{name} , path{path} {} ; 



    MultiMedia::~MultiMedia(){} ; string MultiMedia::get_name() const {
    return this->name ; 
}


string MultiMedia::get_path() const {
    return this->path ; 
}


void MultiMedia::set_name(string name) {
    this->name = name ; 
}

void MultiMedia::set_path(string path) {
    this->path = path ; 
}

void MultiMedia::disp(ostream & out) const {
    out << "name is : " << this->get_name() << "\npath is : "  
    << this->get_path() << endl ; 
}


void MultiMedia::write(ostream & f) const{
    f << this->name << '\n' << this->path << endl;
}

void MultiMedia::read(istream & f ){
    f >> name ;
    f >> path ;
}