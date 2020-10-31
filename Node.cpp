#include "Node.h"
#include <iostream> //Borrar
Node::Node(int cantidadNodos) {
    this->visited = false;
    this->edges.reserve(cantidadNodos);

    for(int i = 0; i < cantidadNodos; i++) {
        this->edges.push_back(false);
    }
}

void Node::setNodeVisited() {
    this->visited = true;
}

void Node::setEdge(int nodeNumber) {
    this->edges[nodeNumber] = true;
}

Node::~Node() {
    for(long unsigned int i = 0; i < this->edges.size(); i++){
        std::cout << "Hola" << this->edges[i] << std::endl;
    }
    std::cout << this->edges.size() << std::endl;
}