#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
using namespace std;

struct student {
	string firstname, lastname;
	int student_ID;
	double labs, assignment1, assignment2, assignment3, assignment4, assignment5, termtest, midterm, final;
};

int main() {
	ifstream fin("CSI2372.info", ios::in | ios::binary);
	ofstream fout("CSI2372_final.info", ios::out | ios::binary);
	student strec;
    char temp[100];
    int len = 9;
    fin.read(temp, 100);
    if (!fin) {
        cout << "Error." << endl;
    }

    if (!fin.read(temp, 100)) {
        cout << "Error." << endl;
    }
	fin.read((char*)&len, sizeof(int)); 
	fin.read(temp, len);
	temp[len] = 0;
	strec.firstname = temp;

	fin.read((char*)&len, sizeof(int));
	fin.read(temp, len);
	temp[len] = 0;
	strec.lastname = temp;
	fin.read((char*)&strec.student_ID, sizeof(int));
	fin.read((char*)&strec.labs, sizeof(double));
	fin.read((char*)&strec.assignment1, sizeof(double));
	fin.read((char*)&strec.assignment2, sizeof(double));
	fin.read((char*)&strec.assignment3, sizeof(double));
	fin.read((char*)&strec.assignment4, sizeof(double));
	fin.read((char*)&strec.assignment5, sizeof(double));
	fin.read((char*)&strec.termtest, sizeof(double));
	fin.read((char*)&strec.midterm, sizeof(double));
	fin.read((char*)&strec.final, sizeof(double));
	fout.seekp(10, ios::end);
	fout.seekp(10, ios::cur);

	unsigned long long pos = fout.tellp();

	cout << "Firstname = " << strec.firstname << endl;
	cout << "Lastname = " << strec.lastname << endl;
	cout << "Student ID = " << strec.student_ID << endl;
	cout << "Labs = " << strec.labs << endl;
	cout << "Assignment 1 = " << strec.assignment1 << endl;
	cout << "Assignment 2 = " << strec.assignment2 << endl;
	cout << "Assignment 3 = " << strec.assignment3 << endl;
	cout << "Assignment 4 = " << strec.assignment4 << endl;
	cout << "Assignment 5 = " << strec.assignment5 << endl;
	cout << "Term test = " << strec.termtest << endl;
	cout << "Midterm = " << strec.midterm << endl;
	cout << "Final = " << strec.final << endl;

	fout.close();
	return 0;
}