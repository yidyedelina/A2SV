#include <vector>
#include <algorithm>
using namespace std;
int bagOfTokensScore(vector<int> &tokens, int power)
{
    int score = 0;
    int maxScore = 0;
    int left = 0;
    int right = tokens.size() - 1;
    sort(tokens.begin(), tokens.end());
    while (left <= right)
    {
        if (power >= tokens[left])
        {
            power -= tokens[left++];
            score++;
            maxScore = max(maxScore, score);
        }
        else if (score > 0)
        {
            power += tokens[right--];
            score--;
        }
        else
        {
            break;
        }
    }
    return maxScore;
}