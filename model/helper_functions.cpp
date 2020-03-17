#include <iostream>
#include <sstream>
#include "helper_functions.h"
#include "../dna_container.h"


DNASequence_Info *Helper_Functions::isSeqNameExist(const std::string seq) {
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

DNASequence_Info *Helper_Functions::isSeqIdExist(const size_t seq_id) {
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

DNASequence_Info *Helper_Functions::name_or_id(std::string seq) {
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
