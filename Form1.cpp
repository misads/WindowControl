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
	
	MessageBox(m_this->gethWnd() , L"button1", L"button1", 0);

}

void button2_click(){

	Form* m_this = Form1::m_this;

	MessageBox(m_this->gethWnd(), L"button2", L"button2", 0);

}

void text1_click(){

	Form* m_this = Form1::m_this;

	//MessageBox(m_this->gethWnd(), L"text1", L"text1", 0);

}


void text1_change(){

	Form* m_this = Form1::m_this;

	MessageBox(m_this->gethWnd(), L"text1", L"text1", 0);

}

void Form1::loadControls(){

	//m_controls["button2"]=new Button();

	//m_controls["button2"]->setCaption(TEXT("测试按钮2"));


	addControl(&button1);

	button1.setCaption(TEXT("测试按钮"));
	button1.setArea(30, 30, 150, 30);
	button1.load(m_hWnd);
	button1.setOnClickListener(button1_click);

	addControl(&button2);

	button2.setCaption(TEXT("测试按钮2"));
	button2.setArea(30, 80, 150, 30);
	button2.load(m_hWnd);
	button2.setOnClickListener(button2_click);

	addControl(&text1);

	text1.setCaption(TEXT("测试框1"));
	text1.setArea(30, 130, 150, 30);
	text1.load(m_hWnd);
	text1.setOnChangeListener(text1_change);
	
	addControl(&label1);

	label1.setCaption(TEXT("标签1"));
	label1.setArea(30, 180, 150, 30);
	label1.load(m_hWnd);

	addControl(&list1);

	list1.setCaption(TEXT("列表1"));
	list1.setArea(30, 230, 150, 100);
	list1.load(m_hWnd);
	list1.addItem(L"条目1");
	list1.addItem(L"条目2");
	list1.addItem(L"条目3");
	list1.addItem(L"条目4");
	//list1.delItem(0);

	//label1.setOnClickListener(text1_change);


}

void Form1::onLoad(){
	

}

Form1* Form1::m_this = NULL;

std::vector<Control*> Form1::m_controls;

