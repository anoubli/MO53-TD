/**
 *
 * @file storage_type.h
 * @author antoine richard
 * @date 2022-06-10
 * @brief Contains storage classes
 * 
 */

//
// Define guards
#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

/**
 * @brief Abstract class (pure virtual) that define the behavior of a storage class
 * 
 */
class storage_type { // pure virtual
    /* Declarations */

public :

    /**
     * @brief add an element
     * 
     */
    virtual void push_back();

    /**
     * @brief Delete an element
     * 
     */
    virtual void pop_element();

    /**
     * @brief Get an iterator on the storage
     * 
     */
    virtual void iterator();

    //TODO histoire d'opérateur poto

};

/**
 * @brief Storage_type based on data_list
 * 
 */
class list_storage : public storage_type{

};

/**
 * @brief Storage_type based on vector
 * 
 */
class vector_storage : public storage_type{

};

#endif // STORAGE_TYPE_H
