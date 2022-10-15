#include <vector>
using namespace std;
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; 
    //number of swaps
    int count = 0;
    for (int start = 0; count < n; start++)
    {
        int current = start;
        int prev = nums[start];
        //swap next element + K with do this untill there current pointer back to its place 
        // [1l,2,3r,4,5,6,7]
        do
        {
            int nextP = (current + k) % n;
            int temp = nums[nextP];
            nums[nextP] = prev;
            prev = temp;
            current = nextP;
            count++;
        } while (start != current);
    }

}

void reverse(vector<int>& nums, int l, int r){
    while (l < r){
        swap(nums[l], nums[r]);
        l++, r--;
    }
}
void rotateArray(vector<int>& nums, int k){
    k = k % (nums.size());
    int l = 0, r = nums.size() - 1;
    reverse(nums, l, r);
    l = 0, r = k - 1;
    reverse(nums, l, r);
    l = k, r = nums.size() - 1;
    reverse(nums, l, r);
}