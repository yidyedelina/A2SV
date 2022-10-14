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
//k = 5
// [1,1,2, 4]
//sum = 1
//sum = 2
//sum = 4
// sum = 8
// sum = 7
// 
int maxFrequency(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    int left = 0, right = 0;
    int sum = 0, maxFre = 0;
    while(right < nums.size()){
        sum += nums[right];
        while((right - left + 1) * nums[right] - sum > k){
            sum -= nums[left];
            left++;
        }
        maxFre = max(maxFre, right - left + 1);
        right++;
    }
    return maxFre;
}