
// SokolovskyLab8.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSokolovskyLab8App:
// See SokolovskyLab8.cpp for the implementation of this class
//

class CSokolovskyLab8App : public CWinApp
{
public:
	CSokolovskyLab8App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSokolovskyLab8App theApp;