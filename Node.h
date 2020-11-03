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

    /* Marca el nodo como visitado */
    void setNodeVisited();

    /* Devuelve un bool que responde a la pregunta: Fue visitado? */
    bool isVisited();

    /* Crea una arista con origen en el objeto que llama al metodo y
     * destino en el nodo especificado con el numero */
    void setEdge(int nodeNumber);

    /* Devuelve un bool que es true en el caso de que exista una arista
     * con origen en el nodo que llama al metodo y destino en el nodo
     * especificado con el numero. Devuelve false en el otro caso */
    bool getEdge(int edgeNumber);

    /* Destructor */
    ~Node();
};


#endif  // NODE_H_
