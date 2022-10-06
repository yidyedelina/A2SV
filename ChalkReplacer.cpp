#include <vector>
using namespace std;
int chalkReplacer(vector<int> &chalk, int k)
{
    int n = chalk.size();
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += chalk[i];
    }
    k = k % sum;
    for (int i = 0; i < n; i++){
        if (chalk[i] > k){
            return i;
        }
        k -= chalk[i];
    }
    return -1;
}

