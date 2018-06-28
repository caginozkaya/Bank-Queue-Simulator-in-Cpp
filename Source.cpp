#include <iostream>
#include <queue>
#include <ctime>
#include <vector>
#include <string>
#include "d_random.h"
using namespace std;

inline void mySleep(clock_t sec) 
{
	clock_t start_time = clock();
	clock_t end_time = sec * 1000 + start_time;
		while (clock() != end_time);
}

void writeQueue(queue<string> qu, int number) {
	
	cout << "Counter-" << number << ": " ;
	queue<string> temp = qu;
	while (!temp.empty()) {
		cout << temp.front() << " ";
		temp.pop();
	}

	cout << endl;
		

}
int getOrder(queue<string> qu) {
	int result;
	string temp = qu.back();
	temp = temp.substr(3);
	result = stoi(temp)+1;
	return result;
}


int main() {
	randomNumber rnd;
	int n, i, tran, counter = 0, dura = 0;
	string client;
	int order;
	
	vector<queue<string>> qV;
	cout << "Enter the number of counters between 1 and 5:" << endl;
	cin >> n;
	system("cls");
	for (i = 0; i < n; i++)
		qV.push_back(queue<string>());

	while (true) {
		tran = rnd.random(2);// 0 -> append, 1 -> serve or do nothing
		counter = rnd.random(n);

		if (tran == 0) {

			if (qV[counter].empty())
				order = 1;
			else
				order = getOrder(qV[counter]);

			client = "C" + to_string(counter+1) + "-"+ to_string(order);
			qV[counter].push(client);
			cout << "Transaction : Append " << client <<endl;
			}
		else if (tran == 1) {
		
			if (!qV[counter].empty()) {

				cout << "Transaction : Serve " << qV[counter].front() << endl;
				qV[counter].pop();

			}
			else {
				cout << "Counter number " << counter + 1 << " is empty." << endl;
			}

		}
	

		
		for (i = 0; i < n; i++)
			if (!qV[i].empty())
				writeQueue(qV[i], i + 1);
			else
				cout << endl;


		cout << "Time: " << dura << " sec" << endl;
		mySleep(1);
		dura = dura + 1;
		system("cls");
		}

	
	system("pause");
	return 0;


}


