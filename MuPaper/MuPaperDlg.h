
// MuPaperDlg.h : 头文件
//

#pragma once

#include "resource.h"
#include "PaperLine.h"
#include "MuDefines.h"
#include <map>
using namespace mu;
using namespace std;

// CMuPaperDlg 对话框
class CMuPaperDlg : public CDialogEx
{
// 构造
public:
	CMuPaperDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MUPAPER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
