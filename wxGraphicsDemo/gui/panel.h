#ifndef PANEL_H
#define PANEL_H
#include<wx/wx.h>
#include<vector>
#include<string>
#include<memory>
#include "text.h"
#include "circle.h"

class Panel : public wxPanel 
{
public:
	Panel(wxWindow* parent);
private:
	void OnDraw(wxCommandEvent& event);
	wxTextCtrl* draw_text;
	wxRadioBox* radio_box;
};

#endif // !PANEL_H
