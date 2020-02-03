#ifndef DNA_ANALYZER_DNA_STREAM_H
#define DNA_ANALYZER_DNA_STREAM_H

#include <string>

class DNA_Stream {

public:
    DNA_Stream() {}

    std::string load(const char *file_name);

    void save(const char *file_name, std::string dna_data);

};


#endif //DNA_ANALYZER_DNA_STREAM_H
