#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void loginSystem(string username, string password);
bool checkDigit(string password);
bool checkCharacter(string password);

int main() {
	string username;
	string password;
	loginSystem(username, password);
}

void loginSystem(string username, string password) {
	cout << "Enter a username that is 20 characters or less: \n";
	getline(cin, username);

	while (username.empty() || username.length() > 20) {
		cout << "You did not enter the username correctly, please input a username that is 20 or less characters: \n";
		getline(cin, username);

	}
	
	cout << "Enter a password that has at least one numerical digit and one special character: \n";
	getline(cin, password);
	while (password.empty() || !checkDigit(password) || !checkCharacter(password)) {
		if (password.empty()) {
			cout << "You did not input a password, please do so: \n";
			

		}

		else if (!checkDigit(password)) {
			cout << "Your password does not contain a digit, please input a correct password: \n";
		
		}

		else if (!checkCharacter(password)) {
			cout << "Your password does not contain a special character, please add a special character: \n";
		
		}
		getline(cin, password);

	}
	cout << "Username: " << username << '\n';
	cout << "Password: " << password << '\n';
}
bool checkDigit(string password) {
	for (int i = 0; i < password.length(); i++) {
		if (isdigit(password[i])) { // if password is a digit
			return true; 
		}
	}

	return false; 
}

bool checkCharacter(string password) {
	for (int i = 0; i < password.length(); i++) {
		if (!isalnum(password[i])) { // if password is not a letter or number
			return true; 
		}
	}

	return false; 

}