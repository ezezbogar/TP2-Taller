#include "Graph.h"

//Node se pasa y se destruye, push_back ag //Node se pasa y se destruye
//Add element at the end
//Adds a new element at the end of the vector, after its current last element.
//The content of val is copied (or moved) to the new element.

Graph::Graph(int cantidadNodos) {
    this->nodes.reserve(cantidadNodos);
    for(int i = 0; i < cantidadNodos; i++) {
        this->nodes.push_back(Node(cantidadNodos));
    }
}

Graph::~Graph() {}