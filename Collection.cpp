#include "Collection.h"

/**
 * @brief Constructs a Collection with the specified name
 * 
 * @param name The name to assign to the collection
 */
Collection::Collection(string name) : name{name} {};

/**
 * @brief Gets the name of the collection
 * 
 * @return string The name of the collection
 */
string Collection::get_name() const {
    return name;
}

/**
 * @brief Displays the collection information and its contents
 * 
 * Outputs the collection name followed by information about each
 * multimedia object in the collection.
 * 
 * @param out The output stream to write to
 */
void Collection::disp(ostream& out) const {
    out << "name of groupe is : " << name << endl;
    for (const auto& media : *this) {
        media->disp(out);  
    }
}

/**
 * @brief Serializes the collection to an output stream
 * 
 * Writes the collection data in a format that can be read back
 * by the read() method. First writes the collection type marker,
 * then the collection name.
 * 
 * @param f The output stream to write to
 */
void Collection::write(ostream& f) const {
    f << "Collection" << '\n';
    f << name << '\n';
}

/**
 * @brief Gets the class name identifier
 * 
 * @return string Always returns "Collection"
 */
string Collection::get_class_name() const {
    return "Collection";
}

/**
 * @brief Deserializes the collection from an input stream
 * 
 * Reads the collection name from the input stream. Assumes
 * the stream is properly formatted (as written by write()).
 * 
 * @param f The input stream to read from
 */
void Collection::read(istream& f) {
    f >> name;
}