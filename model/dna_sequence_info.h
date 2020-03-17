
#ifndef DNA_ANALYZER_DNA_SEQUENCE_INFO_H
#define DNA_ANALYZER_DNA_SEQUENCE_INFO_H

#include "dna_sequence.h"
#include "dna_decorator.h"


class DNASequence_Info : public DNA_Decorator {

public:

    DNASequence_Info(DNA_Decorator *dna,std::string name);

     size_t getId() const {
        return m_id;
     }

    void setId(size_t mId) {
        m_id = mId;
    }

    const std::string &getName() const {
        return m_name;
    }

    void setName(const std::string &mName) {
        m_name = mName;
    }

    DNA_Decorator *m_dna_deco;

private:

    static size_t m_id;
    std::string m_name;

};

#endif //DNA_ANALYZER_DNA_SEQUENCE_INFO_H
