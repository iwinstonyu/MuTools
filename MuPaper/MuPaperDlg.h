
// MuPaperDlg.h : ͷ�ļ�
//

#pragma once

#include "resource.h"
#include "PaperLine.h"
#include "MuDefines.h"
#include <map>
using namespace mu;
using namespace std;

// CMuPaperDlg �Ի���
class CMuPaperDlg : public CDialogEx
{
// ����
public:
	CMuPaperDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MUPAPER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	void	UpdateUI();
	void	UpdateUI( int nLine );
	void	ClearLine( int nLine );

public:
	struct SCount
	{
		SCount() : m_staticCount( new CStatic() ), m_count( 0 ) {}
		
		void		IncCount() { ++m_count; }
		void		DecCount() { if( m_count ) --m_count; }
		void		ClrCount() { m_count = 0; }

		CStatic*	m_staticCount;
		int			m_count;
	};


private:
	std::map<int, CStatic*>		m_staticID;
	std::map<int, SCount>		m_mapCount;
	std::map<int, CStatic*>		m_staticRate;
	std::map<int, CButton*>		m_btnAdd;
	std::map<int, CButton*>		m_btnDel;
	std::map<int, CEdit*>		m_editBase;
	std::map<int, CButton*>		m_btnClr;
	std::map<int, CStatic*>		m_staticCut;
};
