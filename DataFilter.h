//
// Created by n on 2022-01-14.
//

#ifndef FILTER_NAMES_DATAFILTER_H
#define FILTER_NAMES_DATAFILTER_H


#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class DataFilter {
private:
    const std::string &input_file_name_;
    const std::string &delim_after_;

//    long lines_found_count_{0};
//    long delim_after_count_{0};

public:
    DataFilter(const std::string &inputFileName, const std::string &delimAfter) : input_file_name_(inputFileName),
                                                                                  delim_after_(delimAfter) {}

    std::vector<std::string> filter_by_delimiter() const;
    std::vector<std::string> filter_by_delimiter(const std::string &input_file_name, const std::string &delim_after) const;
    std::vector<std::string> filter_by_delimiter_verbose() const;

    long count_occurences(const std::string &input_file_name, const std::string &delim_after) const;

};


#endif //FILTER_NAMES_DATAFILTER_H
