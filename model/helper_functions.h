
#ifndef DNA_ANALYZER_HELPER_FUNCTIONS_H
#define DNA_ANALYZER_HELPER_FUNCTIONS_H

#include "dna_sequence_info.h"

class Helper_Functions{
public:
    static DNASequence_Info *isSeqIdExist(const size_t seq_id);
    static DNASequence_Info *name_or_id(std::string seq);
    static DNASequence_Info *isSeqNameExist(const std::string seq);

};


#endif //DNA_ANALYZER_HELPER_FUNCTIONS_H
