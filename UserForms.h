#pragma once

#include"Form.h"
#include "Controls.h"

class Form1 :public Form{
	
public:

	Form1(CString className, int id_Icon = 0, int id_Menu = 0, int id_IconSmall = 0);
	~Form1();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void loadControls();

	void onLoad();


private:

	Button button1;

};