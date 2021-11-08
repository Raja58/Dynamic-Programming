// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        08 Nov 2021
//  @Detail  :        Min number of jumps
//  ============================
//  -->

#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
  if(array.size() == 1)
		return 0;
	int steps = array[0], maxReach = array[0], jumps = 0;
	for(int i = 1; i < array.size() - 1; i++)
	{
		maxReach = max(maxReach, i + array[i]);
		steps--;
		if(steps == 0)
		{
			jumps++;
			if(maxReach <= i)
				return -1;
			steps = maxReach - i;
		}
	}
  return jumps + 1;
}
