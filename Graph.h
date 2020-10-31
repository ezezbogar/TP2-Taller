#ifndef _GRAPH_H
#define _GRAPH_H

#include "Node.h"

class Graph {
private:
    std::vector<Node> nodes;

public:
    /* Constructor */
    Graph(int cantidadNodos);

    /* Destructor */
    ~Graph();
};
#endif //_GRAPH_H
