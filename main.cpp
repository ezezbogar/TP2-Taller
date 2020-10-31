#include <iostream>
#include <vector>
#include "Parser.h"
#include <fstream>

int main (int argc, char** argv) {


    std::fstream src;
    src.open("/home/ezezbogar/git/TP2-Taller/tcp.bpf");

    Parser parseador;
    parseador.getLabels(src);

    parseador._showLabels();

    src.close();






    char msg[] = "messi flexi";
    char msg2[] = "sale bo2 pa?";
    std::string mensaje(msg, 10);

    mensaje = std::string(msg2, 8);

    std::cout << mensaje << std::endl;

    std::vector<int> myints;

    myints.push_back(5);
    myints.push_back(3);
    myints.push_back(2);
    myints.push_back(1);

    std::cout << myints.size() << std::endl;






    if (argc >= 3) {
        //Correr TP
        std::cout << "Ejecutando" << std::endl;
        Parser();
    } else {
        std::cerr << "Argumentos invalidos" << std::endl;
        return -1;
    }
}
