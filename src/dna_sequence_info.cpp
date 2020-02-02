
#include "dna_sequence_info.h"

DNASequence_Info::DNASequence_Info(std::string sequence, size_t id, std::string name) : DNASequence(sequence), m_id(id),
                                                                                        m_name(name) {}