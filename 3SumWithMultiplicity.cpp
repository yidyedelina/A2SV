#include <vector>
#include <unordered_map>
using namespace std;
int threeSumMulti(vector<int> &arr, int X)
{
    int n = arr.size(), mod = 1e9 + 7, ans = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        ans = (ans + m[X - arr[i]]) % mod;

        for (int j = 0; j < i; j++)
            m[arr[i] + arr[j]]++;
    }
    return ans;
}


int threeSumMultiWithTwoPointer(vector<int>& arr, int x){
    int n = arr.size(), mod = 1e9 + 7, ans = 0;
    for (int i = 0; i < arr.size(); i++){
        int l = i + 1, r = arr.size() - 1;
        int newTarget = x - arr[i];
        while (l < r)
        {
            if(arr[l] + arr[r] == newTarget){
                int lcount = 0, rcount = 0;
                while(l < r && arr[l] == arr[l+1]){
                    lcount++;
                    l++;
                }
                while(l < r && arr[r] == arr[r - 1]){
                    rcount++;
                    r++;
                }
                if(l == r)
                    ans += (lcount * (lcount - 1) / 2) % mod;
                else
                    ans += (rcount * lcount)%mod;
                r--;
                l++;
            }
            else if (arr[l] + arr[r] < newTarget)
                l++;
            else
                r--;
        }
    }
    return ans;
}