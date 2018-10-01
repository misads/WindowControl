#include"stdafx.h"
#include "Wnd.h"


void Window::setInstance(HINSTANCE hInstance){
	m_hInstance = hInstance;
}

HWND Window::gethWnd(){
	return m_hWnd;

}

void Window::setArea(int _x, int _y, int _width, int _height){

	m_x = _x;
	m_y = _y;
	m_width = _width;
	m_height = _height;



}

void  Window::setCaption(CString caption){
	m_caption = caption;

}
HINSTANCE Window::m_hInstance = NULL;




