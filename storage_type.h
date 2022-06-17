#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

#include <vector>


class storage_type { // pure virtual
    /* Declarations */

public :

    //add element
    virtual void push_back();

    //delete one element
    virtual void pop_element();

    //get an iterator on the storage
    virtual void iterator();


    /**
     * @brief Display data of the list into the standard output
     *
     */
    virtual void print_data()const;
    //TODO histoire d'opérateur poto

};
// list_storage, vector_storage inherit from storage_type



/**
 * @class list_element
 * @brief Element of a chained list that contains a double value and is linked with previous and next values of the list :
 * - if previous element is null : the element is the list head
 * - if next element is null : the element is the list tail
 *
 */
class list_element {
    /**
     * @brief element value
     *
     */
    double _value;

    /**
     * @brief pointer to the previous list element
     *
     */
    list_element *_prev;

    /**
     * @brief pointer to the next list element
     *
     */
    list_element *_next;

public:
    /**
     * @brief Construct a new list element
     *
     * @param v the double value
     * @param p pointer to the previous element
     * @param n pointer to the next element
     */
    list_element(double v=0.0, list_element *p=nullptr, list_element *n=nullptr):
        _value(v), _prev(p), _next(n) {}

    /**
     * @brief Destroy the list element
     *
     */
    ~list_element() {}

    /**
     * @brief Get the next list element
     *
     * @return list_element*
     */
    list_element *get_next() {return _next;}

    /**
     * @brief Set the next list element
     *
     * @param n the new element of the list that will be insert after the current
     * element
     */
    void set_next(list_element *n) {_next = n;}

    /**
     * @brief Get the previous list element
     *
     * @return list_element*
     */
    list_element *get_prev() {return _prev;}

    /**
     * @brief Set the previous list element
     *
     * @param n the new element of the list that will be insert before the current
     * element
     */
    void set_prev(list_element *n) {_prev = n;}

    /**
     * @brief Get the element value
     *
     * @return double
     */
    double get_value()const {return _value;}

    /**
     * @brief Set the element value
     *
     * @param v the new double value
     */
    void set_value(double v) {_value = v;}
};

/**
 * @class values_list
 * @brief Provide all services to manage a chained list of list_element
 *
 */
class values_list {
    /**
     * @brief the first current element of the list
     *
     */
    list_element *_head;

    /**
     * @brief the last current element of the list
     *
     */
    list_element *_tail;

public:
    /**
     * @brief Construct a new values list object
     *
     */
    values_list(): _head(nullptr), _tail(nullptr) {}

    /**
     * @brief Copy construct of values list
     *
     * @param other the list that will be copied
     */
    values_list(const values_list &other);

    /**
     * @brief Destroy the values list object
     *
     */
    ~values_list() {clear();}

    /**
     * @brief Overload assignment operator : the current list will
     * replace its elements by new elements with same values as the list passed in parameter.
     *
     * @param other the reference list
     * @return values_list& the current list
     */
    values_list &operator=(const values_list &other);

    /**
     * @brief Remove all elements from the list
     *
     */
    void clear();

    /**
     * @brief Add new element at the end of the list with the value passed in parameter
     *
     * @param v the value of the new element
     */
    void push_back(double v);

    /**
     * @brief Remove the head of the list
     *
     */
    void pop_element();

    /**
     * @brief Get current list size
     *
     * @return size_t
     */
    size_t size()const;

    /**
     * @brief Get the double value at position
     *
     * @param position
     * @return double
     */
    double get_value(size_t position)const;

    /**
     * @brief Sort the list depending on the parameter value.
     * If parameter is <code>true</code> : ascending
     * If parameter is <code>false</code> : descending
     *
     * @param ascending the sort direction
     */
    void sort_list(bool ascending);
};



class list_storage : public storage_type{
    /**
     * @brief values list in which the data will be stored
     *
     */
    values_list _values;
public:
    /**
     * @brief Construct a new data list object
     *
     */
    list_storage();

    /**
     * @brief Copy construct of data list
     *
     * @param other the data list that will be copied
     */
    list_storage(const list_storage &other);

    /**
     * @brief Destroy the data list object
     *
     */
    ~list_storage() {_values.clear();}

    /**
     * @brief Display data of the list into the standard output
     *
     */
    void print_data()const;
};

class vector_storage : public storage_type{
    std::vector<double> _table;

public:
    /**
     * @brief Construct a new data table object
     *
     */
    vector_storage();

    /**
     * @brief Destroy the data table object
     *
     */
    ~vector_storage() {}


    /**
     * @brief Display data of the list into the standard output
     *
     */
    void print_data()const;
};


#endif // STORAGE_TYPE_H
