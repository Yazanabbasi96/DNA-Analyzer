#include <sstream>
#include "slice_cmd.h"
#include "../dna_sequence_info.h"
#include "../../dna_container.h"
#include "../sequence_creation/dna_sequence_creater.h"

DNASequence_Info *isSeqNameExist(const std::string seq) {
    DNA_container &container = DNA_container::getInstance();
    std::map<std::string, DNASequence_Info *>::iterator it = container.dna_name_map.find(seq);
    DNASequence_Info *dna_seq;
    if (it != container.dna_name_map.end()) {
        dna_seq = it->second;
        return dna_seq;
    } else {
        std::cout << "Name Does not Exist!\n";
    }
    return NULL;
}

DNASequence_Info *isSeqIdExist(const size_t seq_id) {
    DNA_container &container = DNA_container::getInstance();
    std::map<size_t, DNASequence_Info *>::iterator it = container.dna_id_map.find(seq_id);
    DNASequence_Info *dna_seq;
    if (it != container.dna_id_map.end()) {
        dna_seq = it->second;
        return dna_seq;
    } else {
        std::cout << "Name Does not Exist!\n";
    }

    return NULL;
}

DNASequence_Info *name_or_id(std::string seq) {
    DNASequence_Info *dna_seq;
    if (seq[0] == '#') {
        seq.erase(0, 1);
        std::stringstream sstream(seq);
        size_t temp_id;
        sstream >> temp_id;
        dna_seq = isSeqIdExist(temp_id);
        return dna_seq;
    } else if (seq[0] == '@') {
        seq.erase(0, 1);
        dna_seq = isSeqNameExist(seq);
        return dna_seq;
    } else {
        std::cout << "Wrong format!";
    }
    return NULL;
}

size_t from_string_to_size_t(std::string index) {
    std::stringstream sstream(index);
    size_t temp_index;
    sstream >> temp_index;
    return temp_index;
}

void Slice_Command::arguments_parser(std::vector<std::string> args) {
    DNASequence_Info *dna_seq;
    dna_seq = name_or_id(args[1]);
    size_t start_pt = from_string_to_size_t(args[2]);
    size_t end_pt = from_string_to_size_t(args[3]);
    if (args.size() == 5) {
        slice_cmd(dna_seq,start_pt ,end_pt, dna_seq->getName());
    } else if (args.size() == 7) {
        if (args[4] == ":" && args[5][0] == '@' && args[5][1] == '@') {
            slice_cmd(dna_seq, from_string_to_size_t(args[2]), from_string_to_size_t(args[3]), "@");
        } else if (args[4] == ":" && args[5][0] == '@') {
            args[5].erase(0, 1);
            slice_cmd(dna_seq, from_string_to_size_t(args[2]), from_string_to_size_t(args[3]), args[5]);
        } else {
            std::cout << "Wrong Args!!\n";
        }
    } else {
        std::cout << "Check your args!!\n";
    }

}



DNASequence_Info *
Slice_Command::slice_cmd(DNASequence_Info *dna_seq, const size_t start_index, const size_t end_index, const std::string name) {
    DNASequence_Creator dna_creator;
    std::string new_seq = ((DNASequence*)(dna_seq->m_dna_deco))->get_str_Nucleotides().substr(start_index,(end_index-start_index));
    DNA_container &container = DNA_container::getInstance();
    if(name=="@"){
       DNASequence_Info new_dna_seq =  dna_creator.new_command(new_seq,"seq");
       //std::cout << "[" << new_dna_seq.getId() << "]" << " "<< ((DNASequence*)(new_dna_seq.m_dna_deco))->getNucleotides() << " " << new_dna_seq.getName() << '\n';
    } else if(name == dna_seq->getName()){
        ((DNASequence*)(dna_seq->m_dna_deco))->setNucleotides(new_seq);
        std::cout << "[" << dna_seq->getId() << "]" << " "<< ((DNASequence*)(dna_seq->m_dna_deco))->getNucleotides() << " " << dna_seq->getName() << '\n';
    } else{
        DNASequence_Info new_dna_seq = dna_creator.new_command(new_seq,name);
        //std::cout << "[" << new_dna_seq.getId() << "]" << " "<< ((DNASequence*)(new_dna_seq.m_dna_deco))->getNucleotides() << " " << new_dna_seq.getName() << '\n';
    }

    return dna_seq;
}