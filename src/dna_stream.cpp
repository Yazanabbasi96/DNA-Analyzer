#include "dna_stream.h"
#include <fstream>
#include <iostream>

std::string DNA_Stream::load(const char *file_name) {
    std::string dna_data;
    std::ifstream infile;
    infile.open(file_name);
    infile >> dna_data;
    infile.close();
    return dna_data;
}

void DNA_Stream::save(const char *file_name, std::string dna_data) {
    std::ofstream outfile;
    outfile.open(file_name);
    outfile << dna_data << '\n';
    outfile.close();
}