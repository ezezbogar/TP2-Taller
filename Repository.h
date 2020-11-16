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
    /* Constructor */
    Repository(const int argc, char** argv);

    /* Constructor por copia borrado */
    Repository(const Repository& repository) = delete;

    /* Asignacion por copia borrado */
    Repository operator=(const Repository& repository) = delete;

    /* Devuelve la cantidad de archivos en el repositorio */
    int getAmountOfFiles();

    /* Devuelve el nombre de un archivo que todavia no haya sido
     * verificado */
    bool getFile(std::string &fileName);

    /* Destructor */
    ~Repository();
};
#endif  // REPOSITORY_H_
