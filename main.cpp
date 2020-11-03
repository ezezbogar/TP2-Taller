#include <iostream>
#include "TP.h"

int main(int argc, char** argv) {
    if (argc >= 3) {
        // Ejecutar TP
        Repository repository(argc, argv);
        Results results;
        TP tp(repository, results, atoi(argv[1]));
        tp.ejecutar();
        results.showResults();
    } else {
        std::cerr << "Argumentos invalidos" << std::endl;
        return -1;
    }
    return 0;
}
