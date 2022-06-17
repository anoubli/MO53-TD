#ifndef CALCULATION_H
#define CALCULATION_H
#include "storage_type.h"
#include <vector>


class calculation { // pure virtual

    virtual storage_type calculate();

}; // average, rolling_average, etc. inherit from calculation

class average : public calculation{

    /**
     * @brief Calculate the average of all data
     *
     * @return data_table with only one value : the calculation result
     */
    storage_type calculate();
};

class moving_average{

    // Computation (return new instances of data_table)
    /**
     * @brief Calculate a series of averages of different subsets of the full data set. The size of these subsets
     * are defined by the parameter. Each time a calculation is done, the oldest data of the current substet will
     * be remplace by the next value in the set.
     *
     * @param window_width the size of data substets
     * @return data_table new data table with all calculated averages
     */
    storage_type calculate(size_t window_width);
};

#endif // CALCULATION_H
