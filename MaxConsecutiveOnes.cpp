#include <iostream>
#include <vector>
using namespace std;

    int longestOnes(vector<int> &nums, int k)
    {
        int maxLen = 0, curMax = 0;
        int left = 0, right = 0;
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) {
                right++;
                curMax++;
                continue;
            }else if(k > 0){
                right++;
                curMax++;
                k--;
                continue;
            }
            maxLen = maxLen > (right - left) ? maxLen : (right - left);
            maxLen = maxLen > curMax ? maxLen : curMax;
            while(nums[left] != 0){
                left++;
            }
            curMax = right - left;
            left++, right++;
        }
        return maxLen;
    }

int main(){
    vector<int> b{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int a = longestOnes(b, 2);
    cout << a;
}