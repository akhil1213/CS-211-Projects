#include <iostream>
using namespace std;
int main() {
  int q[8][8] = {0};
  q[0][0] = 1;
  int c =0,r;
  int counter = 0;
  if(c==8) goto backtrack;
  
  nextcolumn: c++;
  if(c==8) goto print;
  r = -1;
  
  nextrow: r++;
  if(r==8)  goto backtrack; //couldn't find a solution 
  
  
  //rowcheck
  for(int i = 0; i < c; i++){
    if(q[r][i] == 1) goto nextrow;
  }
  for(int i = 1; r-i >= 0 && c-i >=0; i++){
      if(q[r-i][c-i] == 1) goto nextrow;
  }
  for(int i = 1; (r+i) < 8 && (c-i) >= 0; i++){
    if(q[r+i][c-i] == 1) goto nextrow;//down diagonal
  }
  
  q[r][c] = 1;
  goto nextcolumn;
  
  backtrack: c--;
    if(c==-1) return 0;
    r = 0;
    while(q[r][c] == 0){
      r++;
    }
    q[r][c] = 0;
    goto nextrow;
  
  print:
  counter++;
    cout << "This is solution number " << counter << endl; 
    for(int r = 0; r < 8; r++){
      for(int c = 0; c< 8; c++){
        cout << q[r][c];
      }
      cout << endl;
    }
    goto backtrack;
}