class Solution:
    # @param A : integer
    # @return an integer
    def sqrt(self, A):
        if (A<0 or A==0):
            return 0
        if (A==1):
            return 1
        start = 1
        end = A
        mid = 0
        
        while(start<=end):
            mid = (start+end)/2
            if ((mid*mid == A) or ((mid+1)*(mid+1) > A and mid*mid < A)):
                break
            
            if (mid*mid > A):
                end = mid-1
            else:
                start = mid+1
        return mid
