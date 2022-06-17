#include "loader.h"

loader::loader()
{

}

void text_loader::load(const std::string &source) {
    _values.clear();
    ifstream f{source};
    if (f.is_open()) {
        array<char, 100> buffer;
        while (f.getline(&buffer[0], 100)) {
            _values.push_back(stold(string{buffer.data()}));
        }
    } else {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}

void bin_loader::load(const std::string &source) {
    _values.clear();
    ifstream f{source, std::ios::binary};
    if (f.is_open()) {
        double buffer;
        while (f.read(reinterpret_cast<char *>(&buffer), sizeof(double))) {
            _values.push_back(buffer);
        }
    } else  {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}
