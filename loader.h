#ifndef LOADER_H
#define LOADER_H

#include <string>

class loader { // pure virtual

    virtual void load(const std::string &source);
}; // as for storage_type, text and bin loaders are children of loader

class text_loader : public loader{

public :
    text_loader();
    ~text_loader();
    // Input methods
    /**
     * @brief Replace current data by text file values
     *
     * @param source text file name
     */
    void load(const std::string &source);

};

class bin_loader : public loader{

public:
    /**
     * @brief Replace current data by binary file values
     *
     * @param source binary file name
     */
    void load(const std::string &source);

};

#endif // LOADER_H
