#ifndef WRITER_H
#define WRITER_H


#include <string>

class writer { // pure virtual

public:
    writer();
    ~writer();
    virtual void write(const std::string &destination);
}; // any output (file - text or bin, screen) inherit from this one

class text_writer : public writer {

public:
    // Output methods
    /**
     * @brief Write all the data into given text file
     *
     * @param destination text file name
     */
    void write(const std::string &destination);
};

class bin_writer : public writer{

public:
    /**
     * @brief Write all the data into given binary file
     *
     * @param destination text file name
     */
    void write(const std::string &destination);

};





#endif // WRITER_H
