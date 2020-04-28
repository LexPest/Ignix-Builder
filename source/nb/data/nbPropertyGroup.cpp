//
// Created by Alexey Mihailov
//

#include "nbPropertyGroup.h"
using namespace nerp;
nbPropertyGroup::nbPropertyGroup(const std::string &name) : CName(name) {}

std::shared_ptr<nbProperty> nbPropertyGroup::getPropByName(const std::string &parName) {
    for (auto it : Props){
        if (it->Name == parName){
            return it;
        }
    }
    return nullptr;
}
