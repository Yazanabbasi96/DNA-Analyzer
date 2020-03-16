
#include <cstdio>
#include "dna_sequence_info.h"

size_t DNASequence_Info::m_id = 0;

DNASequence_Info::DNASequence_Info(DNASequence *dna_se,std::string name):DNA(dna_se){
    m_id++;
    if(name == "seq"){
        char numstr[21];
        sprintf(numstr, "%d", m_id);
        m_name = name + numstr;
    } else{
        m_name = name;
    }


}
