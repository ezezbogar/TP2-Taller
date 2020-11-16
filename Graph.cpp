#include "Graph.h"

Graph::Graph(int cantidadNodos) {
    this->nodes.reserve(cantidadNodos);
    this->marks.reserve(cantidadNodos);
    this->nums.reserve(cantidadNodos);
    this->i = 0;
    this->hasCicles = false;
    this->hasUnusedInstructions = false;

    for (int j = 0; j < cantidadNodos; j++) {
        Node node(cantidadNodos);
        this->nodes.push_back(std::move(node));
    }
    for (int j = 0; j < cantidadNodos; j++) {
        this->marks.push_back(false);
    }
    for (int j = 0; j < cantidadNodos; j++) {
        this->nums.push_back(0);
    }
}

void Graph::setEdge(int nodeNumberOrigin, int nodeNumberDest) {
    this->nodes[nodeNumberOrigin].setEdge(nodeNumberDest);
}

void Graph::DFS() {
    _DFS(0);
}

void Graph::_DFS(const int nodeNumber) {
    this->i++;
    this->nums[nodeNumber] = i;
    this->marks[nodeNumber] = true;
    this->nodes[nodeNumber].setNodeVisited();
    for (unsigned long int j = 0; j < this->nodes.size(); j++) {
        if (this->nodes[nodeNumber].getEdge(j) == true) {
            if (this->nums[j] == 0) {  // Tree edge
                _DFS(j);
            } else if (this->nums[j] >
            this->nums[nodeNumber]) {  // Forward edge
            } else if (this->marks[j] == 0) {  // Cross edge
            } else {
                this->hasCicles = true;  // Back edge (Graph has cicles)
            }
        }
    }
    this->marks[nodeNumber] = false;
}

void Graph::checkUnusedInstructions() {
    for (unsigned long int i = 0; i < this->nodes.size(); i++) {
        if (this->nodes[i].isVisited() == false) {
            this->hasUnusedInstructions = true;
        }
    }
}

bool Graph::programhasCicles() const {
    return this->hasCicles;
}

bool Graph::programhasUnusedInstructions() const {
    return this->hasUnusedInstructions;
}

Graph::~Graph() {}
