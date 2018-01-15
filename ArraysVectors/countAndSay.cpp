/*
The count-and-say sequence is the sequence of integers beginning as follows:

```
1, 11, 21, 1211, 111221, ...
```

`1` is read off as **`one 1`** or `11`.
`11` is read off as **`two 1s`** or `21`.

`21` is read off as **`one 2, then one 1`** or `1211`.

Given an integer n, generate the nth sequence.

*Note: The sequence of integers will be represented as a string.*

**Example:**

if `n = 2`,
the sequence is `11`.
*/
string itoa(int count) {
    string result = "";
    while(count>0) {
        char value = '0'+(count%10);
        result = value + result;
        count /= 10;
    }
    return result;
}
void nextCount(string &input) {
    int count = 0;
    int size = input.length();
    for(int i=0; i < size; i++) {
        if(((i+1) < size) && (input[i] == input[i+1])) {
            count += 1;
        }
        else {
            input += itoa(count+1);
            input += input[i];
        }
    }
    input.erase(0,size);
}
string Solution::countAndSay(int A) {
    if (A < 1) { return ""; }
    string currentCount = "1";
    while(A-1) {
        nextCount(currentCount);
        A--;
    }
    return currentCount;
}
