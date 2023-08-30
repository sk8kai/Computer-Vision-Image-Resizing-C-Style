// Project UID af1f95f547e44c8ea88730dfb185559d
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Image.h"
#include "Matrix.h"
#include "fstream"
#include <cassert>
#include <cstdlib>
#include "processing.h"

using namespace std;

int main (int argc, char* argv[]) {
    if (argc != 4 && argc != 5) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }

    string fileName = argv[1];
    ifstream imageIn;
    imageIn.open(fileName);
    
    if (!(imageIn.is_open())) {
        cout << "Error opening file: " << fileName << endl;
        return 1;
    }

    Image* img = new Image;
    string fileOut = argv[2];
    int height;
    int width;
    ofstream out(fileOut);
    if (argc == 4) {
        width = atoi(argv[3]);
        Image_init(img, imageIn);
        seam_carve(img,width, Image_height(img));
    }
    if (argc == 5) {
        height = atoi(argv[4]);
        width = atoi(argv[3]);
        Image_init(img, imageIn);
        seam_carve(img, width, height);
    }
    Image_print(img, out);
    
    delete img;
    return 0;
}

