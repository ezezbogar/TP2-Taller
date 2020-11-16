#include "eBPFVerifier.h"
#include <string>
#include <fstream>
#include "Parser.h"
#include "Graph.h"

void eBPFVerifier::verificar() {
    std::string filename;
    while ( this->repository.getFile(filename) ) {
        _verificar(filename);
    }
}

void eBPFVerifier::_verificar(const std::string& fileName) {
    std::fstream src;
    src.open(fileName);
    Parser parser;
    parser.getLabels(src);
    Graph graph(parser.getNodesAmount());
    parser.loadGraph(graph, src);
    graph.DFS();
    graph.checkUnusedInstructions();
    _saveResults(fileName, graph);
    src.close();
}

void eBPFVerifier::_saveResults(const std::string& fileName,
                                const Graph &graph) {
    if ( graph.programhasCicles() ) {
        this->results.loadResult(fileName, "FAIL: cycle detected");
    } else if ( graph.programhasUnusedInstructions() ) {
        this->results.loadResult
        (fileName, "FAIL: unused instructions detected");
    } else {
        this->results.loadResult(fileName, "GOOD");
    }
}

eBPFVerifier::~eBPFVerifier() {}
