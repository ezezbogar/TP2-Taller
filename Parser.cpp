#include "Parser.h"
#include <iostream>
#include <fstream>

#define BUF_LEN 128

Parser::Parser() {
    std::cout << "Parser" << std::endl;
    this->cantidadNodos = 0;
}

void Parser::getLabels(std::fstream& file) {
    char buf[BUF_LEN], c;
    int pos = 0;
    std::string labelAux;

    while(file.get(c)){
        std::cout << c;
        if ( c != ':' && c != ' ' && c != ',' && c != '\n' ) {
            buf[pos] = c;
            pos++;
        } else if ( c == ':') {
            labelAux = std::string(buf, pos);
            this->labels.push_back(Label(labelAux, this->cantidadNodos));
        } else if (c == '\n' && pos != 0) {
            pos = 0;
            this->cantidadNodos++;
        }
    }
}

void Parser::_showLabels(){
    long unsigned int i;
    for(i = 0; i < this->labels.size(); i++) {
        std::cout << labels[i].getLabelName() << ' ' << labels[i].getNodeNumber() << std::endl;
    }
    std::cout << this->cantidadNodos << std::endl;
}



Parser::~Parser() {}