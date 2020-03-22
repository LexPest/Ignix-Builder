//
// Created by Alexey Mihailov
//

#include "IterVersion.h"

IterVersion::IterVersion(unsigned long long int value) : Value(value) {}

bool IterVersion::operator==(const IterVersion &rhs) const {
    return Value == rhs.Value;
}

bool IterVersion::operator!=(const IterVersion &rhs) const {
    return !(rhs == *this);
}

bool IterVersion::operator<(const IterVersion &rhs) const {
    return Value < rhs.Value;
}

bool IterVersion::operator>(const IterVersion &rhs) const {
    return rhs < *this;
}

bool IterVersion::operator<=(const IterVersion &rhs) const {
    return !(rhs < *this);
}

bool IterVersion::operator>=(const IterVersion &rhs) const {
    return !(*this < rhs);
}
