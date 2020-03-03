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
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/button.h>
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
		wxRichTextCtrl* m_richText1;
		wxStaticBitmap* m_bitmap2;
		wxStaticText* m_staticText1;
		wxDirPickerCtrl* m_dirPicker1;
		wxStaticText* m_staticText2;
		wxStaticBitmap* m_bitmap1;
		wxStaticBitmap* m_bitmap3;
		wxStaticText* m_staticText3;
		wxFilePickerCtrl* m_filePicker2;
		wxButton* m_button3;
		wxButton* m_button2;

	public:

		nbFormMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Nerp-Builder GUI"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 857,530 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~nbFormMain();

};

