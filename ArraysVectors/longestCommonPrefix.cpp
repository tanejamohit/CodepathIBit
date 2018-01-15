/*Write a function to find the longest common prefix string amongst an array of strings.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.

As an example, longest common prefix of `"abcdefgh"` and `"abcefgh"` is `"abc"`.

Given the array of strings, you need to find the longest S which is the prefix of **ALL** the strings in the array.

**Example:**

Given the array as:

```
[

  "abcdefgh",

  "aefghijk",

  "abcefgh"
]
```

**The answer would be "a".**
*/
string Solution::longestCommonPrefix(vector<string> &A) {
    string result = "";
    
    for (int pos = 0; pos < A[0].length(); pos++) {
        for (int i =1; i< A.size(); i++) {
            if((pos > (A[i].length()-1)) || (A[i][pos] != A[0][pos])) {
                return result;
            }
        }
        result += A[0][pos];
    }
    return result;
}