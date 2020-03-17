cmake_minimum_required(VERSION 3.15)
project(dna_analyzer)
set(CMAKE_CXX_STANDARD 98)


add_executable(dna_analyzer main.cpp view/cli_interface.cpp view/cli_interface.h model/dna_sequence.cpp model/dna_sequence.h dna_stream.cpp dna_stream.h dna_container.cpp dna_container.h model/dna_sequence_info.cpp model/dna_sequence_info.h model/sequence_creation/dna_sequence_creater.cpp model/sequence_creation/dna_sequence_creater.h controller/command_parser.cpp controller/command_parser.h controller/commandfactory.cpp controller/commandfactory.h model/command.cpp model/command.h model/dna_decorator.cpp model/dna_decorator.h model/sequence_manipulation/slice_cmd.cpp model/sequence_manipulation/slice_cmd.h model/sequence_manipulation/pair_cmd.cpp model/sequence_manipulation/pair_cmd.h model/batch/batch_cmd.cpp model/batch/batch_cmd.h model/batch/batch.cpp model/batch/batch.h model/helper_functions.cpp model/helper_functions.h)