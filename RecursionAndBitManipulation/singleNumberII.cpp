int Solution::singleNumber(const vector<int> &A) {
    if (A.size() < 1) { return -1; }
    int result = 0;
    int mask1 = 0;
    int mask2 = 0;

    for (int i =0; i < A.size(); i++) {
        for (int pos = 0; pos < 32; pos++) {
            if (A[i]&(1<<pos)) {
                if (mask1&(1<<pos)) {
                    if (mask2&(1<<pos)) {
                        mask1 = mask1^(1<<pos);
                        mask2 = mask2^(1<<pos);
                    }
                    else {
                        result = result^(1<<pos);
                        mask2 = mask2|(1<<pos);
                    }
                }
                else {
                    result = result|(1<<pos);
                    mask1 = mask1|(1<<pos);
                }
            }
        }
    }
    return result;
}
