/*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

**For example:**

Given the array `[-2,1,-3,4,-1,2,1,-5,4]`,

the contiguous subarray `[4,-1,2,1]` has the largest sum = 6.

For this problem, return the maximum sum. 
*/
int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int maxSum = INT_MIN;
    int runningSum = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > maxSum) {
            maxSum = A[i];
        }
        if ((runningSum + A[i]) > 0) {
            runningSum += A[i];
        }
        else {
            runningSum = 0;
        }
        if (runningSum > 0) {
            maxSum = max(runningSum, maxSum);
        }
    }
    return maxSum;
}
