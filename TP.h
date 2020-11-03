#ifndef TP_H_
#define TP_H_

#include <vector>
#include "Thread.h"
#include "Repository.h"
#include "Results.h"
#include "eBPFVerifier.h"

class TP {
 private:
    Repository &repository;
    Results &results;
    std::vector<Thread*> eBPFVerifiers;
    int threadsAmount;
 public:
    /* Constructor */
    TP(Repository &repository, Results &results, int threadsAmount) :
        repository(repository), results(results),
        threadsAmount(threadsAmount) {}

    /* Ejecuta el TP */
    void ejecutar();

    /* Destructor */
    ~TP();
};

#endif  // TP_H_
