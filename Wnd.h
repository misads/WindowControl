#pragma once
#include<atlstr.h>

class Window{
public:

	static void setInstance(HINSTANCE hInstance);

	virtual void load(HWND parent=NULL) = 0;

	void setArea(int _x, int _y, int _width, int _height);

	void setCaption(CString caption);

protected:
	static HINSTANCE m_hInstance;
	
	HWND m_hWnd = NULL;
	
	//标题
	CString m_caption = TEXT("");

	//是否可见
	bool m_visibility;

	int m_x = CW_USEDEFAULT;
	int m_y = 0;
	int m_width = CW_USEDEFAULT;
	int m_height = 0;

	
};



