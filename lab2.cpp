#include <iostream>

using namespace std;

class Vector {
	
public:
	Vector(); // конструктор
	Vector(double* mas, int k); // конструктор создающий вектор из заданного массива
	Vector(const Vector& a); // конструктор копирования
	Vector(Vector&& V); // конструктор перемещения, меняет местами 2 вектора
	~Vector(); // деструктор
	double operator[](int a); // оператор получения элемента вектора по заданному номеру
	Vector& operator=(const Vector& b); // оператор копирования одного вектора в другой
	Vector& operator*(int k); // оператор умножение вектора на число

private:
	double* vec = nullptr;
	int n = 0;
};

Vector::Vector() {
	vec = new double [0];
	n = 0;
}

Vector::Vector(double* mas, int k) {
	this->vec = new double[k];
	for (int i = 0; i < k; ++i)  this->vec[i] = mas[i]; 
	this->n = k;
}

Vector::Vector(const Vector& a) {
	this->vec = new double[a.n];
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

double Vector::operator[](int a) {
	if (a < n) { return vec[a]; }
	else cout << "Error";
}

Vector& Vector::operator=(const Vector& b) {
	n = b.n;
	delete vec;
	vec = new double[b.n];
	for (int i = 0; i < b.n; ++i) vec[i] = b.vec[i];
	return *this;
}

Vector& Vector::operator*(int k) {
	for (int i = 0; i < n; ++i) vec[i] = vec[i] * k;
	return *this;
}

int main()
{
	double m[5] = { 1,2,3,4,5 };
	Vector vec1(m, 5);
	Vector vec2;
	vec2 = vec1;
	cout<< vec2[4] << endl;
	vec2 * 3;
	cout << vec2[4];
}

/*	ОТЧЕТ: 1) Цель работы : научится применять перегрузку операторов класса на практике.
	2) УСЛОВИЕ ЗАДАЧИ: Дан класс(например, с именем Vector), задающий вектор размерности n.Поля класса : указатель на массив, задающий вектор(тип элемента double), массив должен создаваться динамически; число элементов(размерность) вектора(тип int).Класс включает : конструктор без параметров, задающий пустой вектор(число элементов равно 0); конструктор, создающий объект вектор на основе обычного одномерного массива размерности n; конструктор копирования, конструктор перемещения, деструктор.
	Необходимо перегрузить операции и продемонстрировать их работу.Перегрузить операцию[](обращение к элементу вектора по индексу), операцию = (копирование вектора или создание копии вектора), операцию* (умножение числа на вектора), на выходе вектор такой же размерности, каждый элемент которого равен произведению соответствующего элемента исходного вектора на число.
	3) */