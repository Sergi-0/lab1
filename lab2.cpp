#include <iostream>

using namespace std;

class Vector {
	friend void operator <<(ostream& m, Vector& f) {
		for (int i = 0; i < f.n; ++i) m << f.vec[i] << " ";
	}

	friend void operator >>(istream& m, Vector& f) {
		for (int i = 0; i < f.n; ++i) m >> f.vec[i];
	}

	friend Vector& operator ^(Vector& a, Vector& b) {
		if (a.n == b.n) {
			bool* mas = new bool[b.n];
			Vector* c = new Vector(mas, b.n);
			for (int i = 0; i < b.n; ++i) c->vec[i] = bool(a.vec[i] * b.vec[i]);
			return *c;
		}
		else
			cout << "Error";
	}

public:
	Vector(); // конструктор
	Vector(bool* mas, int k); // конструктор создающий вектор из заданного массива
	Vector(const Vector& a); // конструктор копирования
	Vector(Vector&& V); // конструктор перемещения, меняет местами 2 вектора
	~Vector(); // деструктор
	bool operator[](int a); // оператор получения элемента вектора по заданному номеру
	Vector& operator=(const Vector& b); // оператор копирования одного вектора в другой
	//Vector& operator*(int k); // оператор умножение вектора на число

private:
	bool* vec = nullptr;
	int n = 0;
};

Vector::Vector() {
	vec = new bool [0];
	n = 0;
}

Vector::Vector(bool* mas, int k) {
	this->vec = new bool[k];
	for (int i = 0; i < k; ++i)  this->vec[i] = mas[i]; 
	this->n = k;
}

Vector::Vector(const Vector& a) {
	this->vec = new bool[a.n];
	this->n = a.n;
	for (int i = 0; i < a.n; ++i)  this->vec[i] = a.vec[i];
}

Vector::Vector(Vector&& a) {                 // правая ссылка для отличия от предыдущего конструктора
	swap(vec, a.vec);
	swap(n, a.n);
}

Vector::~Vector() {
	delete vec;
}

bool Vector::operator[](int a) {
	if (a < n) { return vec[a]; }
	else cout << "Error";
}

Vector& Vector::operator=(const Vector& b) {
	n = b.n;
	delete vec;
	vec = new bool[b.n];
	for (int i = 0; i < b.n; ++i) vec[i] = b.vec[i];
	return *this;
}

/*Vector& Vector::operator*(int k) {
	for (int i = 0; i < n; ++i) vec[i] = vec[i] * k;
	return *this; 
}*/

int main()
{
	bool m[5] = {1,0,0,1,1};
	bool j[5] = {1,1,1,1,0};
	Vector vec1(m, 5);
	Vector vec3(j, 5);
	//Vector vec2;
	//vec2 = vec1;
	//cout<< vec1[4] << endl;
	//cout << vec2[4] << endl;
	//cin >> vec2;
	cout<<(vec3 ^ vec1);
}

/*	ОТЧЕТ: 1) Цель работы : научится применять перегрузку операторов класса на практике.
	2) УСЛОВИЕ ЗАДАЧИ: Дан класс(например, с именем Vector), задающий вектор размерности n.Поля класса : указатель на массив, задающий вектор(тип элемента double), массив должен создаваться динамически; число элементов(размерность) вектора(тип int).Класс включает : конструктор без параметров, задающий пустой вектор(число элементов равно 0); конструктор, создающий объект вектор на основе обычного одномерного массива размерности n; конструктор копирования, конструктор перемещения, деструктор.
	Необходимо перегрузить операции и продемонстрировать их работу.Перегрузить операцию[](обращение к элементу вектора по индексу), операцию = (копирование вектора или создание копии вектора), операцию* (умножение числа на вектора), на выходе вектор такой же размерности, каждый элемент которого равен произведению соответствующего элемента исходного вектора на число.
	3) */
