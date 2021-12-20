#include <iostream>
#include <thread>
#include <stdbool.h>

int cnt;
bool flag[2];
int turn;

using namespace std;

void Process_1() {

	while (true)
	{
		flag[0] = true;
		while (flag[1] == true)
		{
			if (turn == 1) {
				flag[0] = false;
				while (turn == 1);
				flag[0] = true;
			}
		}
		cnt++;
		// critical section
		turn = 1;
		flag[0] = false;
		// remainder section
	}
}

void Process_2() {

	while (true)
	{
		flag[1] = true;
		while (flag[0] == true)
		{
			if (turn == 0) {
				flag[1] = false;
				while (turn == 0);
				flag[1] = true;
			}
		}
		cnt++;
		// critical section
		turn = 0;
		flag[1] = false;
		// remainder section
	}
}


int main() {

	flag[0] = false;
	flag[1] = false;

	thread P1(Process_1);
	thread P2(Process_2);

	P1.join();
	P2.join();

	cout << " cnt :: " << cnt << endl;

	return 0;
}
