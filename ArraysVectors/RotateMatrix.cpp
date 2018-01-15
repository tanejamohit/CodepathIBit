/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place. 

Note that if you end up using an additional array, you will only receive partial score. 

**Example:** 

If the array is 

```
[
    [1, 2],
    [3, 4]
]
```

Then the rotated array becomes: 

```
[
    [3, 1],
    [4, 2]
]
```
*/
void Solution::rotate(vector<vector<int> > &A) {
        // Do not write main() function.
        // Do not read input, instead use the arguments to the function.
        // Do not print the output, instead return values as specified
        // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        int size = A.size()-1;
        int offset = 0;
        
        while (size > offset) {
            // Rotate the outer boundry of the array
            for (int i = 0; i < size-offset; i++) {
                
                // up to right
                int temp = A[offset][offset+i];
                A[offset][offset+i] = A[size-i][offset];
                //cout<<"Replacing "<<temp<< " with "<<A[size-i][offset]<<endl;
                
                // right to down
                int temp2 = A[offset+i][size];
                A[offset+i][size] = temp;
                //cout<<"Replacing "<<temp2<< " with "<<temp<<endl;
                
                // down to left
                temp = A[size][size-i];
                A[size][size-i] = temp2;
                //cout<<"Replacing "<<temp<< " with "<<temp2<<endl;
                
                // left to up
                //cout<<"Replacing "<<A[size-i][offset]<< " with "<<temp<<endl;
                A[size-i][offset] = temp;
                
            }
            offset += 1;
            size -= 1;
        }
        
    }
