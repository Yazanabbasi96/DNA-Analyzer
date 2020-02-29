
#ifndef DNA_ANALYZER_COMMAND_H
#define DNA_ANALYZER_COMMAND_H

#include <vector>
#include <string>

class Command {
public:

    virtual void arguments_parser(std::vector<std::string> args) = 0;

    virtual ~Command() = 0;
};




#endif //DNA_ANALYZER_COMMAND_H
