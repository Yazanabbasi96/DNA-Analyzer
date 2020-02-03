#ifndef DNA_ANALYZER_DNA_CONTAINER_H
#define DNA_ANALYZER_DNA_CONTAINER_H

#include <vector>
#include "dna_sequence_info.h"

class DNA_container {
public:

    static DNA_container &getInstance() {
        static DNA_container instance;
        return instance;
    }

    std::vector<DNASequence_Info> m_sequences_container;
private:
    DNA_container() {}


    DNA_container(DNA_container const &);

    void operator=(DNA_container const &);
};


#endif //DNA_ANALYZER_DNA_CONTAINER_H
