///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/treelist.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/sizer.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/statbmp.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class nbFormMain
///////////////////////////////////////////////////////////////////////////////
class nbFormMain : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_menu5;
		wxMenu* m_menu4;
		wxMenu* m_menu2;
		wxMenu* m_menu1;
		wxTreeListCtrl* m_treeListCtrl2;
		wxRichTextCtrl* m_richText1;
		wxStaticText* m_staticText41;
		wxPropertyGrid* m_propertyGrid9;
		wxPGProperty* m_propertyGridItem8;
		wxPGProperty* m_propertyGridItem9;
		wxPGProperty* m_propertyGridItem1;
		wxPGProperty* m_propertyGridItem2;
		wxPGProperty* m_propertyGridItem3;
		wxPGProperty* m_propertyGridItem4;
		wxPGProperty* m_propertyGridItem5;
		wxPGProperty* m_propertyGridItem6;
		wxPGProperty* m_propertyGridItem7;
		wxRichTextCtrl* m_richText2;
		wxStaticBitmap* m_bitmap2;
		wxStaticText* m_staticText1;
		wxButton* m_button2;
		wxStaticText* m_staticText3;
		wxPanel* m_panel2;
		wxStaticText* m_staticText2;
		wxStaticBitmap* m_bitmap1;

		// Virtual event handlers, overide them in your derived class
		virtual void sourceDirChanged( wxFileDirPickerEvent& event ) { event.Skip(); }


	public:
		wxStaticText* m_staticText4;
		wxDirPickerCtrl* m_dirPicker_projectPath;

		nbFormMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Nerp-Builder GUI"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 857,749 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~nbFormMain();

};

