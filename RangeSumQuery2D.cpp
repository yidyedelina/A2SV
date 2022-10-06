#include <vector>
using namespace std;
class NumMatrix
{
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        int m = matrix.size(), n = matrix[0].size();
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

//product of arraay except itself
//https://leetcode.com/problems/product-of-array-except-self/

#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);
        int left = 1, right = 1;
        for (int i = 0; i < n; i++)
        {
            res[i] *= left;
            left *= nums[i];
            res[n - 1 - i] *= right;
            right *= nums[n - 1 - i];
        }
        return res;
    }
};