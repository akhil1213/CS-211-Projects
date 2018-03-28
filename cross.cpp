#include <iostream>
using namespace std;
//[0][1][2][3][4][5][6][7]
bool ok(int a[], int currentBox){/*ok function checks if what number your trying to put into the current box is ok*/
  static int adjacencyMatrix[8][5] ={
    {-1},/*-1 always at the end because once the for loop sees a -1 it stops because of the teqnique called sentinel value and the inside the for loop will be an if statement checking if the value of the 2d array is -1 and then you break, if you see the -1 that means your done checking the neighbors and none of them returned a false value so its correct*/
    {0,-1},//box 1
    {0,1,-1},//box 2
    {0,2,-1},// box 3
    {1,2,-1},/*box 4, there is no 5 in here because 5 hasn't been filled up yet*/
    {1,2,3,4,-1},//box5
    {2,3,5,-1},//box 6
    {4,5,6,-1}
  };
  for(int i = 0; i <= currentBox-1; i++){/*you want to check all the boxes left of the currentbox index and make sure none of the previous boxes have the same value as the current boxes*/
      if(a[currentBox] == a[i]) return false;
  }
  for(int i = 0; i < 5 ; i++){
    if(adjacencyMatrix[currentBox][i] == -1) break;/*doesn't get to see whats after the -1 in that adjacencymatrix row since after seeing -1, all of the values are undefined and that would mess up*/ 
    if ( abs(a[currentBox] -a[adjacencyMatrix[currentBox][i]]) <= 1) return false;/*adjacencyMatrix[currentbox][i], gets index of currentneighbor and then you get the value using a[currentneighbor] and you subtrract it from the currentbox to see if its consecutive */
  }
  return true;
}
void backTrack( int &index){/*to make sure backtrack actually changes the index*/
  index--;
  if(index == -1) exit(1);/*there arent any more solutions since you checked for solutions and index decremented all the way out of the board */
}
void print(int a[]){
  static int solutions = 0;
  cout << "Solution " << ++solutions << endl;
  cout << "  " << a[1] << " " << a[4] << endl;
  cout << a[0] << " " << a[2] << " " << a[5] << " " << a[7] << endl;
  cout << "  " << a[3] << " " << a[6] << endl;
}
int main(){
  int cross[8] = {0};
  int length = 8;
  int index = 0;
  while(true){
    cross[index]++;/*increment cross each time and then check if its a valid box to put it inside of */
    if(cross[index] == 9){/*should do it right after increment because ok might throw an error*/
      cross[index] = 0; /* set it back to a clean slate because you hit a dead end since cross[index] became 9 */
      backTrack(index);/* so now cross[index] is 0 and the previous index gets incremented and then backtrack tries to find a solution for the previous NEW index increment */
      continue;/*skip everything below and start the loop again*/
    }
    if(ok(cross,index)){ index++;/*if that box is ok then you increment index so you go to the next box*/
        if(index==8){ 
                print(cross); /*that means all the boxes have correct numbers, ok function returns true for everything up till 7 and then you can print */
                backTrack(index);/*go back and look for more solutions*/
        }
    }
    /*don't have to write an else statement because your else statement goes back up to the while automatically and increments cross[index] which is our else*/
    
  }
  
}
