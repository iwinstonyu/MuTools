#include "StdAfx.h"
#include "MyUtility.h"

namespace mu
{
	void GetRand(int nBeg, int nEnd)
	{

	}

	void RandNums(std::vector<int>& nums, int n)
	{
		srand(::time(NULL));
		nums.reserve(n);
		for(int i=0; i<n; ++i)
		{
			nums.push_back(i+1);
		}

		int count = n;
		while(count)
		{
			int nTemp = rand() % count;
			std::swap(nums[count-1], nums[nTemp]);
			--count;
		}
	}


}