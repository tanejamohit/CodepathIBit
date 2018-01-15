/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully *(left and right)* justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ' ' when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line. 

**Example:**

words: `["This", "is", "an", "example", "of", "text", "justification."]`

L: `16`.

Return the formatted lines as:

```
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```

> **Note:** Each word is guaranteed not to exceed L in length.
*/

// Fits strings into a single padded string
string justifyString(vector<string> A, int stringLength, int totalLength) {
    string justifiedString = "";
    if (A.size() == 1) {
        // Pad spaces at end of A[0]
        string padding(totalLength-stringLength, ' ');
        justifiedString = A[0] + padding;
    }
    else {
        int padding = (totalLength-stringLength)/(A.size()-1);
        int offset = (totalLength-stringLength)%(A.size()-1);
        //cout<<padding<<endl<<offset<<endl;
        for (int i = 0; i < A.size()-1; i++) {
            int paddingLength = padding;
            if (offset>0) {
                paddingLength++;
                offset--;
            }
            string padding(paddingLength, ' ');
            justifiedString = justifiedString + A[i] + padding;
        }
        justifiedString += A[A.size()-1];
    }
    //cout<<justifiedString<<endl;
    return justifiedString;
}


vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> result;
    
    //cout<<"size of input "<<A.size()<<endl;
    // Edge case
    if(A.size() == 0 || (A.size() == 1 && A[0] == "")) { return result; }
    
    int startPos = 0;
    int length = 0;
    
    for(int i = 0; i < A.size(); i++) {
        //cout<<"startPos = "<<startPos<<" i = "<<i<<" length = "<<length<<endl;
        length += A[i].length();
        // Check if length + min padding has exceeded
        if(length + (i-startPos) > B) {
            // Construct a subvector here
            vector<string>::const_iterator first = A.begin() + startPos;
            vector<string>::const_iterator last = A.begin() + i;
            vector<string> subsetStrings(first, last);
            
            // find length of just the strings we are trying to merge
            int stringLength = length - A[i].length();
            result.push_back(justifyString(subsetStrings, stringLength, B));
            
            length = A[i].length();
            startPos = i;
        }
    }
    
    // Last line justification
    if (startPos < A.size()) {
        string lastString = A[startPos++];
        while (startPos < A.size()) {
            //cout<<"startPos = "<<startPos<<" lastString = "<<lastString<<endl;
            lastString += " " + A[startPos++];
        }
        //cout<<"while loop ended with string "<<lastString;
        int paddingLength = B-lastString.length();
        //cout<<"padding length = "<<paddingLength;
        string padding(paddingLength, ' ');
        lastString += padding;
    
        result.push_back(lastString);
    }
    return result;
}
