//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBWXFORMELEMENTSBLOCKINGMECHANISM_H
#define NERP_BUILDER_NBWXFORMELEMENTSBLOCKINGMECHANISM_H

#include <unordered_map>
#include <map>
#include <list>
#include <set>
#include <wx/control.h>
#include "nbWxFormElementBlockObject.h"
#include <wx/sharedptr.h>
#include <wx/weakref.h>


class nbWxFormElementsBlockingMechanism {
    typedef std::shared_ptr<std::set<std::shared_ptr<nbWxFormElementBlockObject>>> BlockObjectsList;

private:
    std::map<wxWeakRef<wxControl>, BlockObjectsList> BlocksData;
public:
    std::shared_ptr<nbWxFormElementBlockObject> blockElement(wxWeakRef<wxControl> parElem);
    void unblockElement(wxWeakRef<wxControl> parElem, std::shared_ptr<nbWxFormElementBlockObject> parBlockObj);

    std::shared_ptr<std::list<std::shared_ptr<nbWxFormElementBlockObject>>> blockElements(std::list<wxWeakRef<wxControl>> parElems);
    void unblockElements(std::shared_ptr<std::list<wxWeakRef<wxControl>>> parElems, std::shared_ptr<std::list<std::shared_ptr<nbWxFormElementBlockObject>>> parBlockObjs);
};


#endif //NERP_BUILDER_NBWXFORMELEMENTSBLOCKINGMECHANISM_H
