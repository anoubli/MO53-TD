#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

class process { // raw pointers may be improved
    storage_type *_storage;
    loader *_loader;
    calculation *_calc;
    writer *_writer;

public:
    process(storage_type *stor, loader *load, calculation *calc, writer *write): _storage(stor), _loader(load), _calc(calc), _writer(write) {};
    void execute(string path_to_file);
};

#endif // PROCESS_H
