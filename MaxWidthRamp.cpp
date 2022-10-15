#include <vector>
#include <stack>
using namespace std;
int maxWidthRamp(vector<int> &A, int res = 0)
{
    vector<int> v = {0};
    for (int i = 1; A[v.back()] > A[A.size() - 1]; ++i)
        if (A[v.back()] > A[i])
            v.push_back(i);

    for (int j = A.size() - 1; j > res; --j)
        while (!v.empty() && A[v.back()] <= A[j])
        {
            res = max(res, j - v.back());
            v.pop_back();
        }
    return res;
}