#include <iostream>
#include "dna_sequence_creater.h"
#include "../../dna_container.h"
#include "../dna_sequence_info.h"


DNASequence_Info DNASequence_Creator::new_command(std::string dna,const std::string& name = "seq") {
    DNASequence_Info *dna_seq = new DNASequence_Info(new DNASequence(dna),name);
    DNA_container &container = DNA_container::getInstance();
    container.dna_name_map[dna_seq->getName()] = dna_seq;
    container.dna_id_map[dna_seq->getId()] = dna_seq;
    std::cout << "[" << dna_seq->getId() << "]" << " "<< ((DNASequence*)(dna_seq->m_dna_deco))->getNucleotides() << " " << dna_seq->getName() << '\n';

    return *dna_seq;
}


void DNASequence_Creator::arguments_parser(std::vector<std::string> args) {

    if (args.size() == 3) {
        new_command(args[1]);
    } else if(args.size()==4){
        new_command(args[1], args[2]);
    } else{
        std::cout<<"Check youR args!!";
    }

}
