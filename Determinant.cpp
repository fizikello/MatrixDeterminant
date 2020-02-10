#include <iostream>
#include <vector>

using namespace std;
int signature( vector<int> v );

long long determinant(vector< vector<long long> > m)
{
  // The Leibniz formula requires to make all permutations for the range [0, 1, .. , N].
  // Number of factors equals N! 
  // A sign of each factor is needed
  
  vector<int> v(m.size(), 0);
  for(int i = 0; i < v.size(); i++)
    v[i] = i;
    
  long det = 0;
   
  do {
        long factor = signature(v);
        
        for(int i = 0; i < v.size(); i++)
          factor *= m[i][v[i]];
          
        det += factor;
    } while (next_permutation(v.begin(), v.end())); 
   
  return det;
}

int signature( vector<int> v ) 
{
  int sum = 0;
  for(int i = 0; i < v.size(); i++)
  {
    for(int j = i; j < v.size(); j++)
      if( v[i] > v[j] ) sum++;
  }  
  return sum % 2 == 0 ? 1 : -1; 
}
