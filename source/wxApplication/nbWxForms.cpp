///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "nbWxForms.h"

#include "../res/noun_Error_1965707.png.h"
#include "../res/noun_Seal_N3E.png.h"

///////////////////////////////////////////////////////////////////////////

nbFormMain::nbFormMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 850,530 ), wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );

	m_menubar1 = new wxMenuBar( 0 );
	m_menu5 = new wxMenu();
	m_menubar1->Append( m_menu5, wxT("About") );

	m_menu4 = new wxMenu();
	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( m_menu4, wxID_ANY, wxString( wxT("✪ Update&Merge Project Templates") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem9 );

	m_menubar1->Append( m_menu4, wxT("✪ Dev") );

	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Template Recipe 1") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem1 );

	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Template Recipe 2") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem2 );

	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem3 );

	m_menubar1->Append( m_menu2, wxT("New Recipe From Template") );

	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Save") ) + wxT('\t') + wxT("CTRL+S"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem4 );

	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Save As...") ) + wxT('\t') + wxT("CTRL+SHIFT+S"), wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem5 );

	m_menu1->AppendSeparator();

	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("User Recipe 1") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem6 );

	wxMenuItem* m_menuItem7;
	m_menuItem7 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("User Recipe 2") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem7 );

	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem8 );

	m_menubar1->Append( m_menu1, wxT("Selected Recipe: %NAME%") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Enable/Disable Features, select to show Properties:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	m_staticText4->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Lucida Grande") ) );

	bSizer2->Add( m_staticText4, 0, wxALL, 2 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_treeListCtrl2 = new wxTreeListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTL_CHECKBOX|wxTL_DEFAULT_STYLE );
	m_treeListCtrl2->AppendColumn( wxT("Feature"), wxCOL_WIDTH_AUTOSIZE, wxALIGN_LEFT, wxCOL_RESIZABLE );
	m_treeListCtrl2->AppendColumn( wxT("Requires"), wxCOL_WIDTH_AUTOSIZE, wxALIGN_LEFT, wxCOL_RESIZABLE );

	bSizer3->Add( m_treeListCtrl2, 4, wxEXPAND | wxALL, 5 );

	m_richText1 = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	m_richText1->SetMinSize( wxSize( 400,200 ) );

	bSizer3->Add( m_richText1, 6, wxEXPAND | wxALL, 5 );


	bSizer2->Add( bSizer3, 3, wxEXPAND, 2 );

	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("Edit selected Feature Properties:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	m_staticText41->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Lucida Grande") ) );

	bSizer2->Add( m_staticText41, 0, wxALL, 2 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );

	m_propertyGrid9 = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_BOLD_MODIFIED|wxPG_DEFAULT_STYLE|wxPG_SPLITTER_AUTO_CENTER|wxTAB_TRAVERSAL);
	m_propertyGrid9->SetExtraStyle( wxPG_EX_NATIVE_DOUBLE_BUFFERING );
	m_propertyGrid9->SetMinSize( wxSize( -1,150 ) );

	m_propertyGridItem8 = m_propertyGrid9->Append( new wxPropertyCategory( wxT("Name Cat Test"), wxT("Name Cat Test") ) );
	m_propertyGridItem9 = m_propertyGrid9->Append( new wxLongStringProperty( wxT("Config Elem 1"), wxT("Config Elem 1") ) );
	m_propertyGridItem1 = m_propertyGrid9->Append( new wxStringProperty( wxT("Config Elem 2"), wxT("Config Elem 2") ) );
	m_propertyGridItem2 = m_propertyGrid9->Append( new wxBoolProperty( wxT("Config Elem 3"), wxT("Config Elem 3") ) );
	m_propertyGridItem3 = m_propertyGrid9->Append( new wxFloatProperty( wxT("Config Elem 4"), wxT("Config Elem 4") ) );
	m_propertyGridItem4 = m_propertyGrid9->Append( new wxImageFileProperty( wxT("Config Elem L"), wxT("Config Elem L") ) );
	m_propertyGridItem5 = m_propertyGrid9->Append( new wxSystemColourProperty( wxT("Config Elem C"), wxT("Config Elem C") ) );
	m_propertyGridItem6 = m_propertyGrid9->Append( new wxDirProperty( wxT("Config Elem D"), wxT("Config Elem D") ) );
	m_propertyGridItem7 = m_propertyGrid9->Append( new wxFileProperty( wxT("Config Elem LS"), wxT("Config Elem LS") ) );
	bSizer51->Add( m_propertyGrid9, 4, wxALL|wxEXPAND, 5 );

	m_richText2 = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	bSizer51->Add( m_richText2, 6, wxEXPAND | wxALL, 5 );


	bSizer2->Add( bSizer51, 2, wxEXPAND, 2 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, noun_Seal_N3E_png_to_wx_bitmap(), wxDefaultPosition, wxDefaultSize, 0 );
	m_bitmap2->SetMaxSize( wxSize( 32,25 ) );

	bSizer5->Add( m_bitmap2, 0, wxALL, 5 );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Path to project source directory:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer5->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );

	m_dirPicker_projectPath = new wxDirPickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	m_dirPicker_projectPath->SetMinSize( wxSize( 400,-1 ) );

	bSizer5->Add( m_dirPicker_projectPath, 1, wxALL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Do Build"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button2, 0, wxALL, 5 );


	bSizer2->Add( bSizer5, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Welcome to Nerp-Builder. Select the target project source directory, then choose the recipe settings using (upper) application menu."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Lucida Grande") ) );

	bSizer6->Add( m_staticText3, 0, wxALIGN_CENTER|wxALL, 5 );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer6->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Status:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );

	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, noun_Error_1965707_png_to_wx_bitmap(), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_bitmap1, 0, wxALL, 5 );


	bSizer2->Add( bSizer6, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_dirPicker_projectPath->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( nbFormMain::sourceDirChanged ), NULL, this );
}

nbFormMain::~nbFormMain()
{
	// Disconnect Events
	m_dirPicker_projectPath->Disconnect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( nbFormMain::sourceDirChanged ), NULL, this );

}
