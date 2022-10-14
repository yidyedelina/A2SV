#include <iostream>
#include <vector>
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{
    int totalSum = 0, currSum = 0, minSum = INT32_MAX;
    int n = cardPoints.size();
    for (int i = 0; i < n; i++)
    {
        totalSum += cardPoints[i];
    }
    int left = 0, right = 0;
    while(right < n){
        if((right - left + 1) == (n - k + 1)){
            minSum = min(currSum, minSum);
            currSum -= cardPoints[left];
            left++;
        }
        currSum += cardPoints[right];
        right++;
    }
    return totalSum - minSum;
}

int main(){
    vector<int> b{7, 8, 3, 4, 5, 6, 7};
    int a = maxScore(b, 3);
    cout << a;
}