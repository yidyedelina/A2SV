#include <vector>
using namespace std;
int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int sum = 0;
    int count = 0;
    int left = 0, right = 0;
    while (right < arr.size())
    {
        if (right - left + 1 == k)
        {
            if (sum / k >= threshold)
            {
                count++;
            }
            sum -= arr[left];
            left++;
        }
        sum += arr[right];
        right++;
    }
    return count;
}