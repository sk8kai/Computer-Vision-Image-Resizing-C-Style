// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.h"
#include "Matrix.h"
using namespace std;

// REQUIRES: img points to an Image
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, int width, int height) {
    assert(0 < width && width <= MAX_MATRIX_WIDTH);
    assert(0 < height && height <= MAX_MATRIX_HEIGHT);
    img->width = width;
    img->height = height;
    
    Matrix *ptr = &(img->red_channel);
    Matrix_init(ptr, width, height);
    ptr = &(img->green_channel);
    Matrix_init(ptr, width, height);
    ptr = &(img->blue_channel);
    Matrix_init(ptr, width, height);
}

// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, std::istream& is) {
    string p3;
    is >> p3;
    assert(p3 == "P3");
    int width;
    is >> width;
    int height;
    is >> height;
    Image_init(img, width, height);
    int colors;
    is >> colors;

    for (int i = 0; i < img->height; i++){
        for (int j = 0; j < img->width; j++) {
            int red;
            int green;
            int blue;
            is >> red;
            is >> green;
            is >> blue;
    
        
            *Matrix_at(&img->red_channel, i, j) = red;
            *Matrix_at(&img->green_channel, i, j) = green;
            *Matrix_at(&img->blue_channel, i, j) = blue;
            
            Pixel ran = {red, green, blue};
            Image_set_pixel(img, i, j, ran);
        }
    }
    //dont have to write a whole file to test it
    //istream stream?
}


// REQUIRES: img points to a valid Image
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.
void Image_print(const Image* img, std::ostream& os) {
    os << "P3" << endl;
    os << img->width << " " << img->height << endl;
    os << "255" << endl;
    
    for(int rowCount = 0; rowCount < img->height; rowCount++){
        for(int i = 0; i < img->width; i++) {
            os << *Matrix_at(&img->red_channel, rowCount, i) << " ";
            os << *Matrix_at(&img->green_channel, rowCount, i) << " ";
            os << *Matrix_at(&img->blue_channel, rowCount, i) << " ";
        }
        os << endl;
    }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image* img) {
    int x = img->width;
    return x;
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image* img) {
    int x = img->height;
    return x;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image* img, int row, int column) {
    assert(0 <= row && row < Image_height(img));
    assert(0 <= column && column < Image_width(img));
    Pixel returnPixel;
    const Matrix* red = &(img->red_channel);
    returnPixel.r = *Matrix_at(red, row, column);
    
    const Matrix* green = &(img->green_channel);
    returnPixel.g = *Matrix_at(green, row, column);
    
    const Matrix* blue = &(img->blue_channel);
    returnPixel.b = *Matrix_at(blue, row, column);
    
    return returnPixel;
    
    //pretty sure this is right

}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets the pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image* img, int row, int column, Pixel color) {
    assert(0 <= row && row < Image_height(img));
    assert(0 <= column && column < Image_width(img));
    
    //int index = (row * img->width) + column;
    Matrix* red = &(img->red_channel);
    //red->data[index] = color.r;
    //color.r = *Matrix_at(red, row, column);
    *Matrix_at(red, row, column) = color.r;
    
   
    
    Matrix* green = &(img->green_channel);
    //green->data[index] = color.g;
    //color.g = *Matrix_at(green, row, column);
    *Matrix_at(green, row, column) = color.g;
    
    Matrix* blue = &(img->blue_channel);
    //blue->data[index] = color.b;
    //color.b = *Matrix_at(blue, row, column);
    *Matrix_at(blue, row, column) = color.b;
    
    //pretty sure this is right
}

// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image* img, Pixel color) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            *Matrix_at(&img->red_channel, i, j) = color.r;
            *Matrix_at(&img->green_channel, i, j) = color.g;
            *Matrix_at(&img->blue_channel, i, j) = color.b;
            
        }
    }
}
