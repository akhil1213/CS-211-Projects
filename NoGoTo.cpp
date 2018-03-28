//rows : q[c], columns : c 
#include <iostream>
#include <cstdlib>
using namespace std;
bool ok(int q[], int c){
  for(int i = 0; i < c; i++){
      if(q[c] == q[i] || abs(q[c]-q[i]) == c-i) return false; 
  }
return true;
}
void print(int q[]){
  static int numSolutions = 0;
  cout << "Solution #" << ++numSolutions << ": ";
  for(int i = 0; i < 8; i++){
    cout << q[i];
  }
  cout << endl;
}
void backtrack(int q[], int  &c){//changing the c you want it to change
  c--;//go back a column 
  if(c==-1) exit(1);//no more solutions left
  q[c]++;
  if(q[c]==8) backtrack(q,c);
}

int main (){
  int q[8] = {0};
  int  c = 0;
  while(c>=0){
    c++;
    if(c==8){
      print(q);
      backtrack(q,c);
    }
    else q[c] = -1;
    while(c>=0){
      q[c]++;
      if(q[c]==8) backtrack(q, c); 
      if (ok(q,c)){ 
        break;
      }
    }
  }
    
    
    
}