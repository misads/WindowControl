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

class TextBox :public Control{

public:
	TextBox();
	~TextBox();

	void load(HWND parent = NULL);

	void setOnClickListener(void(*text_OnClick)());
	void setOnChangeListener(void(*text_OnChange)());

protected:
	LRESULT CALLBACK EventProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void(*m_text_OnClick)() = NULL;
	void(*m_text_OnChange)() = NULL;

};

class Label :public Control{

public:
	Label();
	~Label();

	void load(HWND parent = NULL);


protected:
	LRESULT CALLBACK EventProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);



};


class ListBox :public Control{
public:
	ListBox();
	~ListBox();

	void load(HWND parent = NULL);

	//默认在最后添加
	void addItem(CString item, int pos = -1);

	void delItem(int pos);

	int getListCount();

	bool isEmpty();

	CString getItem(int pos);

	void setItem(int pos, CString newitem);


protected:
	LRESULT CALLBACK EventProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


};