#include "game.h"
using namespace std;

int main() {
	Game game;
	game.welcome();
	cout<<"\npress enter to continue"<<endl;
	getchar();
	game.showAllPlayers();
	cout<<"\npress enter to continue"<<endl;
	getchar();
	game.selectPlayers();
	game.showTeamPlayers();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout<<"\nPress enter to Toss...";
	getchar();
	game.toss();
	game.startFirstInnings();
	return 0;
}
