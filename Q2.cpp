#include "Q2.h"
using namespace std;
// class Image {
//     int** pixels;
//     int size, intensity;
//     public:
//     Image();
//     Image(int, int);
//     int getSize();
//     int getIntensity();
//     void setIntensity(int);
//     friend Image operator-(Image&, Image&);
//     friend Image operator+(Image&, Image&);
//     void operator++();
//     void operator--();
//     bool sub_image(Image&);
// };

Image::Image() {
    pixels = new int*[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        pixels[i] = new int[MAX_SIZE];
        for (int j = 0; j < MAX_SIZE; j++) {
            pixels[i][j] = MAX_INTENSITY;
        }
    }
}

Image::Image(int newSize, int newIntensity) {
    if (newIntensity < 0) intensity = MAX_INTENSITY;
    if (newSize <= 0) size = MAX_SIZE;
    for (int i = 0; i < size; i++) {
        pixels[i] = new int[size];
        for (int j = 0; j < size; j++) {
            pixels[i][j] = newIntensity;
        }
    }
}

int Image::getSize() {
    return size;
}

int Image::getIntensity() {
    return intensity;
}

/**
 * @brief 
 * Case 1: If two images have the same size -> subtracts intensity of each pixel in the second image from the intensity of the pixel at the same position in the first image.
 * Note: The result pixel is a pixel with a 0 intensity if a pixel at a position in the second image has a higher intensity. 
 * Case 2: If the images do not have the same size, it just returns the first image.
 * 
 * @param img1 
 * @param img2 
 * @return Image 
 */
Image operator-(Image& img1, Image& img2) {
    if (img1.getSize() != img2.getSize()) return img1; // Case 2
    Image res = Image(img1.getSize(), 0); 
    int intensity1, intensity2;
    for (int i = 0; i < img1.getSize(); i++) {
        for (int j = 0; j < img1.getSize(); j++) {
            intensity1 = img1.pixels[i][j];
            intensity2 = img2.pixels[i][j];
            if (intensity2 > intensity1) {
                res.pixels[i][j] = 0;
            } else {
                res.pixels[i][j] = intensity1 - intensity2;
            }
        }
    }
    return res;
}


/**
 * @brief 
 * Case 1: If two images have the same size -> adds intensity of each pixel in the second image to the intensity of the pixel at the same position in the first image.
 * Case 2: If the images do not have the same size, it just returns the first image.
 * 
 * @param img1 
 * @param img2 
 * @return Image 
 */
Image operator+(Image& img1, Image& img2) {
    if (img1.getSize() != img2.getSize()) return img1; // Case 2
    Image res = Image(img1.getSize(), 0); 
    int intensity1, intensity2;
    for (int i = 0; i < img1.getSize(); i++) {
        for (int j = 0; j < img1.getSize(); j++) {
            intensity1 = img1.pixels[i][j];
            intensity2 = img2.pixels[i][j];
            res.pixels[i][j] = intensity1 + intensity2;
        }
    }
    return res;
}

void Image::operator++() {
    for (int i = 0; i < getSize(); i++) {
        for (int j = 0; j < getSize(); j++) {
            pixels[i][j]++;
        }
    }
}

void Image::operator--() {
    for (int i = 0; i < getSize(); i++) {
        for (int j = 0; j < getSize(); j++) {
            if (pixels[i][j] == 0) continue;
            else pixels[i][j]--;
        }
    }
}

/**
 * @brief Checks if the current image appears in part of the given image
 * 
 * @param parent 
 * @return true 
 * @return false 
 */
bool Image::sub_image(Image& parent) {
    return getSize() <= parent.getSize();
}

Image::~Image() {
    for (int i = 0; i < getSize(); i++) {
        delete[] pixels[i];
    }
    delete[] pixels;
    pixels = nullptr;
}

Monochrome::Monochrome(int newSize, int newIntensity) {
    if ((newIntensity < 0) || (newIntensity > 255)) intensity = MAX_MONOCHROME_INTENSITY;
    if (newSize <= 0) size = MAX_SIZE;
    for (int i = 0; i < size; i++) {
        pixels[i] = new int[size];
        for (int j = 0; j < size; j++) {
            pixels[i][j] = newIntensity;
        }
    }
}

Monochrome operator+(Monochrome& mn1, Monochrome& mn2) {
    if (mn1.getSize() != mn2.getSize()) return mn1; // Case 2
    Monochrome res = Monochrome(mn1.getSize(), 0); 
    int intensity1, intensity2;
    for (int i = 0; i < mn1.getSize(); i++) {
        for (int j = 0; j < mn1.getSize(); j++) {
            intensity1 = mn1.pixels[i][j];
            intensity2 = mn2.pixels[i][j];
            if (intensity1 + intensity2 > MAX_MONOCHROME_INTENSITY) {
                res.pixels[i][j] = (intensity1 + intensity2) % MAX_MONOCHROME_INTENSITY;
            } else {
                res.pixels[i][j] = intensity1 + intensity2;
            }
        }
    }
    return res;
}