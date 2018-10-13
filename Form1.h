#pragma once

#include"Form.h"
#include"Controls.h"

class Form1 :public Form{
	
public:

	Form1(CString className, int id_Icon = 0, int id_Menu = 0, int id_IconSmall = 0);
	~Form1();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void addControl(Control* p_control);

	void loadControls();

	void onLoad();


private:

	static Form1* m_this;

	static std::vector<Control*> m_controls;

	Button button1;

	Button button2;

	TextBox text1;

	Label label1;

	ListBox list1;

	friend void button1_click();

	friend void button2_click();

	friend void text1_click();

	friend void text1_change();

};