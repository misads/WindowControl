#pragma once
#include <atlstr.h>
#include "Wnd.h"
#include "Controls.h"
#include <vector>
#include <map>

class Form :public Window{

public:
	//如果不指定 使用Form类自带的
	Form(CString className, WNDPROC wndproc = WndProc);
	~Form();

	void load(HWND parent = NULL);

	//virtual void addControl(Control* p_control) = 0;

	virtual void loadControls() = 0;
	//抽象函数	
	virtual void onLoad()=0;

	void setArea(int _x, int _y, int _width, int _height);

	void show();

	//return WndProc(hWnd,message,wParam,lParam);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

protected:
	CString			m_className=TEXT("");
	WNDPROC			m_wndProc;
	

	int				m_id_Icon = 0;
	int				m_id_Menu = 0;
	int				m_id_IconSmall = 0;



	ATOM registerClass(WNDPROC wndproc);


};