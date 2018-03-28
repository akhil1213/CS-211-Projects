#include <iostream>
using namespace std; 

int main() {
  int q[8];
  int c = 0;
  q[0] = 0;
  int counter = 0;
  
  nextcolumn: c++;  //Next column section
  if (c == 8) 
    goto print;
  q[c] = -1;

  nextrow: q[c]++;
  if (q[c] == 8)
    goto backtrack;
  
  for (int i = 0; i < c; ++i)
    if (q[i] == q[c] || (c-i) == abs(q[c]-q[i])) 
      goto nextrow;
  goto nextcolumn;
  
  backtrack: c--;
  if (c == -1)
    return 0;
  goto nextrow;
  
  print:
  cout << endl;
  cout<<"Solution number: "<<++counter<<":"<<endl;
  for(int i = 0; i < 8; i++){
    cout<<q[i];
  }
  goto backtrack;
}