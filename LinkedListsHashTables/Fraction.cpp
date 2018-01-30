string itoa(long long int num) {
    std::ostringstream stringStream;
    stringStream << num;
    //cout<<num;
    return stringStream.str();
}

string Solution::fractionToDecimal(int A, int B) {
    string result;
    std::unordered_map<int, int> modulosEncountered;
    long long int dividend, modulo, newA = A, newB = B;
    
    if (A==0) { return "0"; }
    if ((A < 0 && B > 0) || ( A > 0 && B < 0)) { 
        result = "-";
    }
    
    newA = abs(newA);
    newB = abs(newB);
    dividend = newA/newB;
    modulo = newA%newB;
    result += itoa(dividend);
    
    if(modulo) {
        result += ".";
    }
    
    while ((modulo != 0) && 
    (modulosEncountered.find(modulo) == modulosEncountered.end())) {
        modulosEncountered[modulo] = result.size();
        //cout<<modulo<<endl;
        modulo *= 10;
        while ((modulo < newB) && 
        (modulosEncountered.find(modulo) == modulosEncountered.end())) {
            result += "0";
            modulosEncountered[modulo] = result.size();
            //cout<<modulo<<endl;
            modulo *= 10; 
        }
        dividend = modulo/newB;
        modulo = modulo%newB;
        result += itoa(dividend);
    }
    
    if (modulo != 0) {
        // Repitition happened put parentheses correctly
        int lengthBeforeModulo = modulosEncountered[modulo];
        result = result.substr(0, lengthBeforeModulo) + "(" + result.substr(lengthBeforeModulo) + ")";
    }
    return result;
}
