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
    std::stringstream fn{}, mn{}, ln{};




}

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
