/*there is no perfect such that the last two digits are both odd, a random number will be displayed due to an overflow.
*/
#include <iostream>
using namespace std;
int perfectsquare(){
  for(int i = 4; i < 100000; i++){
    int x = i*i;
    if((x%10)%2==1){
      if((x%100/10)%2==1){
	    //cout << i << endl;//prints i to be 65,537 proving that i := 65,537
        return x;
      }
    }
  }
}
int main(){
  cout << perfectsquare() << endl;
  int i = 65537*65537;
  cout << i;
} 
/*
The program returns an integer such that the last two digits are both odd, however, that integer isn't a perfect square. This is because on the last iteration i equals 65,537 and i*i = 4,295,098,369 is bigger then the largest possible integer 2147483647, therefore, in c++ 65537*65537 = 131073. Since this integer 131073 last two digits are both odd it returns it. If the condition for the for loop inside the perfectsquare function is less then 100000 perfectsquare will return 0 because there is no number that is a square and its last two digits are odd and x is automatically initialized to 0.
*/