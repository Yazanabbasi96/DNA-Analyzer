cmake_minimum_required(VERSION 3.15)
project(dna_analyzer)

set(CMAKE_CXX_STANDARD 98)

add_executable(dna_analyzer main.cpp cli_interface.cpp cli_interface.h dna_sequence.cpp dna_sequence.h dna_stream.cpp dna_stream.h dna_container.cpp dna_container.h dna_sequence_info.cpp dna_sequence_info.h dna_sequence_creater.cpp dna_sequence_creater.h command_parser.cpp command_parser.h dna.h commandfactory.cpp commandfactory.h command.cpp command.h dna.cpp)