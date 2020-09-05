#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unistd.h>
#include "team.h"		// "player.h", <string>, <vector>


class Game {

	public:
		Game();
		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];
		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;
		void Welcome();
		void showAllPlayers();
		int takeIntegerInput();
		void selectPlayers();
		bool validatePlayer(int);
		void displaySelectedTeams();
		void toss();
		void tossChoice(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void showGameScorecard();
		void startSecondInnings();
		void summary();
};
