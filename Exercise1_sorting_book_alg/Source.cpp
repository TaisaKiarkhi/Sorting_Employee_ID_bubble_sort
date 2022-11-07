#include <iostream>
#include <vector>
using namespace std;

class EmployeeInfo {

public:
	int EmployeeID;
	string FirstName;
	string LastName;
	string email;
	string address;
	int PhoneNumber;
public:
	EmployeeInfo(int a, string name = "No name", string lastname = "No name", 
		         string email ="No email", string addr = "No address", int phone = 0) {
		EmployeeID = a;
		FirstName = name;
		LastName = lastname;
		this->email = email;
		address = addr;
		PhoneNumber = phone;



	}
};

class EmployeeList {
public:

	vector<EmployeeInfo>emp_list;
	void BubbleSort();

	template <typename T>
	bool operator > (const T& a) {
		if (emp_list > a.emp_list)
			return true;
		else
			return false;
	}



	void swap_func(int& a, int& b);
	void print_sorted_list();

};


int main() {
	EmployeeInfo a(12, "Alex", "Malex", "adabab@gmail.com", "Somewhere there", 46464646);
	EmployeeInfo b(5, "Onion", "Carrot", "carror@gmail.com", "Here");
	EmployeeInfo c(2, "Martine", "Anderson", "martine@gmail.com", "Martine does not have a home", 4894990);
	EmployeeInfo d(87, "O", "A", "a@gmail.com", "Heidmannsgate 32", 465534646);
	EmployeeInfo e(1, "Number one", "two", "12@gmail.com", "Street", 9800202);

	EmployeeList e_list;
	e_list.emp_list.push_back(a);
	e_list.emp_list.push_back(b);
	e_list.emp_list.push_back(c);
	e_list.emp_list.push_back(d);
	e_list.emp_list.push_back(e);

	e_list.BubbleSort();
	e_list.print_sorted_list();


	return 0;
}

void EmployeeList::BubbleSort()
{
	for (int i = 0; i < emp_list.size() - 1; i++) {
		for (int j = 0; j < emp_list.size() - 1 - i; j++) {
			if (emp_list[j].EmployeeID > emp_list[j + 1].EmployeeID) {
				swap_func(emp_list[j + 1].EmployeeID, emp_list[j].EmployeeID);
			}
		}
	}
}

void EmployeeList::swap_func(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;

}

void EmployeeList::print_sorted_list()
{
	cout << "Printing Employee IDs" << endl;
	for (int i = 0; i < emp_list.size() - 1; i++) {
		cout<<" Employee "<<i<<": " << emp_list.at(i).EmployeeID << " " << endl;
	}

}
