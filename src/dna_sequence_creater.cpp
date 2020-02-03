#include "dna_sequence_creater.h"
#include "dna_container.h"

DNASequence_Info DNASequence_Creator::new_command(std::string dna, std::string name) {
    DNASequence new_dna(dna);
    DNASequence_Info dna_seq(&new_dna, name);
    DNA_container &container = DNA_container::getInstance();
    container.m_sequences_container.push_back(dna_seq);
    return dna_seq;
}