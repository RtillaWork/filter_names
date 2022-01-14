//
// Created by n on 2022-01-14.
//

#ifndef FILTER_NAMES_MUSICIAN_H
#define FILTER_NAMES_MUSICIAN_H


#include <string>
#include <ostream>

class Musician {
private:
    std::string first_name_;
    std::string middle_name_;
    std::string last_name_;

public:
    Musician();

    Musician(const std::string &firstName, const std::string &middleName, const std::string &lastName);

    Musician(const std::string &firstName, const std::string &lastName);

    bool operator==(const Musician &rhs) const;

    bool operator!=(const Musician &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Musician &musician);

    bool operator<(const Musician &rhs) const;

    bool operator>(const Musician &rhs) const;

    bool operator<=(const Musician &rhs) const;

    bool operator>=(const Musician &rhs) const;

    virtual ~Musician();

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getMiddleName() const;

    void setMiddleName(const std::string &middleName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

};


#endif //FILTER_NAMES_MUSICIAN_H
