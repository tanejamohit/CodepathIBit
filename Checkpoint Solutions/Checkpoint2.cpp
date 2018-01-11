/* Problem Statement
Print concentric rectangular pattern in a 2d matrix. 
Let us show you some examples to clarify what we mean. 

**Example 1:**

**Input:** A = 4.
**Output:**

```
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
```

**Example 2:**

**Input:** A = 3.
**Output:**

```
3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 
```

The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on. 

You will be given A as an argument to the function you need to implement, and you need to return a 2D array. 
*/

vector<vector<int> > Solution::prettyPrint(int A) {
    vector<vector<int> > result;
    for (int i = 0; i < 2*A-1; i++) {
        vector<int> row;
        int rowOffset = i>=A ? 2*(A-1) - i : i;
        for (int j = 0; j < 2*A-1; j++) {
            int columnOffset = j>=A ? 2*(A-1) - j : j;
            row.push_back(A-std::min(rowOffset, columnOffset));
        }
        result.push_back(row);
    }
    return result;
}