#pragma once
#include<atlstr.h>

class Window{
public:

	static void setInstance(HINSTANCE hInstance);

	HWND gethWnd();

	virtual void load(HWND parent=NULL) = 0;

	void setArea(int _x, int _y, int _width, int _height);

	void setCaption(CString caption);

protected:
	static HINSTANCE m_hInstance;
	
	HWND m_hWnd = NULL;
	
	//����
	CString m_caption = TEXT("");

	//�Ƿ�ɼ�
	bool m_visible;

	int m_x = CW_USEDEFAULT;
	int m_y = 0;
	int m_width = CW_USEDEFAULT;
	int m_height = 0;

	
};



