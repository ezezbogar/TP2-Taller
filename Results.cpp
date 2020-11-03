#include "Results.h"
#include <iostream>

Results::Results() {}

void Results::showResults() {
    for (long unsigned int i = 0; i < this->filenames.size(); i++) {
        std::cout << this->filenames[i] << " " <<
        this->exitCodes[i] << std::endl;
    }
}

void Results::loadResult(std::string filename, std::string exitcode) {
    this->mutex.lock();
    long unsigned int pos = 0;

    std::vector<std::string>::iterator itFiles;
    std::vector<std::string>::iterator itCodes;
    itFiles = this->filenames.begin();
    itCodes = this->exitCodes.begin();

    while (pos < this->filenames.size()) {
        if (filename.compare(this->filenames[pos]) < 0) {
            break;
        }
        pos++;
    }
    this->filenames.insert(itFiles + pos, filename);
    this->exitCodes.insert(itCodes + pos, exitcode);
    this->mutex.unlock();
}

Results::~Results() {}