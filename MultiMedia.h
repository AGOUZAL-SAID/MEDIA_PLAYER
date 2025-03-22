#ifndef MULTI_MEDIA_H
#define MULTI_MEDIA_H

#include <string>
#include <ostream>
#include <list>

using namespace std;

/**
 * @class MultiMedia Abstract
 * @brief Represents a multimedia file.
 *
 * This class manages a multimedia file by storing its name
 * and file path. It provides methods to modify and display these attributes.
 */
class MultiMedia
{
private:
    string name{}; ///< Name of the multimedia file.
    string path{}; ///< File path of the multimedia file.

public:
    /**
     * @brief Default constructor.
     */
    MultiMedia();

    /**
     * @brief Constructor with parameters.
     * @param name Name of the multimedia file.
     * @param path File path of the multimedia file.
     */
    MultiMedia(string name, string path);

    /**
     * @brief Destructor.
     */
    ~MultiMedia();

    /**
     * @brief Gets the name of the multimedia file.
     * @return The file name as a string.
     */
    string get_name() const;

    /**
     * @brief Gets the file path of the multimedia file.
     * @return The file path as a string.
     */
    string get_path() const;

    /**
     * @brief Sets a new name for the multimedia file.
     * @param name The new file name.
     */
    void set_name(string name);

    /**
     * @brief Sets a new file path for the multimedia file.
     * @param path The new file path.
     */
    void set_path(string path);

    /**
     * @brief Displays multimedia file information.
     * @param out Output stream where the information is printed.
     */
    virtual void disp(ostream &out) const;

    /**
     * @brief Runs the file of the multimedia file.
     */
    virtual void run() const = 0;
};

#endif // MULTI_MEDIA_H
