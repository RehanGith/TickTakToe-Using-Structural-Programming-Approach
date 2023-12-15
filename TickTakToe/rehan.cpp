#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void display(char* arr) {
	cout << "\t" << arr[7] << "\t|\t" << arr[8] << "\t|\t" << arr[9] << endl;
	cout << "-----------------------------------------------\n";
	cout << "\t" << arr[4] << "\t|\t" << arr[5] << "\t|\t" << arr[6] << endl;
	cout << "-----------------------------------------------\n";
	cout << "\t" << arr[1] << "\t|\t" << arr[2] << "\t|\t" << arr[3] << endl;
}
char choose_sign() {
	char signA;
	cout << "PlayerA what sign you wants to choose[X or O]: ";
	cin >> signA;
	return toupper(signA);
}


bool game_logic(char arr[], char signA, char signB) {
	if (arr[1] == arr[2] && arr[1] == arr[3]) {
		if (arr[1] == signA) {
			cout << "PlayerA wins." << endl;
			return true;
		}
		else if (arr[1] == signB) {
			cout << "PlayerB wins." << endl;
			return true;
		}
	}
	if (arr[4] == arr[5] && arr[4] == arr[6]) {
		if (arr[4] == signA) {
			cout << "PlayerA wins." << endl;
			return true;
		}
		else if (arr[4] == signB) {
			cout << "PlayerB wins." << endl;
			return true;
		}
	}
	
	if (arr[7] == arr[8] && arr[7] == arr[9]) {
		if (arr[7] == signA) {
			cout << "PlayerA wins." << endl;
			return true;
		}
		else if (arr[7] == signB) {
			cout << "PlayerB wins." << endl;
			return true;
		}
	}
	
	if (arr[1] == arr[4] && arr[1] == arr[7]) {
		if (arr[4] == signA) {
			cout << "PlayerA wins." << endl;
			return true;
		}
		else if (arr[4] == signB) {
			cout << "PlayerB wins." << endl;
			return true;
		}
	}
  	
	if (arr[2] == arr[5] && arr[2] == arr[8]) {
		if (arr[2] == signA) {
			cout << "PlayerA wins." << endl;
			return true;
		}
		else if (arr[2] == signB) {
			cout << "PlayerB wins." << endl;
			return true;
		}
	}
	
	if (arr[3] == arr[6] && arr[3] == arr[9]) {
		if (arr[3] == signA) {
			cout << "PlayerA wins." << endl;
			return true;
		}
		else if (arr[3] == signB) {
			cout << "PlayerB wins." << endl;
			return true;
		}
	}
	
	if (arr[1] == arr[5] && arr[1] == arr[9]) {
		if (arr[1] == signA) {
			cout << "PlayerA wins." << endl;
			return true;
		}
		else if (arr[1] == signB) {
			cout << "PlayerB wins." << endl;
			return true;
		}
	}
	
	if (arr[3] == arr[5] && arr[3] == arr[7]) {
		if (arr[3] == signA) {
			cout << "PlayerA wins." << endl;
			return true;
		}
		else if (arr[3] == signB) {
			cout << "PlayerB wins." << endl;
			return true;
		}
	}
		int loop{};
		for (int i = 1; i < 10; i++) {
			if (arr[i] == ' ') {
				loop += 1;
				return false;
			}
		}
		if (!loop) {
			cout << "Game draw." << endl;
			return true;
		}
	return false;
}
void choose_option(char arr[], vector<int>* vec, char signA, char signB) {
	int optionA, optionB;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	system("cls");
	display(arr);
	while (true) {
		int jugeA{};
		cout << "PlayerA Where you wants to Place: " << signA << " :\t";
		cin >> optionA;
		for (auto& choice : *vec) {
			if (choice == optionA) {
				jugeA += 1;
				break;
			}
		}
		if (jugeA) {
			cout << "This Box is already fill. Please provide another box.\n";
			continue;
		}
		else {
			arr[optionA] = signA;
			vec->push_back(optionA);
			break;
		}
	}
	if (game_logic(arr, signA, signB)) {
		return;
	}
	system("cls");
	display(arr);
	while (true) {
		int  jugeB{};
		cout << "PlayerB Where you wants to Place: " << signB << " :\t";
		cin >> optionB;
		for (auto& choice : *vec) {
			if (choice == optionB) {
				jugeB += 1;
				break;
			}
		}
		if (jugeB) {
			cout << "This Box is already fill. Please provide another box.\n";
			continue;
		}
		else {
			arr[optionB] = signB;
			vec->push_back(optionB);
			break;
		}
	}
	system("cls");
	display(arr);

}

int main() {
	char myarr[] { ' ',' ',' ' ,' ',' ',' ',' ',' ',' ',' ' };
	vector<int> myvec;
	char signA, signB;
	bool alpha = false;
	signA = choose_sign();
	if (signA == 'X') {
		signB = 'O';
	}
	else {
		signB = 'X';
	}
	while (true) {
		choose_option(myarr, &myvec, signA,signB);
		alpha = game_logic(&myarr[0], signA, signB);
		if (alpha) {
			system("cls");
			display(myarr);
			break;
		}
	}
	return 0;
	
}