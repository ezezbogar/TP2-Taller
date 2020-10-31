#ifndef _PARSER_H
#define _PARSER_H

#include "Label.h"
#include <vector>

class Parser {
private:
    //FILE* fd;
    std::vector<Label> labels;
    int cantidadNodos;

public:
    /* Constructor */
    Parser();

    void getLabels(std::fstream& file);

    void _showLabels(); //Borrar

    /* Destructor */
    ~Parser();
};



#endif //_PARSER_H
