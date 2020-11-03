#ifndef GRAPH_H_
#define GRAPH_H_

#include "Node.h"
#include <string>

class Graph {
 private:
    std::vector<Node> nodes;
    // DFS
    int i;
    std::vector<bool> marks;
    std::vector<int> nums;
    bool hasCicles;
    bool hasUnusedInstructions;

 public:
    /* Constructor */
    Graph(int cantidadNodos);

    void setEdge(int nodeNumberOrigin, int nodeNumberDest);

    /* Analiza si el programa eBPF puede caer en un loop infinito */
    void DFS();

    /* Analiza si en el programa eBPF existen instrucciones que
     * nunca son utilizadas (Usar despues de DFS)*/
    void checkUnusedInstructions();

    /* Devuelve "true" si el programa eBPF tiene ciclos, en el otro
     * caso "false" (Usar despues de DFS)*/
    bool programhasCicles();

    /* Devuelve "true" si el programa eBPF tiene instrucciones que
     * nunca son utilizadas (Usar despues de checkUnusedInstructions)*/
    bool programhasUnusedInstructions();

    /* Destructor */
    ~Graph();

 private:
    void _DFS(const int nodeNumber);
};

#endif  // GRAPH_H_
