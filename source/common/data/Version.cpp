//
// Created by Alexey Mihailov
//

#include "Version.h"

Version::Version(unsigned int major, unsigned int minor) : Major(major), Minor(minor) {}

bool Version::operator==(const Version &rhs) const {
    return Major == rhs.Major &&
           Minor == rhs.Minor;
}

bool Version::operator!=(const Version &rhs) const {
    return !(rhs == *this);
}

bool Version::operator<(const Version &rhs) const {
    if (Major < rhs.Major)
        return true;
    if (rhs.Major < Major)
        return false;
    return Minor < rhs.Minor;
}

bool Version::operator>(const Version &rhs) const {
    return rhs < *this;
}

bool Version::operator<=(const Version &rhs) const {
    return !(rhs < *this);
}

bool Version::operator>=(const Version &rhs) const {
    return !(*this < rhs);
}
