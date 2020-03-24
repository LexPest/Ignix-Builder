//
// Created by Alexey Mihailov
//

#include "nbWxProjectOpenedInForm.h"
#include "../logic/nbProjectWorker.h"
#include <future>

nbWxProjectOpenedInForm::nbWxProjectOpenedInForm(const wxWeakRef<nbFormMainExt> &linkedForm) : linkedForm(linkedForm) {}

void nbWxProjectOpenedInForm::loadProject(const std::string &parLoadPath)
{
    auto uiBlocks = formControlsBlockingMech.blockElement(wx_static_cast(wxWeakRef<wxFrame>, linkedForm), linkedForm->m_dirPicker_projectPath);

    F_ProjectLoading = std::async(std::launch::async, &nbProjectWorker::loadProject, [this, uiBlocks](nbReqProjectLoadingResult result){
        formControlsBlockingMech.unblockElement(wx_static_cast(wxWeakRef<wxFrame>, linkedForm), linkedForm->m_dirPicker_projectPath, uiBlocks);
        }, parLoadPath);
}
