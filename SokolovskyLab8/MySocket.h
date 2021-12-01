#pragma once

// CMySocket command target

class CMySocket : public CAsyncSocket
{
public:
	CMySocket();
	virtual ~CMySocket();
	CDialog *m_pWnd;

	void SetParent(CDialog *pWnd);
	void OnAccept(int nErrorCode);
	void OnClose(int nErrorCode);
	void OnConnect(int nErrorCode);
	void OnReceive(int nErrorCode);
	void OnSend(int nErrorCode);

};


