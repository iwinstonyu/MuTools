
// MuPaper.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMuPaperApp:
// �йش����ʵ�֣������ MuPaper.cpp
//

class CMuPaperApp : public CWinApp
{
public:
	CMuPaperApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMuPaperApp theApp;