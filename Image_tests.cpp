// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;    //can use this to input to an input string
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());
    

  delete img; // delete the Image
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

TEST(test_init_important) {
    Image *img = new Image;
    string example;
    example = "P3\n2 2\n255\n255 0 0 0 255 0 \n0 0 255 255 255 255 \n";
    istringstream input(example);
    Image_init(img, input);
    
   //idk just trying this
    
    ostringstream s;
  
    Image_print(img, s);
    string test = s.str();
    assert(example == test);
    //computer knows how to compare string not stream objects
    //want to make sure whatever is printed into S matches original Example string
    
    delete img;
}

TEST(test_image_width_height) {
    Image *img = new Image; // create an Image in dynamic memory

    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    const Pixel white = {255, 255, 255};

    Image_init(img, 2, 2);
    Image_set_pixel(img, 0, 0, red);
    Image_set_pixel(img, 0, 1, green);
    Image_set_pixel(img, 1, 0, blue);
    Image_set_pixel(img, 1, 1, white);
    
    assert(Image_width(img) == 2);
    assert(Image_height(img) == 2);
    
    delete img;
}

TEST(test_image_get_set_pixel) {
    Image *img = new Image; // create an Image in dynamic memory

    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    const Pixel white = {255, 255, 255};

    Image_init(img, 2, 2);
    Image_set_pixel(img, 0, 0, red);
    Image_set_pixel(img, 0, 1, green);
    Image_set_pixel(img, 1, 0, blue);
    Image_set_pixel(img, 1, 1, white);
    
    Image_set_pixel(img, 1, 0, red);
    
    Pixel one = Image_get_pixel(img, 0, 0);
    Pixel two = Image_get_pixel(img, 1, 0);
    
    assert(Pixel_equal(one, two));
    delete img;
}

TEST(test_image_fill) {
    Image *img = new Image; // create an Image in dynamic memory

    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    const Pixel white = {255, 255, 255};

    Image_init(img, 2, 2);
    Image_set_pixel(img, 0, 0, red);
    Image_set_pixel(img, 0, 1, green);
    Image_set_pixel(img, 1, 0, blue);
    Image_set_pixel(img, 1, 1, white);
    
    Pixel blue1 = {0, 0, 255};
    Image_fill(img, blue);
    assert(Image_get_pixel(img, 0, 0).b == blue1.b);
    assert(Image_get_pixel(img, 0, 0).g == blue1.g);
    assert(Image_get_pixel(img, 0, 0).r == blue1.r);
    
    assert(Image_get_pixel(img, 0, 1).b == blue1.b);
    assert(Image_get_pixel(img, 0, 1).g == blue1.g);
    assert(Image_get_pixel(img, 0, 1).r == blue1.r);
    
    assert(Image_get_pixel(img, 1, 0).b == blue1.b);
    assert(Image_get_pixel(img, 1, 1).b
           == blue1.b);
    delete img;
}



// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
