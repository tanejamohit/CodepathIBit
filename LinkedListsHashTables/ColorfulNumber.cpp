int Solution::colorful(int A) {
    A = abs(A);
    std::unordered_set<int> products;
    int outerIteration = A;

    while(outerIteration > 0) {
        int product = 1;
        int innerIteration = outerIteration;
        while (innerIteration > 0) {
            int currentNumber = innerIteration%10;
            innerIteration /= 10;
            product *= currentNumber;
            if(products.find(product) != products.end()) {
                return 0;
            }
            products.insert(product);
        }
        outerIteration /= 10;
    }
    return 1;
}
