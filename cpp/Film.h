#ifndef FILM_H
#define FILM_H
#include "Video.h"

/**
 * @class Film
 * @brief A class representing a film with chapters, derived from Video.
 *
 * This class extends the Video class to support films with chapters,
 * providing methods to manage chapter information and serialization.
 */
class Film : public Video
{
    friend class MediaManager;
private:
    unsigned int* chapters {};      ///< Array storing durations of each chapter
    unsigned int nb_chapters {};    ///< Number of chapters in the film

    /**
     * @brief Default constructor (private).
     */
    Film(){};
    
    /**
     * @brief Parameterized constructor (private).
     * 
     * @param name Film name
     * @param path File path
     * @param duration Total duration
     * @param chapters Array of chapter durations
     * @param nb_chapters Number of chapters
     */
    Film(string name, string path, unsigned int duration, 
        unsigned int const* chapters, unsigned int nb_chapters);
    
    /**
     * @brief Copy constructor (private).
     * @param from Film to copy from
     */
    Film(const Film& from);

public:
    /**
     * @brief Assignment operator.
     * @param from Film to assign from
     * @return Reference to the assigned film
     */
    Film& operator=(const Film& from);

    /**
     * @brief Destructor.
     */
    ~Film();

    /**
     * @brief Sets chapter information.
     * @param chapters Array of chapter durations
     * @param nb_chapters Number of chapters
     */
    void set_chapters(unsigned int const* chapters, unsigned int nb_chapters);

    /**
     * @brief Gets chapter durations.
     * @return Pointer to chapter durations array
     */
    const unsigned int* get_chapters() const;

    /**
     * @brief Gets number of chapters.
     * @return Number of chapters
     */
    unsigned int get_nb_chapters() const;

    /**
     * @brief Displays film information.
     * @param out Output stream
     */
    void disp(ostream& out) const override;
    
    /**
     * @brief Gets class name.
     * @return "Film"
     */
    string get_class_name() const override;

    /**
     * @brief Serializes chapter information.
     * @param f Output stream
     */
    void serial_chapters(ostream& f) const;

    /**
     * @brief Deserializes chapter information.
     * @param f Input stream
     */
    void deserial_chapters(istream& f);

    /**
     * @brief Serializes film data.
     * @param f Output stream
     */
    void write(ostream& f) const override;
    
    /**
     * @brief Deserializes film data.
     * @param f Input stream
     */
    void read(istream& f) override;
};

#endif