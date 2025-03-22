//
// main.cpp
// Created on 21/10/2018
//
#include "Video.h"
#include "Photo.h"
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
    disp_medias(medias,n);

}
