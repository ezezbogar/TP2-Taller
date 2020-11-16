#ifndef GRAPH_H_
#define GRAPH_H_

#include "Node.h"
#include <string>
#include <vector>

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
    explicit Graph(int cantidadNodos);

    /* Constructor por copia borrado */
    Graph(const Graph& graph) = delete;

    /* Asignacion por copia borrado */
    Graph operator=(const Graph& graph) = delete;

    /* Crea una arista */
    void setEdge(int nodeNumberOrigin, int nodeNumberDest);

    /* Analiza si el grafo tiene ciclos */
    void DFS();

    /* Analiza si en el grafo existen nodos no accesibles
     * (Usar despues de DFS) */
    void checkUnusedInstructions();

    /* Devuelve "true" si el grafo tiene ciclos, en el otro
     * caso "false" (Usar despues de DFS) */
    bool programhasCicles() const;

    /* Devuelve "true" si el grafo tiene nodos no accesibles, en
     * el otro caso "false" (Usar despues de checkUnusedInstructions)*/
    bool programhasUnusedInstructions() const;

    /* Destructor */
    ~Graph();

 private:
    void _DFS(const int nodeNumber);
};

#endif  // GRAPH_H_
