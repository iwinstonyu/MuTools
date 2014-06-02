#pragma once

namespace mu
{
	typedef unsigned int uint32;

	const uint32 MU_PAPER_LINE_HEIGHT = 30;
	const uint32 MU_BTN_OPT_WIDTH			= 25;
	const uint32 MU_BTN_OPT_HEIGHT			= 25;

	const int BLOCK_SPILITER = 2;
	const int BLOCK_BTN_ADD_WIDTH = 28;
	const int BLOCK_BTN_DEL_WIDTH = 28;
	const int BLOCK_STATIC_RATE_WIDTH	= BLOCK_BTN_ADD_WIDTH + BLOCK_SPILITER + BLOCK_BTN_DEL_WIDTH;
	const int BLOCK_STATIC_RATE_HEIGHT	= 15;
	const int BLOCK_BTN_ADD_HEIGHT		= 28;

	const int PAPER_STATIC_LINE_WIDTH = 30;
	const int PAPER_HEIGHT = BLOCK_STATIC_RATE_HEIGHT * 2 + BLOCK_SPILITER + BLOCK_BTN_ADD_HEIGHT;

}