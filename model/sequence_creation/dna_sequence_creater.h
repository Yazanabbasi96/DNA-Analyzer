
#ifndef DNA_ANALYZER_DNA_SEQUENCE_CREATER_H
#define DNA_ANALYZER_DNA_SEQUENCE_CREATER_H

#include "../dna_sequence_info.h"
#include "../command.h"


class DNASequence_Creator : public Command {

public:
    DNASequence_Creator(){};

    void arguments_parser(std::vector<std::string> args);

    DNASequence_Info new_command(std::string dna, const std::string& name);
};

#endif //DNA_ANALYZER_DNA_SEQUENCE_CREATER_H
