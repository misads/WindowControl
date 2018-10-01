#include"stdafx.h"
#include"Controls.h"



Control::Control(){

	m_visibility = true;

}

Control::~Control(){


}
Button::Button(){

}


Button::~Button(){

}


void Button::load(HWND parent){

	m_hWnd = CreateWindow(TEXT("BUTTON"), m_caption,
		WS_CHILD | WS_VISIBLE, m_x, m_y, m_width, m_height, parent, NULL, NULL, NULL);

}

LRESULT CALLBACK Button::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	return 0;
}