#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int nearSum = INT32_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                break;
            int sum = nums[i] + nums[l] + nums[r];
            cout << sum << endl;
            nearSum = abs(target - sum) <= abs(target - nearSum) ? sum : nearSum;
            if (sum < target)
                l++;
            else if (sum > target)
                r--;
            else
                break;
        }
    }
    return nearSum;
}
int main(){
    vector b{-1, 2, 1, -4};
    int a = threeSumClosest(b, 1);
    cout << a;
}