#include "panel.h"

Panel::Panel(wxWindow* parent) : wxPanel(parent, -1) 
{
	auto vbox = new wxBoxSizer(wxVERTICAL);
	wxString choices[] {wxT("Text"), wxT("Circle")};
	

	auto hbox0 = new wxBoxSizer(wxHORIZONTAL);
	radio_box = new wxRadioBox(this, -1, wxT("Choices"), wxDefaultPosition, wxDefaultSize,
		                            WXSIZEOF(choices), choices, 1, wxRA_SPECIFY_COLS);

	hbox0->Add(radio_box);

	auto hbox1 = new wxBoxSizer(wxHORIZONTAL);
	auto m_usernameLabel = new wxStaticText(this, wxID_ANY, wxT("Name: "),
		wxDefaultPosition, wxSize(70, -1));
	hbox1->Add(m_usernameLabel, 0);

	draw_text = new wxTextCtrl(this, wxID_ANY);
	hbox1->Add(draw_text, 0);

	//create a button
	auto draw_button = new wxButton(this, -1, wxT("Draw"));
	draw_button->Bind(wxEVT_BUTTON, &Panel::OnDraw, this);

	hbox1->Add(draw_button);

	vbox->Add(hbox0, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
	vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
	SetSizer(vbox);
}

void Panel::OnDraw(wxCommandEvent & event)
{
	std::unique_ptr<Shape> shape;
	auto cdc = new wxClientDC(this);
	if (radio_box->GetSelection() == 0)//draw text
	{
		shape = std::make_unique<Text>(cdc, draw_text->GetValue().ToStdString(), Point(300, 300));

		shape->draw();
	}
}

