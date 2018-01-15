/*Implement atoi to convert a string to an integer.

**Example :**

```
Input : "9 2704"
Output : 9
```

*Note: There might be multiple corner cases here. Clarify all your doubts using "See Expected Output".*

> **Questions:**
>
> **Q1.** Does string contain whitespace characters before the number?
> **A.** Yes
>
> **Q2.** Can the string have garbage characters after the number?
> **A.** Yes. Ignore it.
> 
> **Q3.** If no numeric character is found before encountering garbage characters, what should I do?
> **A.** Return 0.
>
> **Q4.** What if the integer overflows?
> **A.** Return INT_MAX if the number is positive, INT_MIN otherwise.
>


**Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.**
*If you do, we will disqualify your submission retroactively and give you penalty points.*
*/

int Solution::atoi(const string A) {
    
    if (!(A[0] == '-' || 
    (A[0]>='0' && A[0]<='9') ||
    A[0] == '+')) { return 0; }
    
    int result = 0;
    bool isNegative = (A[0]=='-')?true:false;
    int position = (A[0]=='-' || A[0]=='+')?1:0;
    
    while (position < A.length()) {
        if (A[position]>='0' && A[position]<='9') {
            if((result > (INT_MAX/10))
            || ((result == INT_MAX/10) && (A[position]-'0' >= INT_MAX%10))) {
                //cout<<"Int max happened with result = "<<result;
                return isNegative?INT_MIN:INT_MAX;
            }
            result = result*10 + A[position] - '0';
            //cout<<"Result = "<<result<<endl;
        } else {
            return isNegative?result*-1:result;
        }
        position++;
    }
    return isNegative?result*-1:result;
}
