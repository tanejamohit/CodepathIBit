/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

**Example:**

If the vector has `[1, 2, 3]`

the returned vector should be `[1, 2, 4]`

as `123 + 1 = 124`.


> 
> **NOTE:** Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
> For example, for this problem, following are some good questions to ask :
> 
> * **Q :** Can the input have 0's before the most significant digit. Or in other words, is `0 1 2 3` a valid input?
> * **A :** For the purpose of this question, **YES**
>
>
> * **Q :** Can the output have 0's before the most significant digit? Or in other words, is `0 1 2 4` a valid output?
> * **A :** For the purpose of this question, **NO**. Even if the input has zeroes before the most significant digit.
>
*/

vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> result;
    int lastOverflowPosition = 0;
    int overflowing = false;
    bool notInitialZero = false;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != 0 || notInitialZero) {
            notInitialZero = true;
            result.push_back(A[i]);
        }
    }
    if (result.size() == 0) {
        result.push_back(0);
    }
    
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == 9 && !overflowing) {
            overflowing = true;
            lastOverflowPosition = i;
        }
        else if (result[i] != 9) {
            overflowing = false;
        }
        
    }
    
    if (!overflowing) {
        result[result.size() - 1] += 1; 
    }
    else {
        if (lastOverflowPosition == 0) {
            result.insert(result.begin(), 1);
            lastOverflowPosition = 1;
        }
        else {
            result[lastOverflowPosition-1] += 1;
        }
        for(int i = lastOverflowPosition; i < result.size(); i++) {
            result[i] = 0;
        }

    }
    return result;
}
