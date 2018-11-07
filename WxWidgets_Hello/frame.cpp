#include "frame.h"
#include "panel.h"
#include "menu_bar.h"

Frame::Frame()
	: wxFrame(NULL, wxID_ANY, "Hello World", wxDefaultPosition, wxSize(1280, 760))
{
	auto panel = new Panel(this);
	
	auto bar = new MenuBar;
	SetMenuBar(bar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
	Bind(wxEVT_MENU, &Frame::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &Frame::OnHello, this, ID_HELLO);
	Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);
	
}

void Frame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("Hello world!",
		"About Hello World", wxOK | wxICON_INFORMATION);
}

void Frame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void Frame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello wxWidgets!");
}