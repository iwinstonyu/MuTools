#include "stdafx.h"
#include "PaperLine.h"
#include "resource.h"

namespace mu
{  

	CPaperBlock::CPaperBlock()
	{
	}

	CPaperBlock::~CPaperBlock()
	{

	}

	BOOL CPaperBlock::Init( uint32 nLine, uint32 nCol, int nLeft, int nTop, CWnd* pParent )
	{
		uint32 nOff = nLine * 10 + nCol;

		DWORD dwStaStyle = WS_CHILD | WS_VISIBLE | SS_CENTER;
		DWORD dwBtnStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;

		int nL = nLeft;
		int nT = nTop;
		int nR = nL + BLOCK_STATIC_RATE_WIDTH;
		int nB = nT + BLOCK_STATIC_RATE_HEIGHT;
		m_staticCount.Create( CString( "0" ), dwStaStyle, CRect( nL, nT, nR, nB ), pParent, IDC_STATIC_COUNT_00 + nOff );
		nT = nB + BLOCK_SPILITER;
		nB = nT + BLOCK_STATIC_RATE_HEIGHT;
		m_staticRate.Create( CString( "100.00%" ), dwStaStyle, CRect( nL, nT, nR, nB ), pParent, IDC_STATIC_RATE_00 + nOff );

		nR = nL + BLOCK_BTN_ADD_WIDTH;
		nT = nB + BLOCK_SPILITER;
		nB = nT + BLOCK_BTN_ADD_HEIGHT;
		m_btnAdd.Create( CString( "+" ), dwBtnStyle, CRect( nL, nT, nR, nB ), pParent, IDC_BTN_ADD_00 + nOff );

		nL = nR + BLOCK_SPILITER;
		nR = nL + BLOCK_BTN_DEL_WIDTH;
		m_btnDel.Create( CString( "-" ), dwBtnStyle, CRect( nL, nT, nR, nB ), pParent, IDC_BTN_DEL_00 + nOff );

		return true;
	}

	CPaperLine::CPaperLine()
	{

	}

	CPaperLine::~CPaperLine()
	{

	}

	BOOL CPaperLine::Init( uint32 nLine, int nLeft, int nTop, CWnd* pParent )
	{
		if( !pParent )
			return false;

		DWORD dwStaStyle = WS_CHILD | WS_VISIBLE | SS_CENTER;

		CString strLine;
		strLine.Format( _T("%d."), nLine + 1 );
		m_staticLine.Create( strLine, dwStaStyle, CRect( nLeft, nTop + 43, nLeft + 30, nTop + 43 + 43 ), pParent, IDC_STATIC_LINE_0 + nLine );
		nLeft += 30 + 10;

		for( uint32 i = 0; i < 5; ++i )
		{
			m_blocks[i].Init( nLine, i, nLeft, nTop, pParent );
			
			nLeft += 30 + 5 + 30 + 10;
		}

		m_editBase.Create( WS_CHILD | WS_VISIBLE, CRect( nLeft, nTop + 40, nLeft + 40, nTop + 40 + 20 ), pParent, IDC_EDIT_BASE_0 + nLine );
		nLeft += 40 + 5;
		
		m_btnClr.Create( CString( _T("C") ), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect( nLeft, nTop + 33, nLeft + 28, nTop + 33 + 28 ), pParent, IDC_BTN_CLR_0 + nLine );

		return true;
	}
}