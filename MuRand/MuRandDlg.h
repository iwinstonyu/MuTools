// MuRandDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMuRandDlg �Ի���
class CMuRandDlg : public CDialog
{
// ����
public:
	CMuRandDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MURAND_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
