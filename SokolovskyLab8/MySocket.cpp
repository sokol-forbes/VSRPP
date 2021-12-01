// MySocket.cpp : implementation file
//

#include "stdafx.h"
#include "SokolovskyLab8.h"
#include "MySocket.h"
#include "SokolovskyLab8Dlg.h"


// CMySocket

CMySocket::CMySocket()
{
}

CMySocket::~CMySocket()
{
}

void CMySocket::SetParent(CDialog *pWnd)
{
	// устанавливаем указатель
	m_pWnd = pWnd;
}
void CMySocket::OnAccept(int nErrorCode)
{
	if (nErrorCode == 0)
		// Нет, вызываем функцию OnAccept()
			((CSokolovskyLab8Dlg*)m_pWnd)->OnAccept();
	CAsyncSocket::OnAccept(nErrorCode);
}
void CMySocket::OnClose(int nErrorCode)
{
	if (nErrorCode == 0)
		// Нет, вызываем функцию OnAccept()
		((CSokolovskyLab8Dlg*)m_pWnd)->OnClose();
	CAsyncSocket::OnClose(nErrorCode);
}
void CMySocket::OnConnect(int nErrorCode)
{
	if (nErrorCode == 0)
		// Нет, вызываем функцию OnAccept()
		((CSokolovskyLab8Dlg*)m_pWnd)->OnConnect();
	CAsyncSocket::OnConnect(nErrorCode);
}
void CMySocket::OnReceive(int nErrorCode)
{
	if (nErrorCode == 0)
		// Нет, вызываем функцию OnAccept()
		((CSokolovskyLab8Dlg*)m_pWnd)->OnReceive();
	CAsyncSocket::OnReceive(nErrorCode);
}
void CMySocket::OnSend(int nErrorCode)
{
	if (nErrorCode == 0)
		// Нет, вызываем функцию OnAccept()
			((CSokolovskyLab8Dlg*)m_pWnd)->OnSend();
	CAsyncSocket::OnSend(nErrorCode);
}

// CMySocket member functions
