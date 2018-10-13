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



TextBox::TextBox(){

}


TextBox::~TextBox(){

}


void TextBox::load(HWND parent){

	m_hWnd = CreateWindow(TEXT("edit"), m_caption,
		WS_CHILD | WS_VISIBLE | WS_BORDER, m_x, m_y, m_width, m_height, parent, NULL, NULL, NULL);

}

void TextBox::setOnClickListener(void(*text_OnClick)()){

	m_text_OnClick = text_OnClick;

}

void TextBox::setOnChangeListener(void(*text_OnChange)()){

	m_text_OnChange = text_OnChange;
}



LRESULT CALLBACK TextBox::EventProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	if (message == WM_COMMAND){

		switch (HIWORD(wParam)){
		case EN_SETFOCUS:
			if (m_text_OnClick) (*m_text_OnClick)();
			break;
		case EN_CHANGE:
			if (m_text_OnChange) (*m_text_OnChange)();
			break;
			
		}
	}



	return 0;
}



Label::Label(){

}


Label::~Label(){

}


void Label::load(HWND parent){

	m_hWnd = CreateWindow(TEXT("static"), m_caption,
		WS_CHILD | WS_VISIBLE , m_x, m_y, m_width, m_height, parent, NULL, NULL, NULL);

}




LRESULT CALLBACK Label::EventProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	if (message == WM_COMMAND){



		
	}



	return 0;
}





ListBox::ListBox(){

}


ListBox::~ListBox(){

}


void ListBox::load(HWND parent){

	m_hWnd = CreateWindow(TEXT("listbox"), m_caption,
		WS_CHILD | WS_VISIBLE | LBS_STANDARD , m_x, m_y, m_width, m_height, parent, NULL, NULL, NULL);

}


void ListBox::addItem(CString item, int pos){

	SendMessage(m_hWnd, LB_INSERTSTRING, pos, (LPARAM)item.GetBuffer());

}

void ListBox::delItem(int pos){

	SendMessage(m_hWnd, LB_DELETESTRING, pos, 0);

}


int ListBox::getListCount(){




	return 0;
}

bool ListBox::isEmpty(){
	return getListCount() == 0;
}

CString ListBox::getItem(int pos){

	return TEXT("");
}

void ListBox::setItem(int pos, CString newitem){


}



LRESULT CALLBACK ListBox::EventProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	if (message == WM_COMMAND){




	}



	return 0;
}