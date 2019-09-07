// Chris Moroney
// CS212, online section
// Due 4 June 2019
// Project 4: Inheritance

// when we made out HelloWorld.cpp, we needed to make a class in order to 
// make our definitions clear. These are essentially the "terms" that we make for our
// definitions in the cpp file. We use inheritance to say that our app is derived from the windows
// app.

// HelloWorld.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CHelloWorldApp:
// See HelloWorld.cpp for the implementation of this class
//
// inheritance: creating a new class from a larger made class
// for the sakes of different definitions. Both of these are apps, but
// the app that mine is generating is much different than that of the windows app
class CHelloWorldApp : public CWinApp
{
public:
	CHelloWorldApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CHelloWorldApp theApp;
