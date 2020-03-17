#ifndef DNA_ANALYZER_DNA_SEQUENCE_H
#define DNA_ANALYZER_DNA_SEQUENCE_H

#include <string>
#include <vector>
#include "dna_decorator.h"


class bad_index : public std::exception {
public :
    const char *what() const throw() {
        return "Index out of range!";
    }
};


class DNASequence : public DNA_Decorator {
public:

    explicit DNASequence(const char *nucleotides);

    explicit DNASequence(const std::string &nucleotides);

    DNASequence(const DNASequence &dna_seq);

    DNASequence &operator=(const DNASequence &dna_seq);

    DNASequence &operator=(const std::string &nucleotides);

    DNASequence &operator=(const char *nucleotides);

    bool operator==(const DNASequence &dna_seq);

    bool operator!=(const DNASequence &dna_seq);

    char &operator[](size_t index);


    friend std::ostream &operator<<(std::ostream &out, const DNASequence &dna_seq);


    const char *getNucleotides() const {
        return m_nucleotides;
    }

    std::string get_str_Nucleotides() const {
        std::string ret_string(m_nucleotides);
        return ret_string;
    }

    void setNucleotides(std::string new_seq);

    ~DNASequence();


private:
    char *m_nucleotides;

};


#endif //DNA_ANALYZER_DNA_SEQUENCE_H
