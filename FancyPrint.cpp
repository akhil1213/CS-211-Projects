#include <iostream>
using namespace std;

void print(int q[]) {
    static int count =0;
    cout<< ++ count<<endl<<endl;//how many solutions
    int i,j,k,l;
    typedef char box[5][7];
    box bb,wb,*board[8][8];
    char ws = char(219);
    // "drawing" the crown in black queen box
    box bq =
    {
        ws, ws, ws, ws, ws, ws, ws,
        ws, ' ', ws, ' ', ws, ' ', ws,
        ws, ' ', ' ', ' ', ' ', ' ', ws,
        ws, ' ', ' ', ' ', ' ', ' ', ws,
        ws, ws, ws, ws, ws, ws, ws
    };//this is how u draw bq
    
    // This is how you draw the white queen
    box wq =
    {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ws, ' ', ws, ' ', ws, ' ',
        ' ', ws, ws, ws, ws, ws, ' ',
        ' ', ws, ws, ws, ws, ws, ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' '
    };//end of wq
    for(i=0;i<5;i++)//create the black boxes, since white boxes are already created because they are automatically white 
        for( j=0;j<7;j++)
        {wb[i][j]=' ';
            bb[i][j]=char(219);
        }
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if((i+j)%2==0)//set the board with the white and black tiles in a diagnol pattern making sure the next box is for the opposite queen using (i+j)%2.
                if(q[i]==j){
                    board[i][j]=&wq;
                } else {
                    board[i][j]=&wb;
                }
             else 
                if(q[i]==j){
                    board[i][j]=&bq;
                } else {
                   board[i][j]=&bb;
                }
            
    
    
 
    cout<<" ";
    for(i=0;i<7*8;i++)
        cout<<'_';
    cout<<endl;
    
    for(i=0;i<8;i++)
        for(k=0;k<5;k++)
        {cout<<" "<<char(179); 
            for(j=0;j<8;j++)
                for(l=0;
                    l<7;l++)
                    cout<<(*board[i][j])[k][l];
            cout<<char(179)<<endl; 
        }
    
    cout<<" ";
    for(i=0;i<7*8;i
        ++)
        cout<<char(196);
    cout<<endl;


}
bool ok(int q[], int c){
  for(int i = 0; i < c; i++){
      if(q[c] == q[i] || abs(q[c]-q[i]) == c-i) return false; 
  }
return true;
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