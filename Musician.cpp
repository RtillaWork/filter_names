//
// Created by n on 2022-01-14.
//

#include <sstream>
#include "Musician.h"

Musician::Musician() {}

Musician::Musician(const std::string &firstName, const std::string &lastName) : first_name_(firstName), middle_name_(),
                                                                                last_name_(lastName) {}

Musician::Musician(const std::string &firstName, const std::string &middleName, const std::string &lastName)
        : first_name_(firstName), middle_name_(middleName), last_name_(lastName) {}


Musician::Musician(const std::string &datum) {
    std::string fn{MISSING_DATA_PLACEHOLDER},
            mn{},
            ln{MISSING_DATA_PLACEHOLDER};
    std::string::size_type beg_pos{0};
    std::string::size_type end_pos{0};

    // Case of empty string
    if (datum.empty()) {
        Musician(fn, mn, ln);
    }

    // Case of ELEMENTS_SEP-free string: assume then it is just last_name
    if ((end_pos = datum.find_first_of(ELEMENTS_SEP)) == std::string::npos) {
        ln = datum;
        Musician(fn, mn, ln);
    }

    // Case string is LASTNAME, [i.n.i.t.i.a.l.s.] FIRSTNAME
    if ((end_pos = datum.find_first_of(LAST_NAME_INDICATOR)) != std::string::npos) {
        ln = datum.substr(beg_pos, end_pos);
        beg_pos = end_pos + 1;

        if ((end_pos = datum.find_first_of(ELEMENTS_SEP)) != std::string::npos) {
            mn = datum.substr(beg_pos, end_pos);
            fn = datum.substr(end_pos + 1, datum.size());


        } else {
            fn = datum.substr(end_pos + 1, datum.size());
        }
        Musician(fn, mn, ln);

    } // if

    // Case string is FIRSTNAME LASTNAME
    if ((end_pos = datum.find_first_of(ELEMENTS_SEP)) != std::string::npos) {
        fn = datum.substr(beg_pos, end_pos);
        beg_pos = end_pos + 1;

        if ((end_pos = datum.find_first_of(ELEMENTS_SEP)) == std::string::npos) {
            ln = datum.substr(beg_pos, datum.size());
        }
        Musician(fn, mn, ln);
    } // if
} // Musician::Musician(...)

bool Musician::operator==(const Musician &rhs) const {
    return first_name_ == rhs.first_name_ &&
           middle_name_ == rhs.middle_name_ &&
           last_name_ == rhs.last_name_;
}

bool Musician::operator!=(const Musician &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Musician &musician) {
    os << "first_name_: " << musician.first_name_ << " middle_name_: " << musician.middle_name_ << " last_name_: "
       << musician.last_name_;
    return os;
}

bool Musician::operator<(const Musician &rhs) const {
    if (first_name_ < rhs.first_name_)
        return true;
    if (rhs.first_name_ < first_name_)
        return false;
    if (middle_name_ < rhs.middle_name_)
        return true;
    if (rhs.middle_name_ < middle_name_)
        return false;
    return last_name_ < rhs.last_name_;
}

bool Musician::operator>(const Musician &rhs) const {
    return rhs < *this;
}

bool Musician::operator<=(const Musician &rhs) const {
    return !(rhs < *this);
}

bool Musician::operator>=(const Musician &rhs) const {
    return !(*this < rhs);
}

Musician::~Musician() {

}

const std::string &Musician::getFirstName() const {
    return first_name_;
}

void Musician::setFirstName(const std::string &firstName) {
    first_name_ = firstName;
}

const std::string &Musician::getMiddleName() const {
    return middle_name_;
}

void Musician::setMiddleName(const std::string &middleName) {
    middle_name_ = middleName;
}

const std::string &Musician::getLastName() const {
    return last_name_;
}

void Musician::setLastName(const std::string &lastName) {
    last_name_ = lastName;
}
