
#include <cstdio>
#include "dna_sequence_info.h"

size_t DNASequence_Info::m_id = 0;

DNASequence_Info::DNASequence_Info(DNA_Decorator *dna_deco,std::string name):DNA_Decorator(){
    m_id++;
    if(name == "seq"){
        char numstr[21];
        sprintf(numstr, "%d", m_id);
        m_name = name + numstr;
    } else{
        m_name = name;
    }
    m_dna_deco = dna_deco;
}
