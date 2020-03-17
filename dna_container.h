#ifndef DNA_ANALYZER_DNA_CONTAINER_H
#define DNA_ANALYZER_DNA_CONTAINER_H

#include <vector>
#include <map>
#include "model/dna_sequence_info.h"

class DNA_container {
public:

    static DNA_container &getInstance() {
        static DNA_container instance;
        return instance;
    }

    std::map<std::string, DNASequence_Info *> dna_name_map;
    std::map<size_t, DNASequence_Info *> dna_id_map;

private:

    DNA_container() {}

    DNA_container(DNA_container const &);

    void operator=(DNA_container const &);
};


#endif //DNA_ANALYZER_DNA_CONTAINER_H
