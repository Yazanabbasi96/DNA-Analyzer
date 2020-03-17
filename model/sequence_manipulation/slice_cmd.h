#ifndef DNA_ANALYZER_SLICE_CMD_H
#define DNA_ANALYZER_SLICE_CMD_H

#include "../command.h"
#include "../dna_sequence_info.h"
#include <vector>
#include <string>

class Slice_Command: public Command{

    void arguments_parser(std::vector<std::string> args);

    DNASequence_Info *slice_cmd(DNASequence_Info *dna_seq,const size_t, const size_t, const std::string name);

    ~Slice_Command(){}
};





#endif //DNA_ANALYZER_SLICE_CMD_H
