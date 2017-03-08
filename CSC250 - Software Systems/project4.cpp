//Matt Meglan
//Project 4 Sotware Systems
//11/4/12
//This program converts decimal integers to an arbitary base

#include <iostream>

using namespace std;

int main()
{
int base = 10;
int decint = 1;
int stack [100];

while (true) {
	cout << endl << "Enter the number system base (2--36): ";
	cin >> base;
	if (base < 2 || base > 37) {
		cout << endl << "Please enter correct base!\n"; }
	else {
		break;
		cout << endl; }
}

while (decint != 0) {
        int mod = 0; 
	int div = 1;
	int i = 0;
	char c1 = 'a';
	char c2;
        bool negative = false;

	cout << endl << "Enter a decimal integer: ";
	cin >> decint;
	if (decint < 0){
		negative = true;	
		div = decint * -1;
	}
	else {
		div = decint;
	}

	while (div != 0) {
		mod = div % base;
        	stack [i] = mod; 
		i++;
		div = div / base;
	}

	if (negative){
		cout << "The base-" << base << " equivalent is -";}
	else{
		cout << "The base-" << base << " equivalent is ";}
	
	i--;
	while (i >= 0){
		int x = stack [i];
		if (x > 9) {
			c2 = x - 10 + c1;
			cout << c2;
			i--;		
		}
		else {
			cout << x; 
		i--;		
		}		 
	}
	
	
	
}

cout << endl << "Buh bye now!\n\n";
return 0;
}
