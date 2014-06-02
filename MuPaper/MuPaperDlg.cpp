
// MuPaperDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MuPaper.h"
#include "MuPaperDlg.h"
#include "afxdialogex.h"
#include "MuDefines.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMuPaperDlg �Ի���




CMuPaperDlg::CMuPaperDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMuPaperDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMuPaperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CMuPaperDlg::PreTranslateMessage(MSG* pMsg)
{
	int nCtrlId = GetWindowLong( pMsg->hwnd, GWL_ID );
	
	if( pMsg->message == WM_LBUTTONDOWN )
	{
		if( nCtrlId >= IDC_BTN_ADD_00 && nCtrlId <= IDC_BTN_ADD_94 )
		{
			int nOff = nCtrlId - IDC_BTN_ADD_00;
			m_mapCount[IDC_STATIC_COUNT_00 + nOff].IncCount();
			UpdateUI( nOff / 10 );
		}
		else if( nCtrlId >= IDC_BTN_DEL_00 && nCtrlId <= IDC_BTN_DEL_94 )
		{
			int nOff = nCtrlId - IDC_BTN_DEL_00;
			m_mapCount[IDC_STATIC_COUNT_00 + nOff].DecCount();
			UpdateUI( nOff / 10 );
		}
		else if( nCtrlId >= IDC_BTN_CLR_0 && nCtrlId <= IDC_BTN_CLR_9 )
		{
			ClearLine( nCtrlId - IDC_BTN_CLR_0 );
		}
	}
	else if( pMsg->message == WM_KEYUP )
	{
		if( nCtrlId >= IDC_EDIT_BASE_0 && nCtrlId <= IDC_EDIT_BASE_9 )
		{
			UpdateUI( nCtrlId - IDC_EDIT_BASE_0 );
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

BEGIN_MESSAGE_MAP(CMuPaperDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMuPaperDlg ��Ϣ�������

BOOL CMuPaperDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//add by nolaw start
	int nLeft = 10;
	int nTop = 10;
	DWORD dwStaticStyle = WS_CHILD | WS_VISIBLE | SS_CENTER;
	DWORD dwBtnStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;
	for( int i = 0; i < 10; ++i )
	{
		CString strID;
		strID.Format( _T("%d."), i + 1 );
		m_staticID[IDC_STATIC_LINE_0 + i] = new CStatic();
		m_staticID[IDC_STATIC_LINE_0 + i]->Create( strID, dwStaticStyle, CRect( nLeft, nTop + 43, nLeft + 30, nTop + 43 + 43 ), this, IDC_STATIC_LINE_0 + i );
		
		nLeft += 30 + 10;
		for( int j = 0; j < 5; ++j )
		{
			int nOff = i * 10 + j;

			int nL = nLeft;
			int nT = nTop;
			int nR = nL + BLOCK_STATIC_RATE_WIDTH;
			int nB = nT + BLOCK_STATIC_RATE_HEIGHT;
			m_mapCount[IDC_STATIC_COUNT_00 + nOff].m_staticCount->Create( CString( "0" ), dwStaticStyle, CRect( nL, nT, nR, nB ), this, IDC_STATIC_COUNT_00 + nOff );
			m_mapCount[IDC_STATIC_COUNT_00 + nOff].m_count = 0;

			nT = nB + BLOCK_SPILITER;
			nB = nT + BLOCK_STATIC_RATE_HEIGHT;
			m_staticRate[IDC_STATIC_RATE_00 + nOff] = new CStatic();
			m_staticRate[IDC_STATIC_RATE_00 + nOff]->Create( CString( "100.00%" ), dwStaticStyle, CRect( nL, nT, nR, nB ), this, IDC_STATIC_RATE_00 + nOff );

			nR = nL + BLOCK_BTN_ADD_WIDTH;
			nT = nB + BLOCK_SPILITER;
			nB = nT + BLOCK_BTN_ADD_HEIGHT;
			m_btnAdd[IDC_BTN_ADD_00 + nOff] = new CButton();
			m_btnAdd[IDC_BTN_ADD_00 + nOff]->Create( CString( "+" ), dwBtnStyle, CRect( nL, nT, nR, nB ), this, IDC_BTN_ADD_00 + nOff );

			nL = nR + BLOCK_SPILITER;
			nR = nL + BLOCK_BTN_DEL_WIDTH;
			m_btnDel[IDC_BTN_DEL_00 + nOff] = new CButton();
			m_btnDel[IDC_BTN_DEL_00 + nOff]->Create( CString( "-" ), dwBtnStyle, CRect( nL, nT, nR, nB ), this, IDC_BTN_DEL_00 + nOff );

			nLeft += 30 + 5 + 30 + 10;
		}

		m_editBase[IDC_EDIT_BASE_0 + i] = new CEdit();
		m_editBase[IDC_EDIT_BASE_0 + i]->Create( WS_CHILD | WS_VISIBLE | ES_NUMBER, CRect( nLeft, nTop + 40, nLeft + 40, nTop + 40 + 20 ), this, IDC_EDIT_BASE_0 + i );
		nLeft += 40 + 5;

		m_btnClr[IDC_BTN_CLR_0 + i] = new CButton();
		m_btnClr[IDC_BTN_CLR_0 + i]->Create( CString( _T("C") ), dwBtnStyle, CRect( nLeft, nTop + 33, nLeft + 28, nTop + 33 + 28 ), this, IDC_BTN_CLR_0 + i );
		
		nLeft = 10;		
		nTop += 70;
		m_staticCut[IDC_STATIC_CUT_0 + i] = new CStatic();
		m_staticCut[IDC_STATIC_CUT_0 + i]->Create( _T( "" ), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect( nLeft, nTop, nLeft + 650, nTop + 1 ), this, IDC_STATIC_CUT_0 + i );

		nTop += 5;
	}

	UpdateUI();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMuPaperDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMuPaperDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMuPaperDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMuPaperDlg::UpdateUI()
{
	for( int i = 0; i < 10; ++i )
		UpdateUI( i );
}

void CMuPaperDlg::UpdateUI( int nLine )
{
	int nBaseId	= IDC_EDIT_BASE_0 + nLine;
	int nBase = GetDlgItemInt( nBaseId );
	if( !nBase )
	{
		for( int i = 0; i < 5; ++i )
		{
			int nCountId = IDC_STATIC_COUNT_00 + nLine * 10 + i;
			nBase += m_mapCount[nCountId].m_count;
		}
	}

	if( !nBase )
		nBase = 100;

	for( int i = 0; i < 5; ++i )
	{
		int nCountId = IDC_STATIC_COUNT_00 + nLine * 10 + i;
		CString strCount;
		strCount.Format( _T("%d"), m_mapCount[nCountId].m_count );
		m_mapCount[nCountId].m_staticCount->SetWindowText( strCount );

		int nRateId	= IDC_STATIC_RATE_00 + nLine * 10 + i;
		CString strRate;
		strRate.Format( _T("%2.2f%%"), (float)m_mapCount[nCountId].m_count/nBase*100 );
		m_staticRate[nRateId]->SetWindowText( strRate );
	}
}

void CMuPaperDlg::ClearLine( int nLine )
{
	for( int i = 0; i < 5; ++i )
	{
		int nCountId = IDC_STATIC_COUNT_00 + nLine * 10 + i;
		m_mapCount[nCountId].m_count = 0;
	}

	m_editBase[IDC_EDIT_BASE_0 + nLine]->SetWindowText( CString( _T("") ) );

	UpdateUI( nLine );
}
