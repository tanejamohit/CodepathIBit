/*
Given numRows, generate the first numRows of Pascal's triangle.

Pascal's triangle : To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1. 

**Example:**

Given numRows = 5,

Return

```
[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
```

*/
vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> result;
    for (int i = 1; i <= A; i++) {
        vector<int> row;
        row.push_back(1);
        for (int j = 1; j < i-1; j++) {
            row.push_back(result[i-2][j-1] + result[i-2][j]);
        }
        if (i != 1) {
            row.push_back(1);
        }
        result.push_back(row);
    }
    return result;
}
