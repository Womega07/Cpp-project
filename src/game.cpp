#include"game.h"
using namespace std;

Game::Game() {

	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Rohit";
	players[1] = "Dhawan";
	players[2] = "Virat";
	players[3] = "KLRahul";
	players[4] = "Pant";
	players[5] = "Karthik";
	players[6] = "Dhoni";
	players[7] = "Jadeja";
	players[8] = "Hardik";
	players[9] = "Bumrah";
	players[10] = "BKumar";

	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";


}

void Game :: Welcome(){
	cout << "---------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "        ****    WELCOME TO VIRTUAL CRICKET GAME    ****        " << endl << endl;
	cout << "                            CRIC-IN                            " << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------" << endl << endl << endl;

	usleep(2000000);

	cout << "***************************************************************" << endl << endl;
	cout << "|                        Instructions                         |" << endl;
	cout << "|                                                             |" << endl;
	cout << "| 1. Create 2 teams (Team-A and Team-B with 4 players each)   |" << endl;
	cout << "|    from a given pool of 11 players.                         |" << endl;
	cout << "| 2. Lead the toss and decide the choice of play.             |" << endl;
	cout << "| 3. Each innings will be of 6 balls.                         |" << endl;
	cout << "|                                                             |" << endl<<endl;
	cout << "***************************************************************" << endl;

}

void Game :: showAllPlayers(){
	cout << "---------------------------------------------------------------" << endl;
	cout << "====================   Pool of Players    =====================" << endl;
	cout << "---------------------------------------------------------------" << endl << endl;

	for(int i=0; i<11; i++)
	{
		cout << "            " << "[" << i << "]"
				<< players[i] << "            " << endl;
	}
}

int Game :: takeIntegerInput(){
	int n;

	while (!(cin >> n)) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input! Please try again with valid input: ";
	}

	return n;
}

void Game::selectPlayers() {

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|           Create Team-A and Team-B           |" << endl;
	cout << "------------------------------------------------" << endl;

	for (int i = 0; i < playersPerTeam; i++)
	{
		// Add player to team A
		teamASelection:
		cout << endl << "Select player " << i + 1 << " of Team A - ";
		int playerIndexTeamA = takeIntegerInput();

		if (playerIndexTeamA < 0 || playerIndexTeamA > 10) {
			cout << endl << "Please select from the given players" << endl;
			goto teamASelection;
		} else if (!validatePlayer(playerIndexTeamA)) {
			cout << endl << "Player has been already selected. Please select other player." << endl;
			goto teamASelection;
		} else {
			Player teamAPlayer;
			teamAPlayer.id = playerIndexTeamA;
			teamAPlayer.name = players[playerIndexTeamA];
			teamA.players.push_back(teamAPlayer);
		}

		// Add player to team B
		teamBSelection:
		cout << endl << "Select player " << i + 1 << " of Team B - ";
		int playerIndexTeamB = takeIntegerInput();

		if (playerIndexTeamB < 0 || playerIndexTeamB > 10) {
			cout << endl << "Please select from the given players" << endl;
			goto teamBSelection;
		} else if (!validatePlayer(playerIndexTeamB)) {
			cout << endl << "Player has been already selected. Please select other player." << endl;
			goto teamBSelection;
		} else {
			Player teamBPlayer;
			teamBPlayer.id = playerIndexTeamB;
			teamBPlayer.name = players[playerIndexTeamB];
			teamB.players.push_back(teamBPlayer);
		}
	}
}

bool Game :: validatePlayer(int index){

	int n;
	vector<Player> players;

	players = teamA.players;
	n = players.size();
	for(int i=0; i<n; i++){
		if(players[i].id == index){
			return false;
		}
	}

	players = teamB.players;
	n = players.size();
	for(int i=0; i<n; i++){
		if(players[i].id == index){
			return false;
		}
	}

	return true;
}

void Game :: displaySelectedTeams(){

	cout << endl << endl << "---------------------------" << "\t\t---------------------------" << endl;
	cout << "|=====    Team- A    =====|" << "\t\t|=====    Team- B    =====|" << endl;
	cout << "---------------------------" << "\t\t---------------------------" << endl;

	vector<Player> players1, players2 ;

	players1 = teamA.players ;
	players2 = teamB.players ;

	for(int j=0; j<4; j++){
		cout << "|" << "\t[" << j << "] " << players1[j].name << "\t  |" << "\t\t|"
				<< "\t[" << j << "] " << players2[j].name << "\t  |" << endl ;
	}

}

void Game :: toss() {

	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << "|========== Let's Toss  ==========|" << endl;
	cout << "-----------------------------------" << endl << endl;

	cout << "Tossing the coin..." << endl << endl;
	usleep(2000000);

	srand(time(NULL));
	int randomValue = rand() % 2;

    switch (randomValue) {
		case 0:
			cout << "Team-A won the toss" << endl << endl;
			tossChoice(teamA);
			break;
		case 1:
			cout << "Team-B won the toss" << endl << endl;
			tossChoice(teamB);
			break;
    }
}


