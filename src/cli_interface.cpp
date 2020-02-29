#include <string>
#include <iostream>
#include "cli_interface.h"
#include "command_parser.h"
#include "dna_container.h"

#include "commandfactory.h"

void CLI_Interface::run_DNA_Analyzer() {
    Command_Parser cmd;
    std::vector<std::string> command_container;
    CommandFactory cmdFactory;
    DNA_container &container = DNA_container::getInstance();


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





/*
if (command_container[0] == "new") {
    DNASequence_Info dna = creator.new_command(command_container[1], command_container[2]);
    std::cout << "[" << dna.getId() << "]" << " " << dna.getNucleotides() << " " << dna.getName() << '\n';

} else if (command_container[0] == "save") {
    dna_stream.save(command_container[2].c_str(), command_container[1]);

} else if (command_container[0] == "load") {
    std::string dna_data = dna_stream.load(command_container[1].c_str());
    DNASequence_Info dna = creator.new_command(dna_data, command_container[2]);
    std::cout << "[" << dna.getId() << "]" << " " << dna.getNucleotides() << " " << dna.getName() << '\n';

} else if (command_container[0] == "quit") {
    break;
}*/
