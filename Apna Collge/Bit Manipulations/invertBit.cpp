// CPP program to invert actual bits 
// of a number. 
#include <bits/stdc++.h> 
using namespace std; 

int invertBits(int num) 
{ 
	// calculating number of bits 
	// in the number 
	int x = log2(num) + 1; 

	// Inverting the bits one by one 
	for (int i = 0; i < x; i++) 
	num = (num ^ (1 << i)); 

	// cout << num; 
    return num;
} 

// Driver code 
int main() 
{ 
	int num = 11; 
	cout<<invertBits(num); 
	return 0; 
} 
