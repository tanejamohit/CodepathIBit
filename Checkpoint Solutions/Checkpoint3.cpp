/* Problem Statement
Given an array of **non negative** integers `A`, and a range `(B, C)`, 
find the number of continuous subsequences in the array which have sum `S` in the range `[B, C]` or `B <= S <= C`

Continuous subsequence is defined as all the numbers `A[i], A[i + 1], .... A[j]`
where `0 <= i <= j < size(A)`

**Example :**

```
A : [10, 5, 1, 0, 2]
(B, C) : (6, 8)
```

ans = 3 
as `[5, 1], [5, 1, 0], [5, 1, 0, 2]` are the only 3 continuous subsequence with their sum in the range [6, 8]

> **NOTE :** The answer is guranteed to fit in a 32 bit signed integer. 

*/

int Solution::numRange(vector<int> &A, int B, int C) {
    int startPos = 0;
    int endPosMin = 0;
    int endPosMax = 0;
    int runningSumMin = A[0];
    int runningSumMax = A[0];
    int numSequences = 0;
    bool reachedMinBound = false;
    bool reachedMaxBound = false;

    
    while (endPosMin < A.size()) {
        //cout<<"Running sum min = "<<runningSumMin<<" running sum max = "<<runningSumMax<<endl;
        if (runningSumMin < B) {
            //cout<<"Increasing minsum"<<endl;
            endPosMin += 1;
            runningSumMin += A[endPosMin];
        }
        else {
            reachedMinBound = true;
        }
        
        if ((endPosMax < (A.size()-1)) && 
        (runningSumMax + A[endPosMax+1] <= C)) {
            //cout<<"Increasing maxsum"<<endl;
            endPosMax += 1;
            runningSumMax += A[endPosMax];
        }
        else {
            reachedMaxBound = true;
        }
        
        if (reachedMinBound && reachedMaxBound) {
            //cout<<"Reached Bounds"<<endl;
            if (runningSumMin >= B && runningSumMax <= C) {
                numSequences += endPosMax - endPosMin + 1;
                //cout<<"sequences="<<numSequences<<" start="<<startPos<<" min="<<endPosMin<<" max="<<endPosMax<<endl;
                
                runningSumMax -= A[startPos];
                runningSumMin -= A[startPos];
                startPos += 1;
                
                reachedMinBound = false;
                reachedMaxBound = false;
            }
            else {
                if(endPosMin == A.size()-1){
                    break;
                }
                else {
                    runningSumMax -= A[startPos];
                    runningSumMin -= A[startPos];
                    startPos += 1;
                    
                    reachedMinBound = false;
                    reachedMaxBound = false;
                }
            }
        }
    }
    
    return numSequences;
}
