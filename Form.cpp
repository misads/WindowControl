#include"stdafx.h"
#include"Form.h"


Form::Form(CString className, WNDPROC wndproc) :m_className(className), m_wndProc(wndproc){

	m_className = className;

	m_wndProc = wndproc;

	m_visible = false;

}

Form::~Form(){}


void Form::load(HWND parent){

	registerClass(m_wndProc);

	

	m_hWnd = CreateWindow(m_className, m_caption, WS_OVERLAPPEDWINDOW,
		m_x, m_y,m_width, m_height, NULL, NULL, m_hInstance, NULL);

	loadControls();
	
	onLoad();

}


void Form::setArea(int _x, int _y, int _width, int _height){

	Window::setArea(_x, _y, _width, _height);

	if (m_hWnd != NULL){


	}

}

void Form::show(){

	if (m_hWnd == NULL)load();

	ShowWindow(m_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(m_hWnd);
	
	m_visible = true;

}

//return defWndProc(this,hWnd,message,wParam,lParam);
LRESULT CALLBACK Form::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;



	switch (message){
	case WM_COMMAND:

		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  在此添加任意绘图代码...
		//gdi.DrawLine(hdc, 0+20, 0+20, 200+20, 200+20, 16);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}



ATOM Form::registerClass(WNDPROC wndproc){

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = wndproc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInstance;
	wcex.hIcon = LoadIcon(m_hInstance, MAKEINTRESOURCE(m_id_Icon));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(m_id_Menu);
	wcex.lpszClassName = m_className;//szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(m_id_IconSmall));

	return RegisterClassEx(&wcex);

}