#include "Collection.h"

Collection::Collection(string name) : name{name} {};

string Collection::get_name() const{
    return name;
}

void Collection::disp(ostream & out) const{
    out << "name of groupe is : " << name << endl;
    for (const auto& media : *this) {
        media->disp(out);  
}}

void Collection::write(ostream & f) const {
    f << "Collection"<<'\n';
    f << name <<'\n';
}

string Collection::get_class_name() const {
    return "Collection";
}

void Collection::read(istream & f)  {
        string get_name;
        streampos position = f.tellg();
        f >> get_name;
        if (get_name != "Collection"){
            cout << "reding the object is impossible not same classe " <<endl;
            f.seekg(position);
        }
        else {
            f >> name;
}}