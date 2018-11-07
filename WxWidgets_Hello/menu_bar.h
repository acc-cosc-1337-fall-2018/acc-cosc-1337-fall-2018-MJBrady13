#ifndef MENU_H
#define MENU_H
#include<wx/wx.h>

enum
{
	ID_HELLO = 1
};

class MenuBar : public wxMenuBar
{
public:
	MenuBar();
private:
};

#endif //MENU_H