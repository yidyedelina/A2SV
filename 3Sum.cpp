#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> indexes;
    for (int i = 0; i < nums.size(); i++)
    {
        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            if (i != 0 && nums[i] == nums[i - 1])
            {
                break;
            }
            if (nums[l] + nums[r] + nums[i] > 0)
                r--;
            else if (nums[l] + nums[r] + nums[i] < 0)
                l++;
            else
            {
                indexes.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1])
                    l++;
                while (l < r && nums[r] == nums[r - 1])
                    r--;
                l++;
                r--;
            }
           
        }
    }
    return indexes;
}