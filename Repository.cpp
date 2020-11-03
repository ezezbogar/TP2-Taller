#include "Repository.h"

Repository::Repository(const int argc, char **argv) {
    this->verifiedFiles = 0;

    for (int i = 2; i < argc; i++) {
        this->files.push_back(std::string(argv[i]));
    }
}

int Repository::getAmountOfFiles() {
    return this->files.size();
}

bool Repository::getFile(std::string &fileName) {
    this->mutex.lock();
    bool fileLeft = false;
    if ( static_cast<long unsigned int>(this->verifiedFiles)
    < this->files.size() ) {
        fileName = this->files[verifiedFiles];
        this->verifiedFiles++;
        fileLeft = true;
    }
    this->mutex.unlock();
    return fileLeft;
}

Repository::~Repository() {}
