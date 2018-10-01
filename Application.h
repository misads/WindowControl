#pragma once
#include<atlstr.h>
#include"Form1.h"

#define MAX_LOADSTRING 100

class Application{

public:
	Application();
	~Application();

	void initApp();
	void setInstance(HINSTANCE hInstance);

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


private:
	HINSTANCE m_hInstance;

	Form1 form1;



	


};