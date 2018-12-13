#include "panel.h"

Panel::Panel(wxWindow* parent)
	: wxPanel(parent, -1)
{
	manager = std::make_unique<TicTacToeManager>();

	auto vbox = new wxBoxSizer(wxVERTICAL);
	auto top_horizontal_box = get_top_box_sizer();

	auto mid_horizontal_box = get_mid_box_sizer();
	tic_tac_toe_grid_3 = get_grid_sizer(3);
	tic_tac_toe_grid_3->Show(false);
	tic_tac_toe_grid_4 = get_grid_sizer(4);
	tic_tac_toe_grid_4->Show(false);

	for (auto& board : manager->get_games())
	{
		history_list_box->Append("Game");
	}

	vbox->Add(top_horizontal_box, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
	vbox->Add(mid_horizontal_box, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
	vbox->Add(tic_tac_toe_grid_3, 0, wxALIGN_RIGHT | wxTOP | wxRIGHT | wxBOTTOM, 10);
	vbox->Add(tic_tac_toe_grid_4, 0, wxALIGN_RIGHT | wxTOP | wxRIGHT | wxBOTTOM, 10);

	set_winner_labels();

	SetSizer(vbox);
}

wxBoxSizer * Panel::get_top_box_sizer()
{
	wxString game_type_choices[]{ wxT("Tic Tac Toe 3"), wxT("Tic Tac Toe 4") };
	wxString first_player_choices[]{ wxT("X"), wxT("O") };

	auto hbox0 = new wxBoxSizer(wxHORIZONTAL);
	game_type_radio = new wxRadioBox(this, -1, wxT("Game Type"), wxDefaultPosition, wxDefaultSize,
		WXSIZEOF(game_type_choices), game_type_choices, 1, wxRA_SPECIFY_COLS);

	first_player_radio = new wxRadioBox(this, -1, wxT("First Player"), wxDefaultPosition,
		wxDefaultSize, WXSIZEOF(first_player_choices), first_player_choices, 1, wxRA_SPECIFY_COLS);

	history_list_box = new wxListBox(this, -1, wxPoint(-1, -1), wxSize(-1, -1));
	history_list_box->Bind(wxEVT_LISTBOX, &Panel::on_list_box_click, this);

	auto hbox1 = new wxBoxSizer(wxVERTICAL);

	auto label1 = new wxStaticText(this, wxID_ANY, wxT("X: "),
		wxDefaultPosition, wxSize(70, -1));
	auto label2 = new wxStaticText(this, wxID_ANY, wxT("O: "),
		wxDefaultPosition, wxSize(70, -1));
	auto label3 = new wxStaticText(this, wxID_ANY, wxT("C: "),
		wxDefaultPosition, wxSize(70, -1));

	x_winner_label = new wxTextCtrl(this, wxID_ANY);
	o_winner_label = new wxTextCtrl(this, wxID_ANY);
	c_winner_label = new wxTextCtrl(this, wxID_ANY);

	hbox0->Add(game_type_radio);
	hbox0->Add(first_player_radio);
	hbox0->Add(history_list_box);
	hbox1->Add(label1);
	hbox1->Add(x_winner_label);
	hbox1->Add(label2);
	hbox1->Add(o_winner_label);
	hbox1->Add(label3);
	hbox1->Add(c_winner_label);
	hbox0->Add(hbox1);

	return hbox0;
}

wxBoxSizer * Panel::get_mid_box_sizer()
{
	auto hbox1 = new wxBoxSizer(wxHORIZONTAL);
	auto winner_label = new wxStaticText(this, wxID_ANY, wxT("Winner: "),
		wxDefaultPosition, wxSize(70, -1));
	hbox1->Add(winner_label, 0);

	winner_text = new wxTextCtrl(this, wxID_ANY);
	winner_text->Disable();
	hbox1->Add(winner_text, 1);

	start_button = new wxButton(this, -1, wxT("Start"));
	start_button->Bind(wxEVT_BUTTON, &Panel::on_start_button_click, this);
	hbox1->Add(start_button);

	return hbox1;
}

wxGridSizer * Panel::get_grid_sizer(int size)
{
	auto gs = new wxGridSizer(size, size, size, size);

	for (int i = 0; i < size*size; i++)
	{
		auto btn = new wxButton(this, -1, std::to_string(i + 1));
		btn->Bind(wxEVT_BUTTON, &Panel::on_peg_button_click, this);
		gs->Add(btn, 0, wxEXPAND);
	}

	return gs;
}


void Panel::on_start_button_click(wxCommandEvent & event)
{
	set_button_properties(tic_tac_toe_grid_3);
	set_button_properties(tic_tac_toe_grid_4);

	if (game_type_radio->GetSelection() == 0)
	{
		board = manager->get_game(tic_tac_toe_3);
		tic_tac_toe_grid_4->Show(false);
		tic_tac_toe_grid_3->Show(true);
	}
	else if (game_type_radio->GetSelection() == 1)
	{
		board = manager->get_game(tic_tac_toe_4);
		tic_tac_toe_grid_3->Show(false);
		tic_tac_toe_grid_4->Show(true);
	}

	if (first_player_radio->GetSelection() == 0)
	{
		board->start_game("X");
	}
	else if (first_player_radio->GetSelection() == 1)
	{
		board->start_game("O");
	}

	auto btn = dynamic_cast<wxButton*>(event.GetEventObject());
	btn->Disable();
	this->Layout();
}

void Panel::on_peg_button_click(wxCommandEvent & event)
{
	auto btn = dynamic_cast<wxButton*>(event.GetEventObject());
	btn->Disable();
	auto val = btn->GetLabel();
	btn->SetLabel(board->get_player());
	board->mark_board(std::stoi(val.ToStdString()));

	if (board->game_over())
	{
		wxMessageBox(wxT("Winner!"), wxT("TicTacToe"), wxICON_INFORMATION);
		history_list_box->Append("game");
		winner_text->SetLabel(board->get_winner());
		start_button->Enable();
		manager->save_game(std::move(board));
		set_winner_labels();
	}
}

void Panel::on_list_box_click(wxCommandEvent& event)
{
	
	std::vector<std::unique_ptr<TicTacToeBoard>>const& boards = manager->get_games();
	
	std::unique_ptr<TicTacToeBoard>const& board = boards[history_list_box->GetSelection()];

	wxGridSizer* sizer;

	if (board->get_pegs().size() == 9)
	{
		sizer = tic_tac_toe_grid_3;
		tic_tac_toe_grid_4->Show(false);
		tic_tac_toe_grid_3->Show(true);

	}
	else
	{
		sizer = tic_tac_toe_grid_4;
		tic_tac_toe_grid_3->Show(false);
		tic_tac_toe_grid_4->Show(true);
	}

	int i = 1;
	for (auto item : sizer->GetChildren())
	{	
		item->GetWindow()->SetLabel(board->get_pegs()[i - 1].val);
		item->GetWindow()->Disable();
		i++;
	}

	
	winner_text->SetValue(board->get_winner());
	set_winner_labels();
	this->Layout();
}


void Panel::set_button_properties(wxGridSizer* sizer)
{
	int i = 1;
	for (auto item : sizer->GetChildren())
	{
		item->GetWindow()->SetLabel(std::to_string(i));
		item->GetWindow()->Enable();
		i++;
	}
}

void Panel::set_winner_labels()
{
	int x, o, c;
	manager->get_winner_totals(x, o, c);

	x_winner_label->SetValue(std::to_string(x));
	o_winner_label->SetValue(std::to_string(o));
	c_winner_label->SetValue(std::to_string(c));

	this->Layout();
}