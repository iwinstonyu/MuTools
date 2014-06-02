// MuRandDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMuRandDlg 对话框
class CMuRandDlg : public CDialog
{
// 构造
public:
	CMuRandDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MURAND_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editBeg;
	CEdit m_editEnd;
	afx_msg void OnBnClickedButtonOk();
	CEdit m_editNums;
};
