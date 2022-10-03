#include <iostream>
#include <vector>   
#include <algorithm>
using namespace std;

int maxFrequency(vector<int>& nums, int K)
{
        sort(nums.begin(), nums.end());
        int start = 0, end = 0;
        int sum = 0, res = 0;
        for (end = 0; end < nums.size(); end++) {
            sum += nums[end];
            while ((end - start + 1) * nums[end] - sum > K) {
                sum -= nums[start];
                start++;
            }
            res = max(res, end - start + 1);
            res = res > end - start + 1 ? res: end - start + 1;
        }
        return res;
}
