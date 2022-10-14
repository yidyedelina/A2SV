#include <vector>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int start = 0, end = 0;
    for (end = 0; end < nums.size(); end++){
        if(nums[end] != 0){
            nums[start] = nums[end];
            start++;
        }
    }
    for (int i = start; i < nums.size(); i++){
        nums[i] = 0;
    }
}

void moveZeroes1(vector<int> &nums){
    int left = 0;
    for (int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            nums[left] = nums[i];
            left++;
        }
    }
    for (int i = left; i < nums.size(); i++){
        nums[i] = 0;
    }
}