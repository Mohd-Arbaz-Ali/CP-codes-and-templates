// A O(n) solution that uses 
// table fact[] to calculate 
// the Permutation Coefficient 
#include<bits/stdc++.h> 
using namespace std; 

// Returns value of Permutation 
// Coefficient P(n, k) 
int permutationCoeff(int n, int k) 
{ 
	int fact=1;
  	for(int i=n;i>n-k;i--){
      fact*=i;
    }
  return fact;
} 

// Driver Code 
int main() 
{ 
	int n = 10, k = 2; 
	
	cout << "Value of P(" << n << ", "
		<< k << ") is "
		<< permutationCoeff(n, k); 

	return 0; 
} 

// This code is contributed by shubhamsingh10 
