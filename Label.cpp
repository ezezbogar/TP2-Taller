#include "Label.h"

Label::Label(const std::string labelName, const int nodeNumber) {
    this->labelName = labelName;
    this->nodeNumber = nodeNumber;
}

std::string Label::getLabelName() {
    return this->labelName;
}

int Label::getNodeNumber() {
    return this->nodeNumber;
}

Label::~Label() {}