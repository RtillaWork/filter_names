#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    const char LINE_DELIM{'\n'};
    const std::streamsize MAX_LINE_SIZE{std::numeric_limits<std::streamsize>::max()};

    const std::string DELIM_BEFORE{"\n"};
    const std::string DELIM_AFTER{"Civil War (Union)"};
    const std::string INPUT_FILE{"/home/n/Public/input_converted_file.txt"};

    std::ifstream infile(INPUT_FILE);

    if (!infile.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return 1;
    } else {
        std::cout << "Successfully opened file " << INPUT_FILE << std::endl;
    }

    std::vector<std::string> names{};
    int names_count {0};
    for (std::string line1{}, line2{}; std::getline(infile, line1), std::getline(infile, line2);) {
        if (DELIM_AFTER == line2) {
            names.push_back(line1);
            ++names_count;
        }
    }

    for (auto name : names) {
        std::cout << name << std::endl;
    }

    return 0;
}