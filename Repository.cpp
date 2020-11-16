#include "Repository.h"

Repository::Repository(const int argc, char **argv) {
    this->verifiedFiles = 0;

    for (int i = 2; i < argc; i++) {
        std::string fileName(argv[i]);
        this->files.push_back(std::move(fileName));
    }
}

bool Repository::getFile(std::string &fileName) {
    std::unique_lock<std::mutex> lck(this->mutex);
    bool fileLeft = false;
    if ( static_cast<long unsigned int>(this->verifiedFiles)
    < this->files.size() ) {
        fileName = this->files[verifiedFiles];
        this->verifiedFiles++;
        fileLeft = true;
    }
    return fileLeft;
}

Repository::~Repository() {}
