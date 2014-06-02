#pragma once

#include "MuDefines.h"

namespace mu
{
	class CPaperBlock
	{
	public:
		CPaperBlock();
		~CPaperBlock();

		BOOL Init( uint32 nLine, uint32 nCol, int nLeft, int nTop, CWnd* pParent );

	private:
		CButton m_btnAdd;
		CButton m_btnDel;
		CStatic m_staticCount;
		CStatic m_staticRate;
	};

	class CPaperLine
	{
	public:
		CPaperLine();
		~CPaperLine();

		BOOL Init( uint32 nLine, int nLeft, int nTop, CWnd* pParent );

	private:
		CStatic m_staticLine;			// ±àºÅ
		CPaperBlock m_blocks[5];		// 5¸ö¿é
		CEdit m_editBase;				// ±à¼­¿ò
		CButton m_btnClr;				// Çå³ý
	};
}