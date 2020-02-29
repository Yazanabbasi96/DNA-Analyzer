
#include "cli_interface.h"
#include "commandfactory.h"

int main() {

    CommandFactory cmdFactory;
    cmdFactory.CommandFactory_init();

    CLI_Interface cmd;
    cmd.run_DNA_Analyzer();
    return 0;
}
