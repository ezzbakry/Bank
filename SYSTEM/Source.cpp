#include<iostream>
#include<string>
using namespace std;
struct bank {
	string name;
	int accnum;
	char type;
	double amount;
};
void Input(bank x[], int g) {
	int b = 0;
	do {
		cout << "Enter the account no.:";
		cin >> x[g].accnum;
		for (int i = 0; i < g; i++) {
			if (x[g].accnum == x[i].accnum && g != i) {
				b = 1;
				cout << " This number is not available,please try again" << endl;
				system("pause");
				system("cls");
			}
			else {
				b = 0;
			}
		}
		if (b == 0) {
			break;
		}
		else {
			continue;
		}
	} while (true);

	cout << "Enter the name of the account holder:";
	cin >> x[g].name;
	cout << "Enter the type of the account (c/s) :";
	cin >> x[g].type;
	if (x[g].type != 'c' && x[g].type != 's') {
		cout << "Error" << endl;
		system("pause");
		system("cls");
	}
	cout << "Enter the amount:";
	cin >> x[g].amount;
	cout << "Account is created" << endl;
	system("pause");
	system("cls");
}
void Deposit(bank x[], int COUNTER) {
	int p = 1;
	int r;
	cout << "Enter the account no. :" << endl;
	cin >> r;
	
	for (int i = 0; i < COUNTER; i++) {

		if (x[i].accnum == r) {
			p = 2;
			cout << "Account details" << endl;
			cout << " The account no.:";
			cout << x[i].accnum << endl;
			cout << " The name of the account holder:";
			cout << x[i].name << endl;
			cout << " The type of the account:";
			cout << x[i].type << endl;
			cout << " The amount:";
			cout << x[i].amount << endl;

			
			int s;
			cout << "Enter the amount to be deposited : ";
			cin >> s;
			if (s >= 0) {
				x[i].amount = x[i].amount + s;

				cout << "Record updated" << endl;
			}
			else {
				cout << "Not accepted " << endl;
			}

		}
	}
	if (p == 1) {
		cout << " Not exist" << endl;
	}
	system("pause");
	system("cls");

}
void Withdraw(bank x[], int Counter) {
	int q = 1;

	int id;
	cout << "Enter the account no . :";
	cin >> id;

	for (int i = 0; i < Counter; i++) {
	
		if (x[i].accnum == id){
			q = 2;
		
			cout << "Account details" << endl;
			cout << " The account no.:";
			cout << x[i].accnum << endl;
			cout << " The name of the account holder:";
			cout << x[i].name << endl;
			cout << " The type of the account:";
			cout << x[i].type << endl;
			cout << " The amount:";
			cout << x[i].amount << endl;
			int s;
			cout << "Enter the amount to be withdrawed :";
			cin >> s;
			if (s >= 0) {
				if (x[i].amount >= s) {
					x[i].amount = x[i].amount - s;
					cout << "Record updated" << endl;
				}
				else {
					cout << "Error" << endl;
				}
			}
			else {
				cout << "Not accepted" << endl;
			}

		}
		
	}
	if (q == 1) {
		cout << " Not exist" << endl;
	}

	system("pause");
	system("cls");

}
void Balance_enquiry(bank x[], int f) {
	int v = 1;
	int k;
	cout << " enter the account no .:" << endl;
	cin >> k;
	for (int i = 0; i < f; i++) {
		if (x[i].accnum==k) {
			v = 2;
			cout << "Account details" << endl;
			cout << " The account no.:";
			cout << x[i].accnum << endl;
			cout << " The name of the account holder:";
			cout << x[i].name << endl;
			cout << " The type of the account:";
			cout << x[i].type << endl;
			cout << " The amount:";
			cout << x[i].amount << endl;
		}
	}
	
	if (v == 1) {
		cout << "Not exist " << endl;
	}
	system("pause");
	system("cls");
}

void All_account_holder_list(bank x[], int& c) {
	for (int i = 0; i < c; i++) {
		cout << " The account no. :";
		cout << x[i].accnum << endl;
		cout << " The name of the account holder : ";
		cout << x[i].name << endl;
		cout << " The type of the account :";
		cout << x[i].type << endl;
		cout << " The amount: ";
		cout << x[i].amount << endl;
	}
	system("pause");
	system("cls");
}
void Close(bank x[], int& length) {
	cout << " Enter the account no:";
	int n = x->accnum;
	cin >> n;
	for (int i = 0; i < length; i++) {
		if (x[i].accnum == n) {
			for (int j = i; j < length; j++) {
				x[j].accnum = x[j + 1].accnum;
				x[j].name = x[j + 1].name;
				x[j].type = x[j + 1].type;
				x[j].amount = x[j + 1].amount;

			}
			cout << "Account was deleted" << endl;
			length--;
			break;
		}
	}
	system("pause");
	system("cls");
}
void Modify_account(bank x[], int d) {
	int y;
	cout << "Enter the account number" << endl;
	cin >> y;

	for (int i = 0; i < d; i++) {
		if ( x[i].accnum == y) {
			cout << " The account no:";
			cout << x[i].accnum << endl;
			cout << " The name of the account holder:";
			cout << x[i].name << endl;
			cout << " The type of the account:";
			cout << x[i].type << endl;
			cout << " The amount:";
			cout << x[i].amount << endl;
		}


	}
	for (int g = 0; g < d; g++) {
		if ( x[g].accnum == y) {
			cout << "Enter the account no:";
			cin >> x[g].accnum;
			cout << "Enter the name of the account holder:";
			cin >> x[g].name;
			cout << "Enter the type of the account :";
			cin >> x[g].type;
			cout << "Enter the amount:";
			cin >> x[g].amount;
			break;
		}
	}
	system("pause");
	system("cls");
}
int main() {
	bank x[10000];
	int counter = 0;
	do {
		cout << "  Main Menu " << endl;
		cout << endl << "  1-New Account" << endl << endl;
		cout << endl << "  2-Deposit Amount" << endl << endl;
		cout << endl << "  3-Withdraw Amount" << endl << endl;
		cout << endl << "  4-Balance Enquiry" << endl << endl;
		cout << endl << "  5-All account holder list" << endl << endl;
		cout << endl << "  6-Close an account" << endl << endl;
		cout << endl << "  7-Modify  an account" << endl << endl;
		cout << endl << "  8-Exit" << endl << endl;
		int n;
		cout << "Select your option (1-8) ";
		cin >> n;
		system("cls");
		if (n == 1) {
			Input(x, counter);
			counter++;
		}
		else if (n == 2) {
			Deposit(x, counter);
		}
		else if (n == 3) {
			Withdraw(x, counter);
		}
		else if (n == 4) {
			Balance_enquiry(x, counter);
		}
		else if (n == 5) {

			All_account_holder_list(x, counter);

		}
		else if (n == 6) {
			Close(x, counter);
		}
		else if (n == 7) {
			Modify_account(x, counter);

		}
		else if (n == 8) {
			break;
		}

	} while (true);
	return 0;
}
