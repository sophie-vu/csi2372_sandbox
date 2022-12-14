#define MAX_SIZE 1080
#define MAX_INTENSITY 4095
#define MAX_MONOCHROME_INTENSITY 255

class Image {
    protected:
    int** pixels;
    int size, intensity;
    public:
    Image();
    ~Image();
    Image(int, int);
    int getSize();
    int getIntensity();
    friend Image operator-(Image&, Image&);
    friend Image operator+(Image&, Image&);
    void operator++();
    void operator--();
    bool sub_image(Image&);
};

class Monochrome : public Image {
    Monochrome();
    Monochrome(int, int);
    friend Monochrome operator+(Monochrome&, Monochrome&);
};