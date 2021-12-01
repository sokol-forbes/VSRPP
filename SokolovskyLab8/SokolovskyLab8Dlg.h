
// SokolovskyLab8Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "MySocket.h"

// CSokolovskyLab8Dlg dialog
class CSokolovskyLab8Dlg : public CDialogEx
{
// Construction
public:
	CSokolovskyLab8Dlg(CWnd* pParent = NULL);	// standard constructor

	CMySocket m_sListenSocket;
	CMySocket m_sConnectSocket;

// Dialog Data
	enum { IDD = IDD_SOKOLOVSKYLAB8_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_ctlConnect;
	CString m_strMessage;
	CString m_strName;
//	CString m_iPort;
	CListBox m_ctlRecvd;
	CListBox m_ctlSent;
	int m_iType;
	afx_msg void OnBnClickedRclient();
	afx_msg void OnBnClickedRserver();
	int m_iPort;
	afx_msg void OnBnClickedBconnect();
	void OnAccept(void);
	void OnConnect(void);
	void OnSend(void);
	void OnReceive(void);
	void OnClose(void);
	afx_msg void OnBnClickedBclose();
	afx_msg void OnBnClickedBsend();
};
