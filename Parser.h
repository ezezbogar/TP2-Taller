#ifndef PARSER_H_
#define PARSER_H_

#include "Label.h"
#include "Graph.h"
#include <vector>

class Parser {
 private:
    std::vector<Label> labels;
    int cantidadNodos;

 public:
    /* Constructor */
    Parser();

    void getLabels(std::fstream& file);

    void loadGraph(Graph& graph, std::fstream& file);

    int getLabelNodeNumber(std::string name);

    int getNodesAmount();

    /* Destructor */
    ~Parser();
};

#endif  // PARSER_H_
