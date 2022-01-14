#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "DataFilter.h"

int main() {
    const char LINE_DELIM{'\n'};
    const std::streamsize MAX_LINE_SIZE{std::numeric_limits<std::streamsize>::max()};

    const std::string DELIM_BEFORE{"\n"};
    const std::string DELIM_AFTER{"Civil War (Union)"};
    const std::string INPUT_FILE{"./input_converted_file.txt"};

    DataFilter df(INPUT_FILE, DELIM_AFTER);
    std::vector<std::string> names = df.filter_by_delimiter();

    for (auto name : names) {
        std::cout << name << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Entries count: " << names.size() << std::endl;

    return 0;
}
