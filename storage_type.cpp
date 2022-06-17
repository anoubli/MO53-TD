#include "storage_type.h"
#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

values_list::values_list(const values_list &other) {
    list_element *ptr = other._head;
    while (ptr) {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
}

values_list &values_list::operator=(const values_list &other) {
    clear();
    list_element *ptr = other._head;
    while (ptr) {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
    return *this;
}

void values_list::clear() {
    list_element *tmp = _head;
    while (tmp) {
        _head = tmp->get_next();
        delete tmp;
        tmp = _head;
    }
    _head = _tail = nullptr;
}

void values_list::push_back(double v) {
    if (!_head) {
        _head = new list_element(v);
        _tail = _head;
    } else {
        _tail->set_next(new list_element(v, _tail));
        _tail = _tail->get_next();
    }
}

void values_list::pop_element() {
    if (_head) {
        list_element *tmp = _head->get_next();
        delete _head;
        _head = tmp;
        if (tmp) {
            tmp->set_prev(nullptr);
        } else {
            _tail = _head; // both =nullptr
        }
    }
}

size_t values_list::size() const {
    size_t s = 0;
    list_element *ptr = _head;
    while (ptr) {
        ptr = ptr->get_next();
        ++s;
    }
    return s;
}

double values_list::get_value(size_t position) const {
    size_t pos = 0;
    list_element *ptr = _head;
    while (ptr) {
        if (pos == position)
            return ptr->get_value();
        ptr = ptr->get_next();
        ++pos;
    }
    // Error case: position out of bounds
}

void values_list::sort_list(bool ascending) { // Naive sort
    list_element *ptr = _head;
    while (ptr && ptr->get_next()) {
        list_element *min_element = ptr;
        list_element *cursor = ptr;
        while (cursor) {
            if (ascending && cursor->get_value() < min_element->get_value())
                min_element = cursor;
            else if (!ascending && cursor->get_value() > min_element->get_value())
                min_element = cursor;
            cursor = cursor->get_next();
        }
        double tmp = ptr->get_value();
        ptr->set_value(min_element->get_value());
        min_element->set_value(tmp);
        ptr = ptr->get_next();
    }
}

list_storage::list_storage() {
}

list_storage::list_storage(const list_storage &other) {
    _values = other._values;
}

void list_storage::from_text(const std::string &source) {
    _values.clear();
    ifstream f{source};
    if (f.is_open()) {
        array<char, 100> buffer;
        while (f.getline(&buffer[0], 100)) {
            _values.push_back(stold(string{buffer.data()}));
        }
    } else {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}

void list_storage::from_binary(const std::string &source) {
    _values.clear();
    ifstream f{source, std::ios::binary};
    if (f.is_open()) {
        double buffer;
        while (f.read(reinterpret_cast<char *>(&buffer), sizeof(double))) {
            _values.push_back(buffer);
        }
    } else  {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}

void list_storage::to_text(const std::string &destination) {
    ofstream f{destination};
    if (f.is_open()) {
        for (size_t i=0; i<_values.size(); ++i) {
            f << _values.get_value(i) << endl;
        }
    }
}

void list_storage::to_binary(const std::string &destination) {
    ofstream f{destination, std::ios::binary};
    if (f.is_open()) {
        for (size_t i=0; i<_values.size(); ++i) {
            double val = _values.get_value(i);
            f.write(reinterpret_cast<const char *>(&val), sizeof(double));
        }
    } else  {
        throw ios_base::failure("File cannot be opened for writing.");
    }
}

void list_storage::print_data() const {
    for (size_t i=0; i<_values.size(); ++i) {
        cout << _values.get_value(i) << endl;
    }
}
