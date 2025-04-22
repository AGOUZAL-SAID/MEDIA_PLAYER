#include "Film.h"

/**
 * @brief Constructs a Film object with specified parameters.
 * 
 * @param name Name of the film
 * @param path File path of the film
 * @param duration Total duration of the film
 * @param chapters Array of chapter durations
 * @param nb_chapters Number of chapters
 */
Film::Film(string name, string path, unsigned int duration, 
    unsigned int const* chapters, unsigned int nb_chapters):
    Video::Video(name, path, duration), nb_chapters{nb_chapters} {
        set_chapters(chapters, nb_chapters);
    };

/**
 * @brief Destructor for Film class.
 * 
 * Releases memory allocated for chapters array.
 */
Film::~Film() { 
    delete[] chapters;
}

/**
 * @brief Sets the chapter durations for the film.
 * 
 * @param chapters Array of chapter durations
 * @param nb_chapters Number of chapters
 * @note Manages memory allocation/deallocation for chapters array
 */
void Film::set_chapters(unsigned int const* chapters, unsigned int nb_chapters) {
    delete[] this->chapters; 
    if (!chapters) {
        this->chapters = nullptr;
        this->nb_chapters = 0;
        return;
    }
    this->chapters = new unsigned int[nb_chapters];
    for (unsigned int i = 0; i < nb_chapters; i++) {
        this->chapters[i] = chapters[i];
    } 
    this->nb_chapters = nb_chapters;
}

/**
 * @brief Gets the chapter durations array.
 * 
 * @return const pointer to chapter durations array
 */
const unsigned int* Film::get_chapters() const {
    return chapters;    
}

/**
 * @brief Gets the number of chapters.
 * 
 * @return Number of chapters
 */
unsigned int Film::get_nb_chapters() const {
    return nb_chapters;
}

/**
 * @brief Displays film information including chapters.
 * 
 * @param out Output stream to display to
 */
void Film::disp(ostream& out) const {
    Video::disp(out);
    out << "Chapters duration are: ";
    for (unsigned int i = 0; i < nb_chapters; ++i) {
        if (chapters==nullptr) break;
        out << chapters[i] << " ";
    }
    out << ", Number of chapters: " << nb_chapters << endl;
}

/**
 * @brief Copy constructor for Film class.
 * 
 * @param from Film object to copy from
 */
Film::Film(const Film& from) : Video::Video(from.get_name(), from.get_path(),
    from.get_duration()), nb_chapters{from.get_nb_chapters()} {
        this->chapters = new unsigned int[nb_chapters];
        for (unsigned int i = 0; i < nb_chapters; ++i) {
            if (!chapters) {
                this->chapters = nullptr;
                this->nb_chapters = 0;
                break;
            }
            this->chapters[i] = from.get_chapters()[i];
        }
    };

/**
 * @brief Assignment operator for Film class.
 * 
 * @param from Film object to assign from
 * @return Reference to the assigned Film object
 */
Film& Film::operator=(const Film& from) {
    Video::operator=(from);
    if (this->chapters) delete[] chapters;
    this->chapters = new unsigned int[nb_chapters];
    for (unsigned int i = 0; i < nb_chapters; ++i) {
        if (!chapters) {
            this->chapters = nullptr;
            this->nb_chapters = 0;
            break;
        }
        this->chapters[i] = from.get_chapters()[i];
    }
    return *this;
}

/**
 * @brief Gets the class name.
 * 
 * @return "Film" as string
 */
string Film::get_class_name() const {
    return "Film";
}

/**
 * @brief Serializes film data to output stream.
 * 
 * @param f Output stream to write to
 */
void Film::write(ostream& f) const {
    f << "Film" << '\n';
    MultiMedia::write(f);
    f << duration << '\n';
    f << nb_chapters << endl; 
    this->serial_chapters(f);
}

/**
 * @brief Serializes chapter durations to output stream.
 * 
 * @param f Output stream to write to
 */
void Film::serial_chapters(ostream& f) const {
    for (int64_t i = 0; i < nb_chapters; i++) {
        f << chapters[i] << '\n';
    }
}

/**
 * @brief Deserializes chapter durations from input stream.
 * 
 * @param f Input stream to read from
 */
void Film::deserial_chapters(istream& f) {
    chapters = new unsigned int[nb_chapters];
    for (int64_t i = 0; i < nb_chapters; i++) {
        unsigned int chapter;
        f >> chapter;
        chapters[i] = chapter;
    }
}

/**
 * @brief Deserializes film data from input stream.
 * 
 * @param f Input stream to read from
 */
void Film::read(istream& f) {
    Video::read(f);
    f >> nb_chapters;
    deserial_chapters(f);
}