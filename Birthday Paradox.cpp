#include <bits/stdc++.h>
using namespace std;

int main(){
	srand((unsigned)time(0));
	int pair_exist = 0; // Tracks how many cases have pairs
	int N=3000; // Changes number of cases(increase to increase accuracy)
	int num=23; // Number of people whose birthdays are simulated
	for(int j=0; j<N; ++j){
		vector<int> birthdays;
		set<int> bd_set;
		int pair=-1; // Checks status of finding a pair( equal to the day where pair was found )
		bool check = false; // Checks if a pair is found in the particular case
		for(int i=0; i<num; ++i){
			int new_birthday = rand()%366 + 1;
			birthdays.push_back(new_birthday);
			// bd_set.insert(new_birthday);
		}
		cout << "Case " << j+1 << ":" << endl; // Prints the case number
		for(auto it : birthdays)
			cout << it << " ";  // Prints the list of birthdays
		cout << endl;
		for(auto it : birthdays){
			if(bd_set.find(it)==bd_set.end()) // it not in set
				bd_set.insert(it);
			else{
				pair = it; // Stores the day when pair is found
				break;}}
		if(pair!=-1){
			pair_exist++; // Increase the count of cases where pair exist by 1
			check = true;}
		if(check) cout << "Pair found at " << pair << " day." << endl; // This statement executes when a pair is found
		else cout << "No pair found." << endl; // This statement executes when pair is not found
		cout << endl;}
	cout << "Probability of same birthday = " << (float)pair_exist/N << endl; // Prints the probability of same birthday
}
