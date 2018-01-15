/*
Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1. 

**Input:**

```
number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
```

**Output:**

```
return 1 if the number is a power of 2 else return 0

```

**Example:**

```
Input : 128
Output : 1
```

*/
void trimZeros(string &A) {
    while(A[0] == '0') {
        A.erase(A.begin());
    }
}

bool divideByTwo(string &A) {
    for(int i = A.size()-1; i>=0; i--) {
        if((A[i] - '0')%2)
        {
            if(i == A.size()-1) { return false; }
            A[i+1] += 5;
        }
        A[i] = '0' + (A[i] - '0')/2;
    }
    trimZeros(A);
    return true;
    
}
int Solution::power(string A) {
    if (A.size() == 1 && A[0] < '2') { return 0; }
    while (A.compare("2") != 0) {
        if(!divideByTwo(A)) { 
            return 0;
        }
    }
    return 1;
}
