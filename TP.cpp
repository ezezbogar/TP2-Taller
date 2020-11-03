#include "TP.h"

void TP::ejecutar() {
    for (int i = 0; i < this->threadsAmount; i++) {
        this->eBPFVerifiers.push_back(new eBPFVerifier
        (this->repository, this->results));
        this->eBPFVerifiers[i]->start();
    }

    for (int j = 0; j < this->threadsAmount; j++) {
        this->eBPFVerifiers[j]->join();
        delete this->eBPFVerifiers[j];
    }
}

TP::~TP() {}
