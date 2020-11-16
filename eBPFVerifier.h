#ifndef EBPFVERIFIER_H_
#define EBPFVERIFIER_H_

#include "Thread.h"
#include "Graph.h"
#include "Repository.h"
#include "Results.h"
#include <string>

class eBPFVerifier : public Thread {
 private:
    Repository& repository;
    Results& results;

 public:
    /* Constructor */
    eBPFVerifier(Repository& repository, Results& results) :
                repository(repository), results(results) {}

    /* Constructor por copia borrado */
    eBPFVerifier(const eBPFVerifier& ebpfVerifier) = delete;

    /* Asignacion por copia borrado */
    eBPFVerifier operator=(const eBPFVerifier& ebpfVerifier) = delete;

    /* Extrae un archivo de "repository" mientras todavia queden, verifica si tiene
     * ciclos e instrucciones sin utilizar y guarda el resultado en "results" */
    void verificar() override;

    /* Destructor */
    ~eBPFVerifier();

 private:
    void _verificar(std::string& fileName);

    void _saveResults(const std::string& fileName, const Graph &graph);
};

#endif  // EBPFVERIFIER_H_
