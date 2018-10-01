#include"stdafx.h"
#include"Form1.h"



Form1::Form1(CString className, int id_Icon, int id_Menu, int id_IconSmall) :Form(className, WndProc){
	m_this = this;
	

}
Form1::~Form1(){


}


LRESULT CALLBACK Form1::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	

	for (int i = 0; i < m_controls.size(); i++){

		if (m_controls[i]->gethWnd() == (HWND)lParam)
			m_controls[i]->EventProc(hWnd, message, wParam, lParam);
	}



	return Form::WndProc( hWnd, message, wParam,lParam);

}

void Form1::addControl(Control* p_control){

	m_controls.push_back(p_control);
}

void button1_click(){

	Form* m_this = Form1::m_this;
	
	MessageBox(m_this->gethWnd() , L"asd", L"asd", 0);

}

void Form1::loadControls(){

	//m_controls["button2"]=new Button();

	//m_controls["button2"]->setCaption(TEXT("≤‚ ‘∞¥≈•2"));


	addControl(&button1);

	button1.setCaption(TEXT("≤‚ ‘∞¥≈•"));
	button1.setArea(30, 30, 150, 30);
	button1.load(m_hWnd);
	button1.setOnClickListener(button1_click);

}

void Form1::onLoad(){
	

}

Form1* Form1::m_this = NULL;

std::vector<Control*> Form1::m_controls;

