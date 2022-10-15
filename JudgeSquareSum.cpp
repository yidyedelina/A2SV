#include <iostream>
using namespace std;

bool judgeSquareSum(int c)
{
    int l = 0, r = c - 1;
    while(r < l){
        int multiply = l * l + r * r;
        if(multiply == c){
            return true;
        }
        else if(multiply < c){
            l++;
        }else{
            r--;
        }
    }
    return false;
}