#ifndef VIDEO_H
#define VIDEO_H
#include "MultiMedia.h"

/**
 * @class Video
 * @brief A class representing a video file, derived from the MultiMedia base class.
 * 
 * This class provides methods to set and get the duration of the video, 
 * display its details, and run the video using an external player (mpv).
 */
class Video : public MultiMedia
{
private:
    unsigned int duration {}; ///< Duration of the video in seconds.

public:
    /**
     * @brief Default constructor for the Video class.
     * Initializes the video with default values.
     */
    Video(){}

    /**
     * @brief Parameterized constructor to initialize a Video object.
     * 
     * @param name The name of the video.
     * @param path The file path to the video.
     * @param duration The duration of the video in seconds.
     */
    Video(string name, string path, unsigned int duration) :
        MultiMedia(name, path), duration{duration} {}

    /**
     * @brief Destructor for the Video class.
     */
    ~Video(){};

    /**
     * @brief Sets the duration of the video.
     * 
     * @param duration The duration to set for the video in seconds.
     */
    void set_duration(unsigned int duration){
        this->duration = duration ; 
    }

    /**
     * @brief Gets the duration of the video.
     * 
     * @return The duration of the video in seconds.
     */
    unsigned int get_duration() const {
        return this->duration ; 
    }

    /**
     * @brief Displays the details of the video including name, path, and duration.
     * 
     * This function overrides the disp() function in the MultiMedia base class.
     * 
     * @param out The output stream to which the details are written.
     */
    void disp(ostream & out) const override {
        out << "name is : " << this->get_name() << "\npath is : "  
            << this->get_path() <<"\nduration : " << this->get_duration() << endl; 
    }

    /**
     * @brief Plays the video using an external player (mpv).
     * 
     * This function overrides the run() function in the MultiMedia base class.
     * It constructs a system command to run the mpv media player with the video's path.
     */
    void run() const override {
        string command = "mpv"; 
        command = command + " "  + this->get_path() + " &"; 
        system(command.data()); 
    }

};

#endif
