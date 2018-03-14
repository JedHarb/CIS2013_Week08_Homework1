#include<fstream>
#include<iostream>
using namespace std;

int main() {

	int level = 0;
	char keepAlive = 'y';
	int xGuess = 0;
	int yGuess = 0;
	char boardSpaces[10][10];
	char userGuesses[10][10];
	char i;
	bool hit = false;
	int hitCounter = 0;
	bool gameOver = false;

	ifstream in_a;

	//get the level, close the program if the file is inaccessible
	cout << "What level do you want to play? Type 1, 2 or 3: ";
	cin >> level;
	switch (level){
		case 1:
			in_a.open("1.dat");
			break;
		case 2:
			in_a.open("2.dat");
			break;
		case 3:
			in_a.open("3.dat");
			break;
		default:
			cout << "Sorry, I didn't get that. Defaulting to level 1." << endl;
			in_a.open("1.dat");
	}
	if (in_a.fail()) {
		cout << "Unable to read file, the program will now close." << endl;
		cin >> keepAlive; //keep the program from closing the window until the user inputs something
		exit(1);
	}

	//set our 2D array to match the file
	for (int x = 0; x<10; x++) {
		for (int y = 0; y<10; y++) {
			in_a >> i;
			if (i == 'X') {
				boardSpaces[x][y] = 'X';
			}
			else {
				boardSpaces[x][y] = 'o';
			}
		}
	}
	
	//print a blank board to start
	cout << endl << "      WELCOME TO BATTLEHSHIP";
	cout << endl << "        0 1 2 3 4 5 6 7 8 9";
	cout << endl << "       ____________________" << endl;
	for (int x = 0; x<10; x++) {
		cout << "    " << x << " | ";
		for (int y = 0; y<10; y++) {
				cout << ". ";
		}
		cout << endl;
	}

	//start the game
	while (gameOver == false) {

		cout << "Choose X coordinate: ";
		cin >> xGuess;
		switch (xGuess) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			break;
		default:
			xGuess = 0;
			cout << "I didn't get that. Defaulting to 0." << endl;
		}
		cout << "Choose Y coordinate: ";
		cin >> yGuess;
		switch (yGuess) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			break;
		default:
			yGuess = 0;
			cout << "I didn't get that. Defaulting to 0." << endl;
		}

		cout << endl << "        0 1 2 3 4 5 6 7 8 9";
		cout << endl << "       ____________________" << endl;

		for (int x = 0; x < 10; x++) {
			cout << "    " << x << " | ";
			for (int y = 0; y < 10; y++) {
				if (xGuess == y && yGuess == x) {
					cout << boardSpaces[x][y] << " ";
					
					if (boardSpaces[x][y] == 'X') {
						hit = true;
						if (userGuesses[x][y] != 'y') {
							hitCounter++;
						}
					}
					userGuesses[x][y] = 'y';
				}
				else if (userGuesses[x][y] == 'y') {
					cout << boardSpaces[x][y] << " ";
				}
				else {
					cout << ". ";
				}

			}
			cout << endl;
		}
		if (hit == true) {
			cout << "DIRECT HIT" << endl;
			hit = false;
		}
		else {
			cout << "MISS" << endl;
		}

		if (hitCounter >= 17) {
			gameOver = true;
		}
	}

	cout << "YOU SANK ALL THE BATTLESHIPS! YOU WIN!";
	in_a.close(); //always close the file when you are done reading it, prevent file corruption
	cin >> keepAlive; //keep the program from closing the window until the user inputs something
	return 0;
}
