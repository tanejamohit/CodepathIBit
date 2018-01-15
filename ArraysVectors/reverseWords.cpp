/*
Given an input string, reverse the string word by word.

**Example:**

Given s = `"the sky is blue"`,

return `"blue is sky the"`.

> * A sequence of non-space characters constitutes a word.
> * Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
> * If there are multiple spaces between words, reduce them to a single space in the reversed string.
*/
void reverseString(string &A, int startPos, int endPos) {
    while(endPos > startPos) {
        char temp = A[startPos];
        A[startPos] = A[endPos];
        A[endPos] = temp;
        
        startPos++;
        endPos--;
    }
}
void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    reverseString(A, 0, A.size()-1);
    int prevWordEndPos = 0;
    for(int i=0; i<A.size(); i++) {
        if(A[i]==' ') {
            reverseString(A, prevWordEndPos, i-1);
            prevWordEndPos = i+1;
        }
    }
    reverseString(A, prevWordEndPos, A.size()-1);
}
