//
// Copyright (c) Alexey "LexPest" Mihailov. All rights reserved.
//
// Use of this source code is governed by an MIT license
// that can be found in the LICENSE file.

#ifndef NERP_BUILDER_WX_NBDEP_AVAILABLEON_FUNCS_H
#define NERP_BUILDER_WX_NBDEP_AVAILABLEON_FUNCS_H

#include <string>
#include <list>
#include <memory>

namespace nerp {
    template<typename TARGET_T>
    using TList = std::list<std::pair<std::string, std::shared_ptr<TARGET_T>>>;

    template<typename TARGET_T>
    static inline std::string hGetDependsOnMessage(const TList<TARGET_T>& parDepsList, std::string parMessageBegin) {
        std::string retString = std::move(parMessageBegin);
        for (auto it : parDepsList){
            retString += it.first + ' ';
        }
        return std::move(retString);
    }

    template<typename TARGET_T>
    static inline bool hTryResolve(const TList<TARGET_T>& parDepsList, std::function<std::shared_ptr<TARGET_T>(const std::string&)> parResolveFunc) {
        bool retResult = true;
        for (auto it : parDepsList){
            if (it.second == nullptr){
                it.second = parResolveFunc(it.first);
                if (it.second == nullptr){
                    retResult = false;
                }
            }
        }

        return retResult;
    }

    template<typename TARGET_T>
    static inline bool hIsResolved(const TList<TARGET_T>& parDepsList){
        for (auto it : parDepsList){
            if (it.second == nullptr){
                return false;
            }
        }
        return true;
    }

    template<typename TARGET_T>
    static inline bool hCheckSatisfiedAndSetValueAndAvailable(const TList<TARGET_T>& parDepsList,
            std::function<bool(const std::shared_ptr<TARGET_T>)> parIsSatisfiedFunc,
            std::function<void(bool)> parSetValueAndAvailableFunc){
        bool isSatisfied = true;
        for (auto it : parDepsList){
            if (!parIsSatisfiedFunc(it.second)){
                isSatisfied = false;
                break;
            }
        }
        parSetValueAndAvailableFunc(isSatisfied);
        return isSatisfied;
    }
}



#endif //NERP_BUILDER_WX_NBDEP_AVAILABLEON_FUNCS_H
