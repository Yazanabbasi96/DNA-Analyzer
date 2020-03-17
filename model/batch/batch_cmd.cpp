#include "batch_cmd.h"
#include "../../controller/command_parser.h"
#include "../../controller/commandfactory.h"


std::map<std::string, Batch *> Batch_command::batches_map;

void Batch_command::arguments_parser(std::vector<std::string> args) {
    if (args.size() == 3 && args[0] == "batch") {
        batch_cmd(args[1]);
    } else if (args.size() == 3 && args[0] == "run") {
        if (args[1][0] == '@') {
            args[1].erase(0, 1);
            run_batch(args[1]);
        }
    } else if (args.size() == 3 && args[0] == "batchshow") {
        if (args[1][0] == '@') {
            args[1].erase(0, 1);
            show_batch(args[1]);
        }
    } else if (args.size() == 2 && args[0] == "batchlist") {
        list_batches();
    }


}

void Batch_command::batch_cmd(std::string batch_name) {
    Command_Parser cmd;
    std::vector<std::string> command_container;
    Batch *batch = new Batch();

    while (1) {
        std::string command_line;
        std::cout << "> batch >>> ";
        std::getline(std::cin, command_line);
        command_container = cmd.command_parser(command_line);
        if (command_container[0] == "end") {
            break;
        } else {
            batch->batch.push_back(command_container);

        }
    }
    Batch_command::batches_map[batch_name] = batch;
}

Batch *get_batch(std::string name) {

    Batch *batch;
    std::map<std::string, Batch *>::iterator it = Batch_command::batches_map.find(name);
    if (it != Batch_command::batches_map.end()) {
        batch = it->second;
        return batch;
    } else {
        std::cout << "Name Does not Exist!\n";
    }

    return NULL;
}

void Batch_command::run_batch(std::string batch_name) {
    Batch *batch = get_batch(batch_name);
    CommandFactory cmdFactory;
    cmdFactory.CommandFactory_init();

    for (int i = 0; i < batch->batch.size(); i++) {
        Command *command = cmdFactory.commandFactory[batch->batch[i][0]];
        command->arguments_parser(batch->batch[i]);
    }

}

void Batch_command::show_batch(std::string batch_name) {
    Batch *batch = get_batch(batch_name);
    for (int i = 0; i < batch->batch.size(); i++) {
        int j = 0;
        std::string command_cont = "";
        while (batch->batch[i][j] != "") {
            command_cont = command_cont + batch->batch[i][j] + " ";
            j++;
        }
        std::cout << command_cont << '\n';
    }
}

void Batch_command::list_batches() {
    for (std::map<std::string, Batch *>::iterator it = Batch_command::batches_map.begin();
         it != Batch_command::batches_map.end(); ++it) {
        std::cout << it->first << "\n";
    }
}

