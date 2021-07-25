#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand((unsigned)time(0));
	int notswapping = 0;     // Tracks number of cases where not swapping wins
	int swapping = 0;    // Tracks number of cases where swapping wins
	int N = 1000;   // Changes number of cases(increase to increase accuracy)
	for(int i=0; i<N; ++i){
		vector<string> doors(3,"GOAT"); // List of items behind doors 1, 2, 3
		int car_allotment = rand()%3; //A car is alloted to one of the doors randomly
	    doors[car_allotment] = "CAR";
		int initial_choice = rand()%3; //A door is chosen by the player randomly
		cout << "Case " << i+1 << ":" << endl;
		cout <<  "Player has chosen door " << initial_choice+1 << endl;
		vector<int> host_choices; //A list of choices for the host to reveal as part of game
		for(int j=0; j<3; ++j){
			if(doors[j]!="CAR" && j!=initial_choice)
	            host_choices.push_back(j);}
		int door_reveal = host_choices[rand()%host_choices.size()]; // Host randomly reveals a door which doesn't have a car
		cout << "Host has revealed a goat behind " << door_reveal+1 << endl;
		cout << "Our player has chosen to swap" << endl; //As an experiment to show that swapping is beneficial, our palyer swaps
		int second_choice = -1; //A new choicew is made by the user where he/she swaps
		for(int k=0; k<3; ++k){
			if( k!=initial_choice && k!=door_reveal)
	            second_choice = k;}
		if(doors[second_choice]=="CAR"){ //If our second_choice has a car
			swapping++; //The player won by swapping and it is recorded
			cout << "Player won by swapping" << endl;}
		else{ //Otherwise if the car was chosen initially by the player
			notswapping++; // The player lost by not swapping and it is recorded
			cout << "Player lost by swapping" << endl;}
		for(auto it : doors)  //Prints the items behind each door
			cout << it << " ";
		cout << endl;
		cout << endl;}
	cout << "Swapping = " << (float)swapping/N << endl;    // Probability that he wins by swapping
	cout << "Not swapping = " << (float)notswapping/N << endl;    // Probability that he wins by not swapping
}
