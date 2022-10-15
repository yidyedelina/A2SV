#include <vector>
using namespace std;
int longestMountain(vector<int> &arr)
{
    int maxn = 0, currMax = 0;
    int left = 0, right = 0;
    int count = 0;
    while (right < arr.size() - 1)
    {
        if (arr[right] < arr[right + 1])
        {
            right++;
            count++;
        }
        else if (arr[right] > arr[right + 1])
        {
            while (right < arr.size() - 1 && arr[right] > arr[right + 1])
            {
                right++;
            }
            int currMax = (right - left + 1);
            if (currMax > 2 && count > 0)
                maxn = max(currMax, maxn);
            left = right;
            count = 0;
        }
        else
        {
            while (right < arr.size() - 1 && arr[right] == arr[right + 1])
            {
                right++;
            }
            left = right;
            count = 0;
        }
    }
    return maxn;
}