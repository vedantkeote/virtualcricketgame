#include "game.h"
using namespace std;
Game::Game(){
    playersPerTeam=4;
    maxBalls=6;
    totalPlayers=11;
    players[0]="Virat";
    players[1]="Rohit";
    players[2]="Dhawan";
    players[3]="Pant";
    players[4]="Karthik";
    players[5]="KLRahul";
    players[6]="Jadeja";
    players[7]="Hardick";
    players[8]="Bumrah";
    players[9]="BKumar";
    players[10]="Ishant";
    isFirstInnings=false;
    teamA.name="Team-A";
    teamB.name="Team-B";
};

void Game::welcome(){
    cout << "WHALECOME" << endl;
    cout << endl << endl;
    cout << "instructions" << endl;
    cout << "insert generic instructions here" << endl;
}

void Game::showAllPlayers(){
    cout << endl;
    cout<<"list of players"<<endl;
    cout<<endl;
    for (int i=0;i<totalPlayers;i++){
        cout<<"\t\t["<<i<<"]"<<players[i]<<endl;
    }
}

int Game::takeIntegerInput(){
    int n;
    while(!(cin>>n)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "invalid input! Please try again with a valid input.";
    }
    return n;
}

bool Game::validateSelectedPlayer(int index){
    int n;
    vector<Player> players;
    players = teamA.players;
    n=players.size();
    for (int i=0;i<n;i++){
        if (players[i].index == index){
            return false;
        }
    }
    return true;
}

void Game::selectPlayers(){
    cout<<endl;
    cout<<"create Team A and Team B"<<endl;

    for (int i=0;i<playersPerTeam;i++){
        //team A:
        teamASelection:
            cout<<endl<<"Select player"<<i+1<<" of Team A - ";
            int playerIndexTeamA=takeIntegerInput();
            if (playerIndexTeamA < 0 || playerIndexTeamA >10){
                cout<<endl<<"Please enter valid team player"<<endl;
                goto teamASelection;
            } else if (!validateSelectedPlayer(playerIndexTeamA)) {
                cout<<"player has already been selected, please select another player."<<endl;
                goto teamASelection;
            } else {
                Player teamAPlayer;
                teamAPlayer.index=playerIndexTeamA;
                teamAPlayer.name=players[playerIndexTeamA];
                teamA.players.push_back(teamAPlayer);
            }
        //teamB:
        teamBSelection:
            cout<<endl<<"Select player"<<i+1<<" of Team B - ";
            int playerIndexTeamB=takeIntegerInput();
            if(playerIndexTeamB<0||playerIndexTeamB>10){
                cout<<endl<<"please enter valid team player"<<endl;
                goto teamBSelection;
            } else if (!validateSelectedPlayer(playerIndexTeamA)) {
                cout<<"Player has already been selected, please select another player."<<endl;
                goto teamBSelection;
            }else {
                Player teamBPlayer;
                teamBPlayer.index=playerIndexTeamB;
                teamBPlayer.name=players[playerIndexTeamB];
                teamB.players.push_back(teamBPlayer);
            }
    }
}

void Game::showTeamPlayers(){
    vector<Player> teamAPlayers=teamA.players;
    vector<Player> teamBPlayers=teamB.players;
    cout<<endl<<endl;
    cout<<"----------------------\t\t----------------------"<<endl;
    cout<<"|======= Team-A =====|\t\t|======= Team-B =====|"<<endl;
    cout<<"----------------------\t\t----------------------"<<endl;
    for (int i=0;i<playersPerTeam;i++){
        cout<<"|\t"<<"["<<i<<"]"<<teamAPlayers[i].name<<"|\t|"<<"\t\t"<<"|\t"<<"["<<i<<"]"<<teamBPlayers[i].name<<"\t|"<<endl;
    }
    cout<<"----------------------\t\t----------------------"<<endl;
}

void Game::toss(){
    cout<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"|============== Let's Toss ================="<<endl;
    cout<<"--------------------------------------------"<<endl<<endl;
    cout<<"Tossing the coin..."<<endl<<endl;
    srand(time(NULL));
    int randomValue=rand() %2;
    switch(randomValue){
        case 0:
            cout<<"Team-A won the toss"<<endl<<endl;
            tossChoice(teamA);
            break;
        case 1:
            cout<<"Team-B won the toss"<<endl<<endl;
            tossChoice(teamB);
            break;
    }
}

void Game::tossChoice(Team tossWinnerTeam){
    cout<<"Enter 1 to bat or 2 to bowl"<<endl<<"1.bat"<<endl<<"2.bowl"<<endl;
    int tossInput=takeIntegerInput();
    switch (tossInput){
        case 1:
            cout<<endl<< tossWinnerTeam.name<<" won the toss and elected to bat first"<<endl<<endl;
            if(tossWinnerTeam.name.compare("Team-A")==0){
                battingTeam=&teamA;
                bowlingTeam=&teamB;
            } else {
                battingTeam=&teamB;
                bowlingTeam=&teamA;
            }
            break;
        case 2:
            cout<<endl<<tossWinnerTeam.name<<" wont he toss and elected to bowl first"<<endl<<endl;

            break;
        default:
            cout<<endl<<"Invalid input, please try again"<<endl<<endl;
            tossChoice(tossWinnerTeam);
            break;
    }
}