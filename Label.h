#ifndef _LABEL_H
#define _LABEL_H

#include <string>

class Label {
private:
    std::string labelName;
    int nodeNumber;

public:
    /* Constructor */
    Label(const std::string labelName, const int nodeNumber);

    std::string getLabelName();

    int getNodeNumber();

    /* Destructor */
    ~Label();


};


#endif //_LABEL_H
