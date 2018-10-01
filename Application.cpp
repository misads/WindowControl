#include"stdafx.h"
#include"Application.h"



Application::Application() :form1(L"form1"){

}


Application::~Application(){

}


void Application::initApp(){

	Window::setInstance(m_hInstance);

	form1.setArea(300, 200, 600, 400);
	
	form1.setCaption(TEXT("²âÊÔ´°¿Ú"));

	form1.show();



}

void Application::setInstance(HINSTANCE hInstance){
	m_hInstance = hInstance;

}

LRESULT CALLBACK Application::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	return 0;
}



