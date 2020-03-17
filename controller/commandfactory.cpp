#include "commandfactory.h"
#include "../model/sequence_creation/dna_sequence_creater.h"
#include "../model/sequence_manipulation/slice_cmd.h"
#include "../model/batch/batch_cmd.h"


void CommandFactory::CommandFactory_init() {
    commandFactory["new"] = new DNASequence_Creator();
    commandFactory["load"] = new DNASequence_Creator();
    commandFactory["dup"] = new DNASequence_Creator();
    commandFactory["slice"] = new Slice_Command();
    commandFactory["replace"] = new DNASequence_Creator();
    commandFactory["concat"] = new DNASequence_Creator();
    commandFactory["pair"] = new DNASequence_Creator();
    commandFactory["rename"] = new DNASequence_Creator();
    commandFactory["del"] = new DNASequence_Creator();
    commandFactory["reenum"] = new DNASequence_Creator();
    commandFactory["save"] = new DNASequence_Creator();
    commandFactory["batch"] = new Batch_command();
    commandFactory["run"] = new Batch_command();
    commandFactory["batchlist"] = new Batch_command();
    commandFactory["batchshow"] = new Batch_command();
    commandFactory["batchsave"] = new Batch_command();
    commandFactory["batchload"] = new Batch_command();
}