void Game :: tossChoice(Team tossWinnerTeam) {

	usleep(1000000);
	cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" << endl
        	 << "2. Bowl " << endl;

	int tossInput = takeIntegerInput();

	switch (tossInput) {
		case 1:
			cout << endl << tossWinnerTeam.name << " Won the toss and decided to bat first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	 // if Team-A is the toss winner
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}

			break;
		case 2:
			cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	// if Team-A is the toss winner
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}

			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
			tossChoice(tossWinnerTeam);
			break;
   	}
}

void Game :: startFirstInnings() {

	cout << "\t ||| FIRST INNINGS STARTS ||| " << endl << endl;

	isFirstInnings = true;

	initializePlayers();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	playInnings();

}

void Game :: initializePlayers() {

	// Choose batsman and bowler: Initialize *batsman and *bowler
	if(isFirstInnings){                          //for 1st innings
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << endl << "From " << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << "And from " << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;

	} else{										// for 2nd innings
		Team temporary = *battingTeam;
		*battingTeam = *bowlingTeam;
		*bowlingTeam = temporary;
		batsman = &battingTeam->players[0];
		bowler = &bowlingTeam->players[0];

		cout << endl << "From " << battingTeam->name << " - " << batsman->name << " is batting " << endl;
		cout << "And from " << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;

	}
}

void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to bowl...";
		cin.get();
		cout << "Bowling..." << endl;

		bat();
		if (!validateInningsScore()) {
			break;
		}

	}
}

void Game :: bat() {

	int runsScored = rand() % 7;

	// Update batting team and batsman score
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	// Update bowling team and bowler score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

    if (runsScored != 0) {	// if runsScored = 1, 2, 3, 4, 5, or 6
    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
    	showGameScorecard();

    } else { 	// else runScored = 0 and the batsman is ‘OUT’
    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

    	battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
    	bowler->wicketsTaken = bowler->wicketsTaken + 1;
    	showGameScorecard();

    	int nextPlayerIndex = battingTeam->wicketsLost;
    	batsman = &battingTeam->players[nextPlayerIndex];
    }
}

bool Game :: validateInningsScore() {

	if (isFirstInnings) {

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

			cout << endl << endl << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
					<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}

	} else {	// Else 2nd innings

		if (bowlingTeam->totalRunsScored < battingTeam->totalRunsScored && battingTeam->wicketsLost < playersPerTeam && bowlingTeam->totalBallsBowled <= maxBalls) {
			cout << endl << endl << battingTeam->name << " WON THE MATCH" << endl;
			cout << endl << "\t\t ||| MATCH ENDS |||" << endl;
			return false;
		} else if(bowlingTeam->totalRunsScored > battingTeam->totalRunsScored){
			if (battingTeam->wicketsLost >= playersPerTeam || bowlingTeam->totalBallsBowled >= maxBalls) {
				cout << endl << endl << bowlingTeam->name << " WON THE MATCH" << endl;
				cout << endl << "\t\t ||| MATCH ENDS |||" << endl;
				return false; }
		}
	}

	return true;
}

void Game :: showGameScorecard(){

	cout << endl << "-------------------------------------------------------------------------------------" << endl;
	cout << "\t" << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost
			<< " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name << " "
			<< batsman->runsScored << " (" << batsman->ballsPlayed << ")"<< "\t\t" << bowler->name << " "
			<< bowler->ballsBowled <<  "-" << bowler->runsGiven << "-" << bowler->wicketsTaken << endl;
	cout << "-------------------------------------------------------------------------------------" << endl << endl;
}

void Game :: startSecondInnings(){

	cout << "\t ||| SECOND INNINGS STARTS ||| " << endl << endl;

	isFirstInnings = false;

	initializePlayers();
	cout << "Enter for continue" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	playInnings();

}

void Game :: summary(){
	vector<Player> players1, players2 ;
	players1 = teamA.players ;
	players2 = teamB.players ;


	cout << endl << teamA.name  << " " << teamA.totalRunsScored << "-(" << teamB.totalBallsBowled << ")" << endl;
	cout << "==================================================================" << endl;
	cout << "| PLAYER" << "\t\t\t" << "BATTING" << "\t\t\t"  << "BOWLING  |" << endl;
	for (int i=0; i<4; i++){
		cout << "|----------------------------------------------------------------|" << endl;
		cout << "| [" << i << "] " << players1[i].name << "\t\t\t" << players1[i].runsScored << "("
				<< players1[i].ballsPlayed << ")" << "\t\t\t" << players1[i].ballsBowled << " - "
				<< players1[i].runsGiven << " - " << players1[i].wicketsTaken << "|" << endl;
	}
	cout << "==================================================================" << endl << endl;


	cout << endl << teamB.name  << " " << teamB.totalRunsScored << "-(" << teamA.totalBallsBowled << ")" << endl;
	cout << "==================================================================" << endl;
	cout << "| PLAYER" << "\t\t\t" << "BATTING" << "\t\t\t"  << "BOWLING  |" << endl;
	for (int i=0; i<4; i++){
		cout << "|----------------------------------------------------------------|" << endl;
		cout << "| [" << i << "] " << players2[i].name << "\t\t\t" << players2[i].runsScored << "("
				<< players2[i].ballsPlayed << ")" << "\t\t\t" << players2[i].ballsBowled << " - "
				<< players2[i].runsGiven << " - " << players2[i].wicketsTaken << "|" << endl;
	}
	cout << "==================================================================" << endl;

}
