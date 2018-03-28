#include <iostream>
using namespace std;

int main(){
      string outcome; 
       cout << "Enter the race outcome: ";
      cin >> outcome;
      //if (valid(outcome) == false) cout << "Each team has the same amount of runners, try again.";
      double scorecounter[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
      double lettercounter[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int index = 0;
        char x = 'A'; 
        int runners = lettercounter[0];
        int round;
        int teamcounter = 0;
       for(int j=0; j < 26; j++){
          round = 1;//each round/iteration the index goes up by 1 and we need to count that towards the score
          
          for(int i = 0; i < outcome.length(); i++){
              if(outcome[i] == x ){
                scorecounter[index] += round;//add the index of the place each member of team got
                lettercounter[index]++;//added how many runners for each team there were. scorecounter divides lettercounter to get average team score
                if(lettercounter[index] > runners) runners = lettercounter[index];//have to get the max of the lettercounter array to get how many runners there are
              } 
              round++;
          }
       if(scorecounter[j] > 0) teamcounter++;//counts how many teams there are
       x++;
       index++;
       }
       char y[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W','X', 'Y','Z'};
       cout << "There are " << teamcounter << " teams." << endl;
       cout << "Each team had " << runners << " runners." << endl;
       cout << "Team\t" << "Score" << endl;//\t is an automatic tab
       for(int i = 0; i < 26; i++){
         
         if(scorecounter[i] > 0) cout <<  y[i] << "\t" << scorecounter[i] / lettercounter[i] << endl;
       }
      
      
      return 0;
}
