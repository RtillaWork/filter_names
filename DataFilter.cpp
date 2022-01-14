//
// Created by n on 2022-01-14.
//

#include "DataFilter.h"


std::vector<std::string> DataFilter::filter_by_delimiter() const {
    return filter_by_delimiter(input_file_name_, delim_after_);
}

std::vector<std::string>
DataFilter::filter_by_delimiter(const std::string &input_file_name, const std::string &delim_after) const {
    std::ifstream infile(input_file_name);

    std::vector<std::string> names{};
    if (!infile.is_open()) {
        std::cout << "Failed to open file." << std::endl;

    } else {
        std::cout << "Successfully opened file " << input_file_name << std::endl;
        for (std::string line{}, delim{}; std::getline(infile, line), std::getline(infile, delim);) {
            if (delim_after == delim) {
                names.push_back(line);

//                  std::cout << line << std::endl; //DEBUG
            }
        }
    }

//    std::cout << names.size() << std::endl; //DEBUG

    return names;
}

long DataFilter::count_occurences(const std::string &input_file_name, const std::string &delim_after) const {
    std::ifstream infile(input_file_name);

    long count {};
    if (!infile.is_open()) {
        std::cout << "Failed to open file." << std::endl;

    } else {
        std::cout << "Successfully opened file " << input_file_name << std::endl;
        for (std::string delim{};  std::getline(infile, delim);) {
            if (delim_after == delim) {
                ++count;
//                  std::cout << line << std::endl; //DEBUG
            }
        }
    }

//    std::cout << names.size() << std::endl; //DEBUG

    return count;
}
std::vector<std::string> DataFilter::filter_by_delimiter_verbose() const {
    long expected_count = count_occurences(input_file_name_, delim_after_);
    std::vector<std::string> names = filter_by_delimiter(input_file_name_, delim_after_);

    std::cout << "Expected count by delimiter: `" << delim_after_ << "`: " << expected_count << std::endl;
    std::cout << "Found relevant: " << names.size() << " lines. " << std::endl;
    std::cout << "Count is equal: " <<  std::boolalpha << (expected_count == names.size()) << std::endl;



}
