/**
 *
 * @file loader.h
 * @author antoine richard
 * @date 2022-06-10
 * @brief Contains loaders class
 * 
 */

//
// Define guards
#ifndef LOADER_H
#define LOADER_H

/**
 * @brief Abstract class (pure virtual) that define the behavior of a loader class
 * 
 */
class loader { // pure virtual
};

/**
 * @brief Class used to load data from text file
 * 
 */
class text_loader : public loader {

};

/**
 * @brief Class used to load data from binary file
 * 
 */
class bin_loader : public loader {

};

#endif // LOADER_H
