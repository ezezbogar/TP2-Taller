#ifndef _NODE_H
#define _NODE_H

#include <vector>

class Node {
private:
    bool visited;
    std::vector<bool> edges;

public:

    /* Constructor */
    Node(int cantidadNodos);

    void setNodeVisited();

    void setEdge(int nodeNumber);

    /* Destructor */
    ~Node();

};


#endif //_NODE_H
