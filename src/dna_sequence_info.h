
#ifndef DNA_ANALYZER_DNA_SEQUENCE_INFO_H
#define DNA_ANALYZER_DNA_SEQUENCE_INFO_H


#include <string>
#include "dna.h"


class DNASequence_Info : public DNA {


public:

    DNASequence_Info(DNA *dna, std::string name);

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

    DNA *m_dna;

private:
    static size_t m_id;
    std::string m_name;

};

#endif //DNA_ANALYZER_DNA_SEQUENCE_INFO_H
