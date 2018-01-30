int Solution::nchoc(int units, vector<int> &bags) {
    long long int sum = 0;
    
    make_heap(bags.begin(), bags.end());
    while(units) {
        int max = bags.front();
        sum = (sum+max)%1000000007;
        pop_heap(bags.begin(), bags.end());
        bags.back() = max/2;
        push_heap(bags.begin(), bags.end());
        units--;
    }
    return sum;
}
