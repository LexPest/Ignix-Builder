//
// Created by Alexey Mihailov
//

#include "nbWxFormElementsBlockingMechanism.h"
#include <algorithm>

std::shared_ptr<nbWxFormElementBlockObject>
nbWxFormElementsBlockingMechanism::blockElement(wxWeakRef<wxControl> parElem) {
    std::shared_ptr<nbWxFormElementBlockObject> retBlockObj = std::make_shared<nbWxFormElementBlockObject>();
    BlockObjectsList parTargetList = nullptr;

    if (BlocksData.count(parElem) <= 0){
        parTargetList = BlocksData[parElem];
    } else {
        parTargetList = std::make_shared<std::set<std::shared_ptr<nbWxFormElementBlockObject>>>();
        BlocksData.insert(std::pair<wxWeakRef<wxControl>, BlockObjectsList>(parElem, parTargetList));
    }

    if (parTargetList->size() <= 0){
        parElem->Disable();
    }

    parTargetList->insert(retBlockObj);

    return retBlockObj;
}

void nbWxFormElementsBlockingMechanism::unblockElement(wxWeakRef<wxControl> parElem,
                                                       std::shared_ptr<nbWxFormElementBlockObject> parBlockObj) {
    if (BlocksData.count(parElem) > 0){
        BlockObjectsList parTargetList = BlocksData[parElem];
        if (parTargetList->count(parBlockObj) > 0){
            parTargetList->erase(parBlockObj);
        }

        if (parTargetList->size() <= 0){
            parElem->Enable();
        }
    }
}

std::shared_ptr<std::list<std::shared_ptr<nbWxFormElementBlockObject>>>
nbWxFormElementsBlockingMechanism::blockElements(std::list<wxWeakRef<wxControl>> parElems) {
    auto retBlockObjects = std::make_shared<std::list<std::shared_ptr<nbWxFormElementBlockObject>>>();
    for (auto eElem : parElems){
        retBlockObjects->emplace_back(blockElement(eElem));
    }
    return retBlockObjects;
}

void nbWxFormElementsBlockingMechanism::unblockElements(std::shared_ptr<std::list<wxWeakRef<wxControl>>> parElems,
                                                        std::shared_ptr<std::list<std::shared_ptr<nbWxFormElementBlockObject>>> parBlockObjs) {
    while (parElems->size() > 0){
        auto curControl = parElems->front();
        auto curBlockObj = parBlockObjs->front();

        unblockElement(curControl, curBlockObj);

        parElems->pop_front();
        parBlockObjs->pop_front();
    }
}

