#include "process.h"

void process::execute(std::string path_to_file)
{
    *_storage = _loader->load(path_to_file);
    _calc->calculation(_storage);
    _writer->write(_storage);
}
