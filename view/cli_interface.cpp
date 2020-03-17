#include <string>
#include <iostream>
#include "cli_interface.h"
#include "../controller/command_parser.h"
#include "../controller/commandfactory.h"


void CLI_Interface::run_DNA_Analyzer() {
    Command_Parser cmd;
    std::vector<std::string> command_container;
    CommandFactory cmdFactory;
    cmdFactory.CommandFactory_init();

    while (1) {
        std::string command_line;
        std::cout << "> cmd >>> ";
        std::getline(std::cin, command_line);
        command_container = cmd.command_parser(command_line);

        if (command_container[0] == "quit") {
            break;
        }

        Command *command = cmdFactory.commandFactory[command_container[0]];
        command->arguments_parser(command_container);
    }

}