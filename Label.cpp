#include "Label.h"
#include <utility>

Label::Label(const std::string& labelName, const int nodeNumber) {
    this->labelName = labelName;
    this->nodeNumber = nodeNumber;
}

Label::Label(Label &&label) noexcept {
    this->labelName = std::move(label.labelName);
    this->nodeNumber = label.nodeNumber;
    label.nodeNumber = -1;
}

std::string Label::getLabelName() {
    return this->labelName;
}

int Label::getNodeNumber() {
    return this->nodeNumber;
}

Label::~Label() {}
