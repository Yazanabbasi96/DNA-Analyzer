
#ifndef DNA_ANALYZER_DNA_H
#define DNA_ANALYZER_DNA_H

#include "dna_sequence.h"

class DNA: public DNASequence {
public:
    DNA(DNASequence *dna_seq) : m_dna_seq(dna_seq);

    ~DNA() {}

private:
    DNASequence *m_dna_seq;
};


#endif //DNA_ANALYZER_DNA_H
