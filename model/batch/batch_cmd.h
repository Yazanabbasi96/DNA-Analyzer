
#ifndef DNA_ANALYZER_BATCH_CMD_H
#define DNA_ANALYZER_BATCH_CMD_H

#include "../command.h"
#include "batch.h"
#include <vector>
#include <string>
#include <map>

class Batch_command: public Command{

public:

    friend Batch* get_batch(std::string name);

    void arguments_parser(std::vector<std::string> args);

    void batch_cmd(std::string batch_name);

    void run_batch(std::string batch_name);

    void show_batch(std::string batch_name);

    void list_batches();

    void batch_save(std::string name,Batch *batch);

    void batch_load(std::string file_name,std::string name);


    ~Batch_command(){}

    static std::map<std::string,Batch*> batches_map;
};





#endif //DNA_ANALYZER_BATCH_CMD_H
