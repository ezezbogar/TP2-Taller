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

    std::string getLabelName();

    int getNodeNumber();

    /* Destructor */
    ~Label();
};


#endif  // LABEL_H_
