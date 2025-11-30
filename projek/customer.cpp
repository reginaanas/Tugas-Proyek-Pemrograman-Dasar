#include "customer.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<customer> total;
bool emp = false;

customer::customer(string name, string email, string password)
		: _name(name), _email(email), _password(password){}

void customer::print() const {
    string masked(_password.length(), '*');
    cout << "Nama: " << _name << "\nEmail: " << _email << "Password: " << masked << "\n";
}

void customer::newcust(const customer &c) {
    total.push_back(c);
    emp = true;
}

