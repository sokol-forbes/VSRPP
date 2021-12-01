
// SokolovskyLab8Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "SokolovskyLab8.h"
#include "SokolovskyLab8Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSokolovskyLab8Dlg dialog



CSokolovskyLab8Dlg::CSokolovskyLab8Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSokolovskyLab8Dlg::IDD, pParent)
	, m_strMessage(_T(""))
	, m_strName(_T(""))
	, m_iType(0)
	, m_iPort(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSokolovskyLab8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BCONNECT, m_ctlConnect);
	DDX_Text(pDX, IDC_EMSG, m_strMessage);
	DDX_Text(pDX, IDC_ESERVNAME, m_strName);
	//  DDX_Text(pDX, IDC_ESERVPORT, m_iPort);
	DDX_Control(pDX, IDC_LRECVD, m_ctlRecvd);
	DDX_Control(pDX, IDC_LSENT, m_ctlSent);
	DDX_Radio(pDX, IDC_RCLIENT, m_iType);
	DDX_Text(pDX, IDC_ESERVPORT, m_iPort);
}

BEGIN_MESSAGE_MAP(CSokolovskyLab8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RCLIENT, &CSokolovskyLab8Dlg::OnBnClickedRclient)
	ON_BN_CLICKED(IDC_RSERVER, &CSokolovskyLab8Dlg::OnBnClickedRserver)
	ON_BN_CLICKED(IDC_BCONNECT, &CSokolovskyLab8Dlg::OnBnClickedBconnect)
	ON_BN_CLICKED(IDC_BCLOSE, &CSokolovskyLab8Dlg::OnBnClickedBclose)
	ON_BN_CLICKED(IDC_BSEND, &CSokolovskyLab8Dlg::OnBnClickedBsend)
END_MESSAGE_MAP()


// CSokolovskyLab8Dlg message handlers

BOOL CSokolovskyLab8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// Инициализируем переменные управления
	m_iType = 0;
	m_strName = "loopback";
	m_iPort = 4000;
	// обновляем элементы управления 
	UpdateData(FALSE);
	// Устанавливаем указатель
	m_sConnectSocket.SetParent(this);
	m_sListenSocket.SetParent(this);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSokolovskyLab8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSokolovskyLab8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSokolovskyLab8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSokolovskyLab8Dlg::OnBnClickedRclient()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	// В каком мы режиме?
	if (m_iType == 0)  // Устанавить текст на кнопке
		m_ctlConnect.SetWindowText(TEXT("C&onnect"));
	else
		m_ctlConnect.SetWindowText(TEXT("&Listen"));

}


void CSokolovskyLab8Dlg::OnBnClickedRserver()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
// В каком режиме приложение?
	if (m_iType == 0) //Устанавливить текст на кнопке
		m_ctlConnect.SetWindowText(TEXT("C&onnect"));
	else
		m_ctlConnect.SetWindowText(TEXT("&Listen"));

}


void CSokolovskyLab8Dlg::OnBnClickedBconnect()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	// Включаем прочие элементы управления
	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_ESERVNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_ESERVPORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_RCLIENT)->EnableWindow(FALSE);
	GetDlgItem(IDC_RSERVER)->EnableWindow(FALSE);
	// Работаем в качестве клиента или сервера?
	if (m_iType == 0)
	{	// клиент, создаем сокет по умолчанию 
		m_sConnectSocket.Create();
		// открываем соединение с сервером
		m_sConnectSocket.Connect(m_strName, m_iPort);
	}
	else
	{
// сервер, создаем возможность прослушивания на указанном порте
		m_sListenSocket.Create(m_iPort);
		// прослушиваем запросы на соединение
		m_sListenSocket.Listen();
	}

}


void CSokolovskyLab8Dlg::OnAccept(void)
{
	m_sListenSocket.Accept(m_sConnectSocket);

	GetDlgItem(IDC_EMSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BSEND)->EnableWindow(TRUE);
}


void CSokolovskyLab8Dlg::OnConnect(void)
{
	GetDlgItem(IDC_EMSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BSEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_BCLOSE)->EnableWindow(TRUE);
}


void CSokolovskyLab8Dlg::OnSend(void)
{
	int iLen;
	int iSent;
// Обновляем элементы управления в соответствии с переменными
	UpdateData(TRUE);
	// Есть сообщение для посылки?
	if (m_strMessage != "")
	{	// Получаем длину сообщения
		iLen = m_strMessage.GetLength();
		// Посылаем сообщение
		char* p = new char[iLen];
		char s1[1024];
		for (int i = 0; i < iLen; i++)
		{
			char s = m_strMessage[i];
			s1[i] = s;
		}
		p = s1;
		iSent = m_sConnectSocket.Send(p, iLen, 0);
		// Смогли послать?
		if (iSent == SOCKET_ERROR)
		{
			return;
		}
		else
		{	// Добавляем сообщение в список
			m_ctlSent.AddString(m_strMessage);
// Обновляем переменные согласно элементам управления
			UpdateData(FALSE);
		}
	}

}


void CSokolovskyLab8Dlg::OnReceive(void)
{
	char *pBuf = new char[1025];
	int iBufSize = 1024;
	int iRcvd;
	CString strRecvd;
	// Получаем сообщение
	iRcvd = m_sConnectSocket.Receive(pBuf, iBufSize);
	// Получили что-либо?
	if (iRcvd == SOCKET_ERROR)
	{
		return;
	}
	else
	{	// Отрезаем конец сообщения
		pBuf[iRcvd] = NULL;
		// Копируем сообщение в CString
		strRecvd = pBuf;
		// добавляем сообщение в список полученных сообщений
		m_ctlRecvd.AddString(strRecvd);
		// обновляем переменные в соответствии с элементами 
// управления
		UpdateData(FALSE);
	}

}


void CSokolovskyLab8Dlg::OnClose(void)
{
	m_sConnectSocket.Close();
// выключаем элементы управления, ответственные за посылку 
// сообщений
	GetDlgItem(IDC_EMSG)->EnableWindow(FALSE);
	GetDlgItem(IDC_BSEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_BCLOSE)->EnableWindow(FALSE);
	// мы работаем как клиент?
	if (m_iType == 0)
	{
// да, тогда влючаем элементы управления соединением
		GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_ESERVNAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_ESERVPORT)->EnableWindow(TRUE);
		GetDlgItem(IDC_RCLIENT)->EnableWindow(TRUE);
		GetDlgItem(IDC_RSERVER)->EnableWindow(TRUE);
	}

}


void CSokolovskyLab8Dlg::OnBnClickedBclose()
{
	// TODO: Add your control notification handler code here
	OnClose();
}


void CSokolovskyLab8Dlg::OnBnClickedBsend()
{
	// TODO: Add your control notification handler code here
	OnSend();
}
