//
// main.cpp
// Created on 21/10/2018
//
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include <iostream>
using namespace std;

void disp_medias( MultiMedia ** medias, int n){
    for(int i = 0 ; i<n ; i++){
        if (medias[i]) medias[i]->disp(cout);
    }
}
int main(int argc, const char* argv[]){
    int n = 5 ;
    MultiMedia ** medias = new MultiMedia*[n];
    medias[0] = new Video("v1","c:",50);
    medias[1] = new Photo("p1","d:",50,50);
    medias[2] = new Video("v2","c:",60);
    unsigned int chapters[6] = {0,1,2,3,4,5} ;
    Film * my_film = new Film("john cena","c:/www",50,chapters,6);
    my_film->disp(cout);
    {
    unsigned int new_chapters[6] = {1,1,2,3,4,5} ;
    my_film->set_chapters(new_chapters,6);
    }
    my_film->disp(cout);
    disp_medias(medias,n);

}
