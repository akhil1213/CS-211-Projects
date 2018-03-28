//rows : q[c], columns : c 
#include <iostream>
#include <cstdlib>
using namespace std;
bool ok(int q[], int c){
  for(int i = 0; i < c; i++){
      if(q[c] == q[i] || abs(q[c]-q[i]) == c-i) return false; //this means the queen is on the same row as a prior queen, up diagonal if the difference in the columns c-i is equal to the difference in the rows q[c] - q[i]
  }
return true;
}

void backtrack(int q[], int  &c){//changing the c you want it to change
  c--;//go back a column 
  if(c==-1) exit(1);//no more solutions left
  q[c]++;//to go to the next row, lets say q[c] = 7 prior to q[c]++, thats why you got to check q[c] == 8
  if(q[c]==8) backtrack(q,c);
}

int nqueens(int n) {
   int* q = new int[n];
   q[0] = 0;
   int c = 0, solutions = 0;
   while (c >= 0) {
       if (c == n-1) {
          ++solutions;
          c--;//you usually backtrack here
       }
      else
         q[++c] = -1;
      while (c >= 0) {
         q[c]++;
         if (q[c] == n)
            c--;
         else if (ok(q, c))
            break;
      }
   }
   delete[] q;
   return solutions;
}
int main(){
  int n;
  cout << "Please enter a number for n" << endl;
  cin >> n;
  for(int i =1; i <= n; i++){
    cout << "The number of solutions for " << i << " queens is:" << nqueens(i) << endl;
  }
}