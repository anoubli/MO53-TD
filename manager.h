#ifndef MANAGER_H
#define MANAGER_H

#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

class manager
{





public:
    manager();

    //create the right storage type object
    storage_type make_storage(std::string param);

    //create the right loader type object
    loader make_reader(std::string param);

    //create the right calculation type object
    calculation make_calculation(std::string param);

    //create the right writer type object
    writer make_writer(std::string param);

};



#endif // MANAGER_H
