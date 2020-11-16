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

    /* Constructor por copia borrado */
    Results(const Results& results) = delete;

    /* Asignacion por copia borrado */
    Results operator=(const Results& results) = delete;

    /* Guarda el nombre de un archivo con su respectivo exitcode */
    void loadResult(std::string filename, std::string exitcode);

    /* Muestra los resultados de todos los archivos por pantalla */
    void showResults();

    /* Destructor */
    ~Results();
};

#endif  // RESULTS_H_
