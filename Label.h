#ifndef LABEL_H_
#define LABEL_H_

#include <string>

class Label {
 private:
    std::string labelName;
    int nodeNumber;

 public:
    /* Constructor */
    Label(const std::string labelName, const int nodeNumber);

    /* Devuelve un string con el nombre del label */
    std::string getLabelName();

    /* Devuelve el numero de nodo en el que se encuentra el label */
    int getNodeNumber();

    /* Destructor */
    ~Label();
};


#endif  // LABEL_H_
