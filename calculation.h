/**
 * @file calculation.h
 * @author antoine richard
 * @date 2022-06-03
 * @brief Contains all class needed to make calculations on storage_type
 * 
 * 
 */
 
 //
// Define guards
#ifndef CALCULATION_H
#define CALCULATION_H

/**
 * @brief Abstract class (pure virtual) that define the behavior of a calculation class
 * 
 */
class calculation { // pure virtual
};

/**
 * @brief Class that calculate the average of storage_type
 * 
 */
class average : public calculation{

};

/**
 * @brief Class that calculate the rolling_average on storage_type
 * 
 */
class rolling_average{

};

#endif // CALCULATION_H
