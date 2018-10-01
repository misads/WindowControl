#pragma once
#include"Wnd.h"

class Control :public Window{

public:
	Control();
	~Control();

protected:
	virtual LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;

};

class Button :public Control{

public:
	Button();
	~Button();

	void load(HWND parent = NULL);

protected:
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};