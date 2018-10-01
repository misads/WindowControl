#pragma once
#include"Wnd.h"

class Control :public Window{

public:
	Control();
	~Control();

public:
	virtual LRESULT CALLBACK EventProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;

};

class Button :public Control{

public:
	Button();
	~Button();

	void load(HWND parent = NULL);

	void setOnClickListener(void(*button_OnClick)());

protected:
	LRESULT CALLBACK EventProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void(*m_button_OnClick)() = NULL;

};