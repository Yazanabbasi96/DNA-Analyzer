#ifndef DNA_ANALYZER_COMMANDFACTORY_H
#define DNA_ANALYZER_COMMANDFACTORY_H

#include <map>
#include <string>
#include "../model/command.h"

class CommandFactory {
public:

    CommandFactory() {}

    void CommandFactory_init();

    ~CommandFactory() {}

    std::map<std::string, Command*> commandFactory;

};


#endif //DNA_ANALYZER_COMMANDFACTORY_H
