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
            cout << cardPoints[left] << endl;
            left++;
        }
        currSum += cardPoints[right];
        right++;
    }
    minSum = min(minSum, currSum);
    return totalSum - minSum;
}

int main(){
    vector<int> b{96, 90, 41, 82, 39, 74, 64, 50, 30};
    int a = maxScore(b, 8);
    cout << a;
}