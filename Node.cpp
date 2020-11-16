#include "Node.h"

Node::Node(int cantidadNodos) {
    this->visited = false;
    this->edges.reserve(cantidadNodos);

    for (int i = 0; i < cantidadNodos; i++) {
        this->edges.push_back(false);
    }
}

Node::Node(Node &&node) noexcept {
    this->edges = std::move(node.edges);
    this->visited = node.visited;
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
