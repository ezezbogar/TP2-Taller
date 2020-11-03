#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <vector>
#include <string>
#include <mutex>

class Repository {
 private:
    std::vector<std::string> files;
    int verifiedFiles;
    std::mutex mutex;
 public:
    Repository(const int argc, char** argv);

    int getAmountOfFiles();

    bool getFile(std::string &fileName);

    ~Repository();
};
#endif  // REPOSITORY_H_
