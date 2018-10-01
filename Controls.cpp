#include"stdafx.h"
#include"Controls.h"



Control::Control(){

	m_visible = true;

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

void Button::setOnClickListener(void(*button_OnClick)()){

	m_button_OnClick = button_OnClick;
	
}
LRESULT CALLBACK Button::EventProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	if (message == WM_COMMAND){
		if (m_button_OnClick) (*m_button_OnClick)();
	}



	return 0;
}