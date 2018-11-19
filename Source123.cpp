#include <iostream>
#include <iomanip>

using namespace std;

const int Size = 10;

class person {

private:

	char name[Size];
	char surname[Size];
	unsigned int birth_year;

public:

	unsigned int year;
	void enter_person() {

		cout << "Enter persons name" << endl;
		cin >> name;
		cout << "Enter person surname " << endl;
		cin >> surname;
		cout << "Enter persons birthyear " << endl;
		cin >> year;
		set_birth_year(year);
		
		cin.ignore();
	}


	void print_person() const {
		cout << endl;

		cout << "Persons name: " << name << endl;
		cout << "Persons surname: " << surname << endl;
		cout << "Persons birthyear: " << birth_year << endl;
		cout << "Pointer {this}: " << this << endl;
	}

	const char* get_name() {
		return name;
	}

	void set_name(const char* n) {
		strcpy_s(name, n);
	}

	const char* get_surname() {
		return surname;
	}

	void set_surname(const char* sn) {
		strcpy_s(surname, sn);
	}

	unsigned int get_birth_year() {
		return birth_year;
	}

	void set_birth_year(const int num) {

		if (num >= 2019)
			cout << "Its only 2018" << endl;
		else
			birth_year = num;
	}

	unsigned int yo()const {
		
		return 2018 - birth_year;
	}
	

	

};
int main() {

	person a;

	a.enter_person();
	a.print_person();

	a.set_name("Vadet");
	cout <<endl << a.get_name() << endl;

	a.set_surname("Zahar");
	cout << endl << a.get_surname() << endl;

	a.set_birth_year(2008);
	cout << endl << a.get_birth_year() << endl;

	cout << endl << "Years old: " << a.yo() << endl;;

	a.print_person();

	cout << " &a " << &a << endl;
	


	system("pause");
}