//
// main.cpp
// Created on 21/10/2018
//
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include <iostream>
#include "Collection.h"
#include <memory>
using namespace std;
typedef std::shared_ptr<MultiMedia> MediaPtr;


int main(int argc, const char* argv[]){
    MediaPtr v1(new Video("v1","c:",50));
    MediaPtr p1(new Photo("p1","d:",50,50));
    MediaPtr v2(new Video("v2","c:",60));
    Collection * my_collection = new Collection("vacances");
    my_collection->push_back(v1);
    my_collection->push_back(p1);
    my_collection->push_back(v2);
    unsigned int chapters[6] = {0,1,2,3,4,5} ;
    MediaPtr f1(new Film("john cena","c:/www",50,chapters,6));
    my_collection->push_back(f1);
    my_collection->disp(cout);
    delete my_collection;
    cout << " function excuted succefully :)"<<endl;
}
