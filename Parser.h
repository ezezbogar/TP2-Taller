#ifndef PARSER_H_
#define PARSER_H_

#include "Label.h"
#include "Graph.h"
#include <vector>
#include <string>

class Parser {
 private:
    std::vector<Label> labels;
    int cantidadNodos;

 public:
    /* Constructor */
    Parser();

    /* Constructor por copia borrado */
    Parser(const Parser& parser) = delete;

    /* Asignacion por copia borrado */
    Parser operator=(const Parser& parser) = delete;

    /* Analiza el archivo eBPF y extrae los labels */
    void getLabels(std::fstream& file);

    /* Modela el archivo eBPF como un grafo dirigido */
    void loadGraph(Graph& graph, std::fstream& file);

    /* Devuelve el numero de nodo en el que se encuentra el label indicado */
    int getLabelNodeNumber(const std::string& name);

    /* Devuelve la cantidad de nodos (Instrucciones) */
    int getNodesAmount() const;

    /* Destructor */
    ~Parser();

private:
    /* Devuelve "true" si el string es algun jumpcode */
    bool isJumpCode(const std::string& instruction) const;

    /* Devuelve "true" si el string es igual a "ret" */
    bool isRetCode(const std::string& instruction) const;
};

#endif  // PARSER_H_
