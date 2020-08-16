#include<iostream>
#include<string>
using namespace std;

int main()
{
  int len_of_voters;
  cin>>len_of_voters;
  
  string people;
  cin>>people;
  
  int voters_of_A=0, voters_of_B=0;
  
  for(int i=0; i<len_of_voters; i++)
  {
  	if(people[i] == 'A')
      voters_of_A++;
    
    else if(people[i] == 'B')
      voters_of_B++;
  }
  
  int j=0;
  while(people[j] == '-')
  {
    j++;
  }
  
  if(people[j] == 'A')  // case 1: ---A or ---B
  {
      voters_of_A += j;
  }
  
  int start = j;
  
  for(;j<len_of_voters;)
  {
  	while(people[j] == '-' && j< len_of_voters) 
      j++;
    
    if(j == len_of_voters) break; // if we reach at the end 
    
    if(people[j] == 'A')
    {
      if(start == j){
      	j++;
        continue;
      }
      
      voters_of_A = voters_of_A + (j-start-1);
      start = j;
      j++;
      continue;
    }
    
    start = j;
    j++;
    
    while(people[j] == '-' && j<len_of_voters)
      j++;
    
    if(j == len_of_voters)
      voters_of_B = voters_of_B + (j-start-1);
    else{
    	if(people[j]=='A')
        {
          voters_of_A = voters_of_A + (j-start-1)/2;
          voters_of_B = voters_of_B + (j-start-1)/2;
          start = j;
          j++;
        }
      	else{
        	voters_of_B = voters_of_B + (j-start-1);
        }
    }
    
  }
  
  if(voters_of_A > voters_of_B)
    cout<<"A";
  
  else if(voters_of_A == voters_of_B)
    cout<<"Coalition government";
  
  else
    cout<<"B";
  
  
  return 0;
}
