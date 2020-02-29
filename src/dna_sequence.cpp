#include <cstring>
#include <iostream>
#include "dna_sequence.h"


void check_nucleotides(const char *nucleotides) {

    for (size_t i = 0; i < strlen(nucleotides); ++i) {
        if (nucleotides[i] == 'A' || nucleotides[i] == 'T' || nucleotides[i] == 'G' || nucleotides[i] == 'C') {
            continue;
        } else {
            throw std::invalid_argument("Error!, Make sure your string only contains nucleotides(A,T,G,C)");
        }
    }
}


DNASequence::DNASequence(const char *nucleotides):DNA() {
    this->m_nucleotides = new char[strlen(nucleotides) + 1];
    check_nucleotides(nucleotides);
    strcpy(this->m_nucleotides, nucleotides);
}

DNASequence::DNASequence(const std::string &nucleotides):DNA() {
    const char *c_nucleotides = nucleotides.c_str();
    check_nucleotides(c_nucleotides);
    this->m_nucleotides = new char[nucleotides.length() + 1];
    strcpy(this->m_nucleotides, c_nucleotides);
}

DNASequence::DNASequence(const DNASequence &dna_seq):DNA() {
    this->m_nucleotides = new char[strlen(dna_seq.m_nucleotides) + 1];
    strcpy(this->m_nucleotides, dna_seq.getNucleotides());
}

DNASequence &DNASequence::operator=(const DNASequence &dna_seq) {
    this->~DNASequence();
    new(this)DNASequence(dna_seq);
    return *this;
}

DNASequence &DNASequence::operator=(const std::string &nucleotides) {
    this->~DNASequence();
    new(this)DNASequence(nucleotides);
    return *this;
}

DNASequence &DNASequence::operator=(const char *nucleotides) {
    this->~DNASequence();
    new(this)DNASequence(nucleotides);
    return *this;
}


std::ostream &operator<<(std::ostream &out, const DNASequence &dna_seq) {
    out << dna_seq.m_nucleotides;
    return out;
}

bool DNASequence::operator==(const DNASequence &dna_seq) {
    return strcmp(this->m_nucleotides, dna_seq.getNucleotides()) == 0;
}

bool DNASequence::operator!=(const DNASequence &dna_seq) {
    return strcmp(this->m_nucleotides, dna_seq.getNucleotides()) != 0;
}

char &DNASequence::operator[](size_t index) {
    if (index > sizeof(m_nucleotides)) {
        throw bad_index();
    } else {
        return m_nucleotides[index];
    }
}

DNASequence::~DNASequence() {
    delete[] m_nucleotides;
}

