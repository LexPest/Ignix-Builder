//
// Created by Alexey Mihailov
//

#ifndef NERP_BUILDER_NBWXPROJECTOPENEDINFORM_H
#define NERP_BUILDER_NBWXPROJECTOPENEDINFORM_H


#include "nbWxForms.h"
#include "nbFormMainExt.h"
#include "../logic/nbOpenedProjectHandler.h"
#include "nbWxFormElementsBlockingMechanism.h"
#include <wx/sharedptr.h>
#include <future>
#include <memory>

class nbFormMainExt;

class nbWxProjectOpenedInForm  {
public:
    nbWxProjectOpenedInForm(const wxWeakRef<nbFormMainExt> &linkedForm);

    void loadProject(const std::string &parLoadPath);



private:
    wxWeakRef<nbFormMainExt> linkedForm;
    nbWxFormElementsBlockingMechanism formControlsBlockingMech;
    std::shared_ptr<nbOpenedProjectHandler> cOpenedProject;

    

    std::future<void> F_ProjectLoading;
};


#endif //NERP_BUILDER_NBWXPROJECTOPENEDINFORM_H
