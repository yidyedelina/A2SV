#include <vector>
using namespace std;
bool carPooling(vector<vector<int>> &trips, int capacity)
{
    int n = trips.size();
    vector<int> count(1001, 0);
    for (int i = 0; i < n; i++){
        count[trips[i][1]] += trips[i][0];
        count[trips[i][2]] -= trips[i][0];
    }
    int cur = 0;
    for (int i = 0; i < 1001; i++){
        cur += count[i];
        if (cur > capacity){
            return false;
        }
    }
    return true;
}