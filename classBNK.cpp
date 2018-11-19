#include <iostream>
#include <iomanip>

using namespace std;

enum currency { UAH = 1, USD, EUR };

class account {

private:

	unsigned int acc_num;
	unsigned int cash;
	currency n;

public:

	void create_acc() {
		cout << "Enter credit card: ";
		cin >> acc_num;
		cout << "Enter cash located on card: ";
		cin >> cash;
		cout << "Enter currency: [1]uah [2]usd [3]eur ";
		int n_;
		cin >> n_;
		
		switch (n_) {
		case 1:
			n = UAH;
			break;
		case 2:
			n = USD;
			break;
		case 3:
			n = EUR;
			break;
		default: 
			n = UAH;
			break;
		}
	}



	currency get_currency() {
		return n;
	}


	int transfer_sum = 0;

	void set_transfer_value(int &cash_to) {
		cash_to += transfer_sum;
	}

	void edit_acc() {
		unsigned short menu = 0;
		int take;
		int input;
		start:
		cout << "What do you want to do: [1] - open account | [2] - take cash | [3] - input cash | [4] - transfer | [5] - exit";
		cin >> menu;
		switch (menu) {
		case 1:
			create_acc();
			get_status();
			cout << "Do you want to continue? [1] - yes [other] - no " << endl;
			int cnt;
			cin >> cnt;
			
			if (cnt == 1)
				goto start;
				
			break;
		case 2:
			retake:
			cout << "Enter cash to take: ";
			cin >> take;
			if (cash < take) {
				cout << "You have not enough money " << endl;
				get_status();
				goto retake;
			}
			else {
				cash -= take;
				get_status();
			}
			break;
		case 3:
			cout << "How many cash do you want to input: " << endl;
			cin >> input;
			cash += input;
			get_status();
			goto start;

		case 4: 
			cout << "How many do you want to transfer: ";
			cin >> transfer_sum;
			if (transfer_sum >= cash)
				cash -= transfer_sum;
			break;

		case 5: 
			break;
		}

		
	}
	int get_transfer_sum(){
			return transfer_sum;
		}
	void get_status()const {
		cout << endl << "Bank account: " << acc_num << endl;
		cout << "Cash: " << cash << endl;
		cout << "Currency: ";
		switch (n) {
		case 1: 
			cout << "UAH" << endl;
			break;
		case 2:
			cout << "USD" << endl;
			break;
		case 3: 
			cout << "EUR" << endl;
			break;
		default: 
			cout << "UAH" << endl;
			break;
		}
		
	}
	

};

int main() {

	account a;
	account b;

	a.edit_acc();
	b.edit_acc();
	int buffer = a.get_transfer_sum();
	b.set_transfer_value(buffer);
	b.get_status();
	

	

	system("pause");
}