#ifndef PHOTO_H
#define PHOTO_H
#include "MultiMedia.h"

/**
 * @class Photo
 * @brief A class representing a photo file, derived from the MultiMedia base class.
 * 
 * This class provides methods to set and get the width and height of the photo, 
 * display its details, and run the photo using an external player (mpv).
 */
class Photo : public MultiMedia
{
    friend class MediaManager;
private:
    double width {};  ///< Width of the photo in pixels.
    double height {}; ///< Height of the photo in pixels.

    /**
     * @brief Default constructor for the Photo class.
     * Initializes the photo with default values.
     */
    Photo(){}
    
    /**
     * @brief Parameterized constructor to initialize a Photo object.
     * 
     * @param name The name of the photo.
     * @param path The file path to the photo.
     * @param width The width of the photo in pixels.
     * @param height The height of the photo in pixels.
     */
    Photo(string name, string path, double width, double height) : 
    MultiMedia(name, path), width{width}, height{height} {}

    
public:
    /**
     * @brief Destructor for the Photo class.
     */
    ~Photo(){
        cout<< " A Photo classe has been destroyed U Monster"<<endl; 
    };
    /**
     * @brief Sets the width of the photo.
     * 
     * @param width The width to set for the photo in pixels.
     */
    void set_width(double width) {
        this->width = width;
    }

    /**
     * @brief Gets the width of the photo.
     * 
     * @return The width of the photo in pixels.
     */
    double get_width() const {
        return this->width;
    }

    /**
     * @brief Sets the height of the photo.
     * 
     * @param height The height to set for the photo in pixels.
     */
    void set_height(double height) {
        this->height = height;
    }

    /**
     * @brief Gets the height of the photo.
     * 
     * @return The height of the photo in pixels.
     */
    double get_height() const {
        return this->height;
    }

    /**
     * @brief Displays the details of the photo including name, path, width, and height.
     * 
     * This function overrides the disp() function in the MultiMedia base class.
     * 
     * @param out The output stream to which the details are written.
     */
    void disp(ostream & out) const override {
        MultiMedia::disp(out);  
        out << "\nwidth : " << this->get_width() <<
            "\nheight : " << this->get_height() << endl;
    }

    /**
     * @brief Runs the photo using an external player (mpv).
     * 
     * This function overrides the run() function in the MultiMedia base class.
     * It constructs a system command to run the mpv media player with the photo's path.
     */
    void run() const override {
        string command = "mpv --keep-open"; 
        command = command + " " + this->get_path() + " &"; 
        system(command.data()); 
    }

    string get_class_name()const override{
        return "Photo";
    }

    void write(ostream & f) const override{
        f << "Photo"<<'\n';
        MultiMedia::write(f);
        f << width << '\n' << height << endl ;
    }

    void read(istream & f){
        MultiMedia::read(f);
        f >> width >> height;}
};

#endif
