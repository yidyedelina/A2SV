#include <vector>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int curMax = 0, max = 0;
    int budget = 1;
    int left = 0, right = 0;
    while (right < nums.size())
    {
        if (nums[right] == 0)
        {
            budget--;
        }
        if (budget >= 0)
        {
            curMax = right - left + 1;
            max = max > curMax ? max : curMax;
        }
        else
        {
            while (budget < 0)
            {
                if (nums[left] == 0)
                {
                    budget++;
                }
                left++;
            }
        }
        right++;
    }
    return max;
}