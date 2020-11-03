#ifndef NODE_H_
#define NODE_H_

#include <vector>

class Node {
 private:
    bool visited;
    std::vector<bool> edges;

 public:
    /* Constructor */
    Node(int cantidadNodos);

    void setNodeVisited();

    bool isVisited();

    void setEdge(int nodeNumber);

    bool getEdge(int edgeNumber);

    /* Destructor */
    ~Node();
};


#endif  // NODE_H_
