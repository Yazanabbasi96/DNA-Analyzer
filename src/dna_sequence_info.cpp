
#include "dna_sequence_info.h"

size_t DNASequence_Info::m_id = 0;

DNASequence_Info::DNASequence_Info(DNA *dna,std::string name):DNA(*dna) {

    m_id++;
    if(name == "seq"){
        name.append((const char*)m_id);
    }
    m_name = name;

}
