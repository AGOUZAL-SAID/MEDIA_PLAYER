#ifndef COLLECTION_H
#define COLLECTION_H
#include "MultiMedia.h"

/**
 * @typedef MediaPtr
 * @brief Shared pointer to a MultiMedia object
 */
typedef std::shared_ptr<MultiMedia> MediaPtr;

/**
 * @class Collection
 * @brief A collection of multimedia objects
 * 
 * This class represents a named collection of multimedia items (photos, videos, films)
 * inheriting from std::list to provide container functionality. It supports serialization
 * and display of the collection contents.
 */
class Collection : public list<MediaPtr>
{
    friend class MediaManager;
private:
    string name {}; ///< Name of the collection

    /**
     * @brief Constructs a Collection with a given name
     * @param name Name of the collection
     */
    Collection(string name);

    /**
     * @brief Default constructor (private)
     */
    Collection(){};

public:
    /**
     * @brief Destructor
     */
    ~Collection(){};

    /**
     * @brief Gets the collection name
     * @return Name of the collection
     */
    string get_name() const;

    /**
     * @brief Gets the class name
     * @return "Collection" string
     */
    string get_class_name() const;

    /**
     * @brief Serializes the collection to an output stream
     * @param f Output stream to write to
     */
    void write(ostream& f) const;

    /**
     * @brief Deserializes the collection from an input stream
     * @param f Input stream to read from
     */
    void read(istream& f);

    /**
     * @brief Displays the collection contents
     * @param out Output stream to display to
     */
    void disp(ostream& out) const;
};

#endif