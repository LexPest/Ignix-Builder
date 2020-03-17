//
// Created by Alexey Mihailov on 2020-03-18.
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
