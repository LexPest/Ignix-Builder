//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_VERSION_H
#define NERP_BUILDER_VERSION_H


struct Version {
    unsigned int Major;
    unsigned int Minor;

    Version(unsigned int major, unsigned int minor);

    bool operator==(const Version &rhs) const;

    bool operator!=(const Version &rhs) const;

    bool operator<(const Version &rhs) const;

    bool operator>(const Version &rhs) const;

    bool operator<=(const Version &rhs) const;

    bool operator>=(const Version &rhs) const;
};


#endif //NERP_BUILDER_VERSION_H
