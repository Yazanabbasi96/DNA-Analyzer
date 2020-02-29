#include <iostream>
#include "dna_sequence_creater.h"
#include "dna_container.h"
#include "dna_sequence.h"


DNASequence_Info DNASequence_Creator::new_command(std::string dna,const std::string& name = "seq") {
    DNASequence new_dna(dna);
    DNASequence_Info *dna_seq = new DNASequence_Info(&new_dna,name);
    DNA_container &container = DNA_container::getInstance();
    container.dna_name_map[dna_seq->getName()] = dna_seq;
    container.dna_id_map[dna_seq->getId()] = dna_seq;

    std::cout << "[" << dna_seq->getId() << "]" << " " << " " << dna_seq->getName() << '\n';

    return *dna_seq;
}


void DNASequence_Creator::arguments_parser(std::vector<std::string> args) {
    std::cout<<"hellloooo";

    if (args.size() < 2) {
        std::cout << "Missing arguments" << "\n";
    } else if (args.size() > 3) {
        std::cout << "Too Many arguments" << "\n";
    }

    if (args.size() == 2) {
        new_command(args[1]);
    } else {
        new_command(args[1], args[2]);
    }

}
