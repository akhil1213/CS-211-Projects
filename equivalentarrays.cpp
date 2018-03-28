#include <iostream>
using namespace std;
bool equivalent(int a[],int b[], int n){
int shifter[n] = {0};
int shift;
  for(int j = 0; j < n; j++){
    if(a[0] == b[j]){
        shift = j;//break from loop, stop loop and shift is now equal to whatever it is
    }
  }/*in this case shift would be = to 4,however arrays start with 0 so shift is actually = to 3, and it takes 4 right-shifts for 12345 to become 34512
  */
int theWayWeShift = n-shift;
  for (int i=0;i<n;i++) {
    int shiftWay = i+theWayWeShift;
    if(shiftWay >= n){
      shifter[i] = a[shiftWay%n];
    }
    else shifter[i] = a[shiftWay];
  
    /*since the shift is 3 we know we need to go i+n-shift places see if we can turn A into B. We add i+n-shift because b copies each element inside of array b, however, when we get to element n-1, we need to copy the first element which is why we %n because the highest index of the array is n-1 and by modding it by n we make sure it never goes past index n-1. 
    */
  }
  for(int check = 0; check < n; check++){
    if(shifter[check] != b[check]) return false;
  }
return true;
}
int main(){
cout << boolalpha; // to show boolean value as "true" or "false"

   int a1[5] = {1, 2, 3, 4, 5};
   int a2[5] = {3, 4, 5, 1, 2};
   cout << equivalent(a1, a2, 5) << endl; // true

   int a3[3] = {1, 2, 3};
   int a4[3] = {2, 3, 3};
   cout << equivalent(a3, a4, 3) << endl; // false

   int a5[4] = {1, 1, 0, 1};
   int a6[4] = {1, 0, 1, 1};
   cout << equivalent(a5, a6, 4) << endl; // true

}