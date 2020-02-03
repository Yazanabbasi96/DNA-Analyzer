
#include "dna_sequence_info.h"

size_t DNASequence_Info::m_id = 0;


DNASequence_Info::DNASequence_Info(DNASequence *dnaSequence,std::string name):DNASequence(*dnaSequence) {
    m_dna_sequence = dnaSequence;
    m_name = name;
    m_id++;
}
