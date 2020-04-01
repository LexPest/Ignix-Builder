//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_ITERVERSION_H
#define NERP_BUILDER_ITERVERSION_H

#include <string>

struct IterVersion {
    unsigned long long Value;

    bool operator<(const IterVersion &rhs) const;

    bool operator>(const IterVersion &rhs) const;

    bool operator<=(const IterVersion &rhs) const;

    bool operator>=(const IterVersion &rhs) const;

    IterVersion(unsigned long long int value);
    IterVersion(const std::string& parStr);

    bool operator==(const IterVersion &rhs) const;

    bool operator!=(const IterVersion &rhs) const;
};


#endif //NERP_BUILDER_ITERVERSION_H
