#include <sstream>
#include "command_parser.h"



std::vector<std::string> Command_Parser::command_parser(std::string command) {
    std::vector<std::string> command_container;
    std::istringstream ss(command);
    while (ss) {
        std::string command_word;
        ss >> command_word;
        command_container.push_back(command_word);
    }

    return command_container;
}