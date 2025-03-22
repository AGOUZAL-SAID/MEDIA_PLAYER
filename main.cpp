//
// main.cpp
// Created on 21/10/2018
//
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include <iostream>
#include "Collection.h"
using namespace std;

void disp_medias( MultiMedia ** medias, int n){
    for(int i = 0 ; i<n ; i++){
        if (medias[i]) medias[i]->disp(cout);
    }
}
int main(int argc, const char* argv[]){
    Collection * my_collection = new Collection("vacances");
    my_collection->push_back(new Video("v1","c:",50));
    my_collection->push_back(new Photo("p1","d:",50,50));
    my_collection->push_back(new Video("v2","c:",60));
    unsigned int chapters[6] = {0,1,2,3,4,5} ;
    Film * my_film = new Film("john cena","c:/www",50,chapters,6);
    my_collection->push_back(my_film);
    my_collection->disp(cout);
}
