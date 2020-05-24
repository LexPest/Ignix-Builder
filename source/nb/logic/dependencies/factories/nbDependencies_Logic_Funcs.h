//
// Created by Alexey Mihailov on 16/05/2020.
//

#ifndef NERP_BUILDER_WX_NBDEPENDENCIES_LOGIC_FUNCS_H
#define NERP_BUILDER_WX_NBDEPENDENCIES_LOGIC_FUNCS_H


#include <yaml-cpp/node/node.h>
#include <memory>

namespace nerp {

//    template<typename TARGET_T>
//    void fillDependenciesListOnTarget_s(nbTargetsContainedDependency<TARGET_T>& parTargetDep, const YAML::Node &parTargetsNode) {
//        std::list<std::pair<std::string, std::shared_ptr<TARGET_T>>>& depTargets = &parTargetDep.depTargets;
//
//        auto addPairFunc = [&] (const std::string& depTargetString) {
//            parTargetDep.push_back(std::pair<std::string, std::shared_ptr<TARGET_T>>(depTargetString, nullptr));
//        };
//
//        if (parTargetsNode.IsSequence()){
//            for (size_t i = 0; i < parTargetsNode.size(); i++){
//                addPairFunc(parTargetsNode[i].as<std::string>());
//            }
//        } else {
//            addPairFunc(parTargetsNode.as<std::string>());
//        }
//    }


    //std::shared_ptr<nbFeatureDependency> constructFeatureDependency(const YAML::Node &parNode);
    //std::shared_ptr<nbPropertyDependency> constructPropertyDependency(const YAML::Node &parNode);
}


#endif //NERP_BUILDER_WX_NBDEPENDENCIES_LOGIC_FUNCS_H
