/* Problem Statement
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

**Example:** 
Given `[100, 4, 200, 1, 3, 2]`,
The longest consecutive elements sequence is `[1, 2, 3, 4]`. Return its length: `4`.

Your algorithm should run in `O(n)` complexity.
*/
int Solution::longestConsecutive(const vector<int> &A) {
    std::unordered_set<int> S(A.begin(), A.end());
    int maxSequenceLength = 0;
    for (int i = 0; i < A.size(); i++) {
        int x = A[i];
        
        // Only proceed if it is the first element in a sequence
        if (S.find(x-1) == S.end()) {
            int y = x;
            while (S.find(y+1) != S.end()) {
                y += 1;
            }
            maxSequenceLength = max(maxSequenceLength, y-x+1);
        }
    }
    return maxSequenceLength;
}
