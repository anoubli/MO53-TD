/**
 *
 * @file factory.h
 * @author antoine richard
 * @date 2022-06-10
 * @brief Contains factories class
 * 
 */

//
// Define guards
#include "storage_type.h"
#include "loader.h"
#include "writer.h"
#include "calculation.h"

/**
 * @brief Factory class to whom we delegate the object creation
 * 
 */
class factory
{
    public:
    /**
     * @brief Construct a new factory object
     * 
     */
    factory();
    
    /**
     * @brief Destroy the factory object
     * 
     */
    ~factory();
    
    /**
     * @brief Create a storage object
     * 
     * @return storage_type* ptr to the created storage object
     */
    storage_type* storage_type_factory();
    
    /**
     * @brief Create a loader object
     * 
     * @return loader* ptr to the created loader object
     */
    loader* loader_factory();
    
    /**
     * @brief Create a writer object
     * 
     * @return writer* ptr to the created writer object
     */
    writer* writer_factory();
    
    /**
     * @brief Create a calculation object
     * 
     * @return calculation* ptr to the created calculation object
     */
    calculation* calculation_factory();

};