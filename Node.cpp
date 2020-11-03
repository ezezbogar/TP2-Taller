#include "Node.h"

Node::Node(int cantidadNodos) {
    this->visited = false;
    this->edges.reserve(cantidadNodos);

    for (int i = 0; i < cantidadNodos; i++) {
        this->edges.push_back(false);
    }
}

void Node::setNodeVisited() {
    this->visited = true;
}

bool Node::isVisited() {
    return this->visited;
}

void Node::setEdge(int nodeNumber) {
    this->edges[nodeNumber] = true;
}

bool Node::getEdge(int edgeNumber) {
    return this->edges[edgeNumber];
}

Node::~Node() {}
