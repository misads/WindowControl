// Control.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Common.h"
#include "GDI.h"
#include "Application.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������
CGDI gdi;
Application App;

HBITMAP hmap=NULL;// = gdi.LoadImageRes(hInst, IDB_BITMAP1);

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// (hInstance);

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CONTROL, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CONTROL));

	// ����Ϣѭ��: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(0));//IDI_CONTROL
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(0);//IDC_CONTROL
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(0));//IDI_SMALL

	return RegisterClassEx(&wcex);
}

//
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����


   //hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
   //   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);


   App.setInstance(hInstance);
   App.initApp();

   gdi.SetFont(L"΢���ź�",100 ,30, 30);
  // if (!hWnd)
  // {
  //    return FALSE;
 //  }

   //ShowWindow(hWnd, nCmdShow);
   //UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	App.WndProc(hWnd, message, wParam, lParam);

	if (hmap==NULL)
	hmap = gdi.LoadImageRes(hInst, IDB_BITMAP1);

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  �ڴ���������ͼ����...
		//gdi.DrawLine(hdc, 0+20, 0+20, 200+20, 200+20, 16);
		//gdi.DrawLine(hdc, 0+20, 200+20, 200+20, 0+20, 16);
		//gdi.DrawBmp(hdc, hmap, 0, 0, 300, 400);
		//gdi.DrawBmp(hdc, hInst,IDB_BITMAP1, 0, 0, 300, 400);
		gdi.DrawTransparentBmp(hdc, hInst, IDB_BITMAP1, 0, 0, 300, 400, 0, 0);
		gdi.SetFont(L"΢���ź�", 100, 30, 30);
		gdi.DrawTextB(hdc, 110, 400, 1000, 550, L"����");

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

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
