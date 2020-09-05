//============================================================================
// Name        : virtual-cricket-game.cpp
// Author      : Bhawana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "game.h"
using namespace std;

int main() {
	Game Cricket;
	Cricket.Welcome();

	cout << endl << endl << "Press enter to continue" << endl;
	cin.get();

	Cricket.showAllPlayers();

	cout << endl << endl << "Press enter to continue" << endl;
	cin.get();

	Cricket.selectPlayers();
	Cricket.displaySelectedTeams();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl << endl << "Press Enter to TOSS" << endl;
	cin.get();

	Cricket.toss();

	Cricket.startFirstInnings();
	Cricket.startSecondInnings();

	Cricket.summary();

	return 0;
}
