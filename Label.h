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

    /* Constructor por movimiento */
    Label(Label&& label) noexcept;

    /* Constructor por copia borrado */
    Label(const Label& label) = delete;

    /* Asignacion por copia borrado */
    Label operator=(const Label& label) = delete;

    /* Devuelve un string con el nombre del label */
    std::string getLabelName();

    /* Devuelve el numero de nodo en el que se encuentra el label */
    int getNodeNumber();

    /* Destructor */
    ~Label();
};


#endif  // LABEL_H_
