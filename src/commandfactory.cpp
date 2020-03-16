
#include "commandfactory.h"
#include "dna_sequence_creater.h"


void CommandFactory::CommandFactory_init() {
    commandFactory["new"] = new DNASequence_Creator();
    commandFactory["load"] = new DNASequence_Creator();
    commandFactory["dup"] = new DNASequence_Creator();
    commandFactory["slice"] = new DNASequence_Creator();
    commandFactory["replace"] = new DNASequence_Creator();
    commandFactory["concat"] = new DNASequence_Creator();
    commandFactory["pair"] = new DNASequence_Creator();
    commandFactory["rename"] = new DNASequence_Creator();
    commandFactory["del"] = new DNASequence_Creator();
    commandFactory["reenum"] = new DNASequence_Creator();
    commandFactory["save"] = new DNASequence_Creator();
}




