
#ifndef DNA_ANALYZER_DNA_SEQUENCE_CREATER_H
#define DNA_ANALYZER_DNA_SEQUENCE_CREATER_H

#include "dna_sequence_info.h"


class DNASequence_Creator {


public:
    DNASequence_Creator() {}
    DNASequence_Info new_command(std::string dna, std::string name);
};

#endif //DNA_ANALYZER_DNA_SEQUENCE_CREATER_H
