#ifndef RESULTS_H_
#define RESULTS_H_

#include <vector>
#include <string>
#include <mutex>

class Results {
 private:
    std::vector<std::string> filenames;
    std::vector<std::string> exitCodes;
    std::mutex mutex;

 public:
    /* Constructor */
    Results();

    void loadResult(std::string filename, std::string exitcode);

    void showResults();

    /* Destructor */
    ~Results();
};

#endif  // RESULTS_H_
