// C++ program for Naive Pattern 
// Searching algorithm 
#include <bits/stdc++.h> 
using namespace std; 
  
void search(string p, string str) 
{
    int pLen = p.length(), strLen = str.length();
    if(pLen > strLen){
      cout<<"Pattern Not Found"<<endl;
      return;
    }
    
    int limit = strLen - pLen;

    for(int i=0; i<=limit; i++){
        int j;
        for(j=0; j<pLen; j++){
            if(p[j] != str[i+j])
                break;
        }
        if(j==pLen){
          cout<<"Pattern found at index " << i << endl;
        }
    }
    
    
} 
  
// Driver Code 
int main() 
{ 
    string str = "AABAAAB"; 
    string p = "AA"; 
    search(p, str); 
    return 0; 
} 
 
