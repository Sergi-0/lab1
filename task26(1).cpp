#include <iostream> // 19 вариант
#include <fstream>
#include <array>
#include <string>
#include <Windows.h>

using namespace std;

class Student {

	public:
		Student();
		double average();
		void write();
		void setFIO(string s);
		void setEST(int n, int k);

	private:
		string FIO;
		array<int, 4> estimations;
}; 

Student::Student() {
	this->FIO = "";
	this->estimations = {0,0,0,0};
};

void Student::setFIO(string s) {
	this->FIO = s;
}

void Student::setEST(int n, int k) {
	this->estimations[n] = k;
}

double Student::average() {
	return (this->estimations[0] + this->estimations[1] + this->estimations[2] + this->estimations[3]) / 4;
}

void Student::write() {
	cout << this->FIO << " ";
	cout << this->estimations[0] << " " << this->estimations[1] << " " << this->estimations[2] << " " << this->estimations[3] << endl;
}

int main()
{
	Student A;
	setlocale(LC_ALL, "Rus");
    ifstream file("stud(for26task).txt");
	string N,l;
	getline(file, N);
	Student* p = new Student[atoi(N.c_str())];
	for (int i = 0; i < atoi(N.c_str()); ++i)
	{
		getline(file, l, '/');
		A.setFIO(l);
		for (int b = 0;b < 4; ++b) { getline(file, l, ' '); A.setEST(b, atoi(l.c_str())); }
		getline(file, l); /////////// после верхней строки с циклом гетлайн остается в файле на той же строке, поэтому нужно это
		p[i] = A;
	}

	int max = p[0].average();
	int nom1; int nom2; int nom3;

	for (int i = 0; i < atoi(N.c_str()); ++i) {
		if (p[i].average() >= max) { max = p[i].average(); nom1 = i; }
	}

	p[nom1].write();
	max = p[0].average();

	for (int i = 0; i < atoi(N.c_str()); ++i) {
		if ((p[i].average() >= max)&&(i != nom1)) { max = p[i].average(); nom2 = i; }
	}

	p[nom2].write();
	max = p[0].average();

	for (int i = 0; i < atoi(N.c_str()); ++i) {
		if ((p[i].average() >= max) && (i != nom1)&&(i != nom2)) { max = p[i].average(); nom3 = i; }
	}

	p[nom3].write();
	file.close();
}
