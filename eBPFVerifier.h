#ifndef EBPFVERIFIER_H_
#define EBPFVERIFIER_H_

#include "Thread.h"
#include "Graph.h"
#include "Repository.h"
#include "Results.h"

class eBPFVerifier : public Thread {
 private:
    Repository& repository;
    Results& results;

 public:
    /* Constructor */
    eBPFVerifier(Repository& repository, Results& results) :
                repository(repository), results(results) {}

    void verificar() override;

    /* Destructor */
    ~eBPFVerifier();

 private:
    void _verificar(std::string fileName);

    void _saveResults(std::string fileName, Graph &graph);
};

#endif  // EBPFVERIFIER_H_
