
// my_paint.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CmypaintApp:
// See my_paint.cpp for the implementation of this class
//

class CmypaintApp : public CWinApp
{
public:
	CmypaintApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CmypaintApp theApp;
