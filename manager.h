/**
 *
 * @file loader.h
 * @author antoine richard
 * @date 2022-06-10
 * @brief Contains manager class
 * 
 */

//
// Define guards
#ifndef MANAGER_H
#define MANAGER_H

#include "storage_type.h"
#include "loader.h"
#include "calculation.h"
#include "writer.h"

/**
 * @brief Class that create the right object depending on the context
 * 
 */
class manager
{

public:
    /**
     * @brief Construct a new manager object
     * 
     */
    manager();

    /**
     * @brief Create the right storage type object
     * 
     * @return storage_type the created storage object
     */
    storage_type make_storage();

    /**
     * @brief Create the right loader type object
     * 
     * @return loader the created loader object
     */
    loader make_reader();

    /**
     * @brief Create the right calculation type object
     * 
     * @return calculation the created calculation object
     */
    calculation make_calculation();

    /**
     * @brief create the right writer type object
     * 
     * @return writer the created writer object
     */
    writer make_writer();

};



#endif // MANAGER_H
