/*
Given a string S, find the longest palindromic substring in S.

**Substring of string S:**

`S[i...j]` where `0 <= i <= j < len(S)`

**Palindrome string:**

A string which reads the same backwards. More formally, S is palindrome if `reverse(S) = S`.

**Incase of conflict**, return the substring which occurs first ( with the least starting index ).

**Example :**

```
Input : "aaaabaaa"
Output : "aaabaaa"
```


*/
bool isPalindrome(string input, int start, int end) {
    while(end > start) {
        if(input[start] != input[end]) {
            return false; 
            
        }
        end--;
        start++;
    }
    return true;
}
string Solution::longestPalindrome(string A) {
    if(A.length()==0) { return ""; }
    string result = "";
    int palindromeLength = A.length();
    while(palindromeLength > 1) {
        for(int i=0; (i+palindromeLength) <= A.length(); i++) {
            if(isPalindrome(A, i, i+palindromeLength-1)) {
                return A.substr(i,palindromeLength);
            }
        }
        palindromeLength--;
    }
    return A.substr(0,1);
}
