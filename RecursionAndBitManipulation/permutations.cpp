void generatePermutationsHelper(vector<int> currentPermutation, vector<int> availableIntegers, vector<vector<int> > &result) {
  
  if(availableIntegers.size() == 0)  {
    result.push_back(currentPermutation);
    return;
  }
  
  
  for (int i = 0; i < availableIntegers.size(); i++) {
      vector<int> currentPermutationCopy = currentPermutation;
    currentPermutationCopy.push_back(availableIntegers[i]);
  
    vector<int> availableIntegersCopy = availableIntegers;
    availableIntegersCopy.erase(availableIntegersCopy.begin()+i);
  
    generatePermutationsHelper(currentPermutationCopy, availableIntegersCopy, result);

  }  
}

vector<vector<int> > Solution::permute(vector<int> &input) {
  vector<vector<int> > result;
  vector<int> currentPermutation;
  generatePermutationsHelper(currentPermutation, input, result);
  return result;

}
