#include"stdafx.h"
#include"UserForms.h"



Form1::Form1(CString className, int id_Icon, int id_Menu, int id_IconSmall) :Form(className, WndProc){
	
	

}
Form1::~Form1(){


}


LRESULT CALLBACK Form1::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;



	switch (message)
	{
	case WM_COMMAND:

		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  �ڴ���������ͼ����...
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


void Form1::loadControls(){

	button1.setCaption(TEXT("���԰�ť"));
	button1.setArea(30, 30, 150, 30);
	button1.load(m_hWnd);

}

void Form1::onLoad(){
	

}
