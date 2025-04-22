#include "MultiMedia.h"
using namespace std;

/**
 * @brief Default constructor for the MultiMedia class.
 * Initializes a MultiMedia object with empty name and path.
 */
MultiMedia::MultiMedia() {};

/**
 * @brief Parameterized constructor for the MultiMedia class.
 * 
 * @param name The name of the multimedia object.
 * @param path The file path of the multimedia object.
 */
MultiMedia::MultiMedia(string name, string path) : 
    name{name}, path{path} {}; 

/**
 * @brief Destructor for the MultiMedia class.
 */
MultiMedia::~MultiMedia() {};

/**
 * @brief Gets the name of the multimedia object.
 * 
 * @return The name of the multimedia object as a string.
 */
string MultiMedia::get_name() const {
    return this->name; 
}

/**
 * @brief Gets the path of the multimedia object.
 * 
 * @return The file path of the multimedia object as a string.
 */
string MultiMedia::get_path() const {
    return this->path; 
}

/**
 * @brief Sets the name of the multimedia object.
 * 
 * @param name The new name to set for the multimedia object.
 */
void MultiMedia::set_name(string name) {
    this->name = name; 
}

/**
 * @brief Sets the path of the multimedia object.
 * 
 * @param path The new file path to set for the multimedia object.
 */
void MultiMedia::set_path(string path) {
    this->path = path; 
}

/**
 * @brief Displays the basic information of the multimedia object.
 * 
 * Outputs the name and path of the multimedia object to the given output stream.
 * 
 * @param out The output stream where the information will be displayed.
 */
void MultiMedia::disp(ostream & out) const {
    out << "name is : " << this->get_name() << "\npath is : "  
    << this->get_path() << endl; 
}

/**
 * @brief Writes the multimedia object's data to an output stream.
 * 
 * Serializes the name and path of the multimedia object to the given output stream.
 * 
 * @param f The output stream where the data will be written.
 */
void MultiMedia::write(ostream & f) const {
    f << this->name << '\n' << this->path << endl;
}

/**
 * @brief Reads the multimedia object's data from an input stream.
 * 
 * Deserializes the name and path of the multimedia object from the given input stream.
 * 
 * @param f The input stream from which the data will be read.
 */
void MultiMedia::read(istream & f) {
    f >> name;
    f >> path;
}