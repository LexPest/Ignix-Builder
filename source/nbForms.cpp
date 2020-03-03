///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "nbForms.h"

#include "res/noun_Error_1965707.png.h"
#include "res/noun_Seal_N3E.png.h"
#include "res/noun_build_1178847.png.h"

///////////////////////////////////////////////////////////////////////////

nbFormMain::nbFormMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 850,530 ), wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	m_menubar1 = new wxMenuBar( 0 );
	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_propertyGrid9 = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_BOLD_MODIFIED|wxPG_DEFAULT_STYLE|wxPG_SPLITTER_AUTO_CENTER|wxTAB_TRAVERSAL);
	m_propertyGrid9->SetExtraStyle( wxPG_EX_NATIVE_DOUBLE_BUFFERING );
	m_propertyGrid9->SetMinSize( wxSize( -1,350 ) );

	m_propertyGridItem8 = m_propertyGrid9->Append( new wxPropertyCategory( wxT("Name Cat Test"), wxT("Name Cat Test") ) );
	m_propertyGridItem9 = m_propertyGrid9->Append( new wxLongStringProperty( wxT("Config Elem 1"), wxT("Config Elem 1") ) );
	m_propertyGridItem1 = m_propertyGrid9->Append( new wxStringProperty( wxT("Config Elem 2"), wxT("Config Elem 2") ) );
	m_propertyGridItem2 = m_propertyGrid9->Append( new wxBoolProperty( wxT("Config Elem 3"), wxT("Config Elem 3") ) );
	m_propertyGridItem3 = m_propertyGrid9->Append( new wxFloatProperty( wxT("Config Elem 4"), wxT("Config Elem 4") ) );
	m_propertyGridItem4 = m_propertyGrid9->Append( new wxImageFileProperty( wxT("Config Elem L"), wxT("Config Elem L") ) );
	m_propertyGridItem5 = m_propertyGrid9->Append( new wxSystemColourProperty( wxT("Config Elem C"), wxT("Config Elem C") ) );
	m_propertyGridItem6 = m_propertyGrid9->Append( new wxDirProperty( wxT("Config Elem D"), wxT("Config Elem D") ) );
	m_propertyGridItem7 = m_propertyGrid9->Append( new wxFileProperty( wxT("Config Elem LS"), wxT("Config Elem LS") ) );
	bSizer3->Add( m_propertyGrid9, 3, wxALL|wxEXPAND, 5 );

	m_richText1 = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	m_richText1->SetMinSize( wxSize( 400,200 ) );

	bSizer3->Add( m_richText1, 4, wxEXPAND | wxALL, 5 );


	bSizer2->Add( bSizer3, 2, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, noun_Seal_N3E_png_to_wx_bitmap(), wxDefaultPosition, wxDefaultSize, 0 );
	m_bitmap2->SetMaxSize( wxSize( 32,25 ) );

	bSizer5->Add( m_bitmap2, 0, wxALL, 5 );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Path to N3E source directory:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer5->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );

	m_dirPicker1 = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	m_dirPicker1->SetMinSize( wxSize( 400,-1 ) );

	bSizer5->Add( m_dirPicker1, 1, wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Status:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );

	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, noun_Error_1965707_png_to_wx_bitmap(), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_bitmap1, 0, wxALL, 5 );


	bSizer2->Add( bSizer5, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_bitmap3 = new wxStaticBitmap( this, wxID_ANY, noun_build_1178847_png_to_wx_bitmap(), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_bitmap3, 0, wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Path to current N3E build receipt:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALIGN_CENTER|wxALL, 5 );

	m_filePicker2 = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer6->Add( m_filePicker2, 1, wxALL, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Save Receipt"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button3, 0, wxALL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Build N3E"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button2, 0, wxALL, 5 );


	bSizer2->Add( bSizer6, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );
}

nbFormMain::~nbFormMain()
{
}
