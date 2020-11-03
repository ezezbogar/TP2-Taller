#include "Parser.h"
#include <fstream>

#define BUF_LEN 128
#define ERROR -1

Parser::Parser() {
    this->cantidadNodos = 0;
}

bool isJumpCode(const std::string instruction) {
    bool isJumpCode = false;
    if (instruction.compare("jmp") == 0 || instruction.compare("ja") == 0) {
        isJumpCode = true;
    }
    if (instruction.compare("jeq") == 0 || instruction.compare("jneq") == 0) {
        isJumpCode = true;
    }
    if (instruction.compare("jne") == 0 || instruction.compare("jlt") == 0) {
        isJumpCode = true;
    }
    if (instruction.compare("jle") == 0 || instruction.compare("jgt") == 0) {
        isJumpCode = true;
    }
    if (instruction.compare("jge") == 0 || instruction.compare("jset") == 0) {
        isJumpCode = true;
    }
    return isJumpCode;
}

bool isRetCode(const std::string instruction) {
    bool isRetCode = false;
    if (instruction.compare("ret") == 0) {
        isRetCode = true;
    }
    return isRetCode;
}

void Parser::loadGraph(Graph& graph, std::fstream& file) {
    char buf[BUF_LEN], c;
    bool isJumpLine = false, isRetLine = false;
    int labelNodeNumber, currentNodeNumber = 0, arguments = 0, pos = 0;

    while (file.get(c)) {
        if ( c != ':' && c != ' ' && c != ',' && c != '\n' ) {
            buf[pos] = c;
            pos++;
        } else if ( c == ':' ) {
            pos = 0;
        } else if ( c == ' ' && pos != 0 &&
        isJumpCode(std::string(buf, pos)) ) {
            isJumpLine = true;
            pos = 0;
            arguments = 1;
        } else if ( c == ' ' && pos != 0 && isRetCode(std::string(buf, pos)) ) {
            isRetLine = true;
        } else if ( c == ',' && isJumpLine ) {
            labelNodeNumber = getLabelNodeNumber(std::string(buf, pos));
            if (labelNodeNumber != ERROR) {
                graph.setEdge(currentNodeNumber, labelNodeNumber);
            }
            pos = 0;
            arguments++;
        } else if ( c == '\n' && isJumpLine ) {
            labelNodeNumber = getLabelNodeNumber(std::string(buf, pos));
            if (labelNodeNumber != ERROR) {
                graph.setEdge(currentNodeNumber, labelNodeNumber);
            }
            if (arguments == 2) {
                graph.setEdge(currentNodeNumber, currentNodeNumber + 1);
            }
            pos = 0;
            currentNodeNumber++;
            isJumpLine = false;
        } else if ( c == '\n' && isRetLine ) {
            currentNodeNumber++;
            isJumpLine = false;
            isRetLine = false;
            pos = 0;
        } else if ( c == '\n' && pos != 0 ) {
            graph.setEdge(currentNodeNumber, currentNodeNumber + 1);
            currentNodeNumber++;
            isJumpLine = false;
            pos = 0;
        }
    }
}

void Parser::getLabels(std::fstream& file) {
    char buf[BUF_LEN], c;
    int pos = 0;
    std::string labelAux;

    while (file.get(c)) {
        if ( c != ':' && c != ' ' && c != ',' && c != '\n' ) {
            buf[pos] = c;
            pos++;
        } else if ( c == ':' ) {
            labelAux = std::string(buf, pos);
            this->labels.push_back(Label(labelAux, this->cantidadNodos));
        } else if ( c == '\n' && pos != 0 ) {
            pos = 0;
            this->cantidadNodos++;
        }
    }
    file.clear();
    file.seekg(0);
}

int Parser::getLabelNodeNumber(std::string name) {
    for (long unsigned int i = 0; i < this->labels.size(); i++) {
        if (this->labels[i].getLabelName().compare(name) == 0) {
            return this->labels[i].getNodeNumber();
        }
    }
    return ERROR;
}

int Parser::getNodesAmount() {
    return this->cantidadNodos;
}

Parser::~Parser() {}
