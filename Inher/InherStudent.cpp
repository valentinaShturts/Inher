#include<iostream>
#include<Windows.h>
using namespace std;

class Person 
{
	char* name;
	int age;
public:
	Person() = default;
	Person(const char* Name, int Age)
	{
		cout << "Construct Person\n";
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
		age = Age;
	}

	void Print() const
	{
		cout << "Output Person\n";
		cout << "Name: " << name << endl
			<< "Age: " << age << endl;
	}

	void Input()
	{
		char buff[20];
		cout << "Name: ";
		cin.getline(buff, 20);
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);

		cout << "Age: ";
		cin >> age;
	}

	~Person()
	{
		if (name != nullptr)
		{
			delete[] name;
		}
		cout << "Destruct Person\n";
		Sleep(1000);
	}
};

class Student : public Person
{
	char* Univer;
public: 
	Student() = default;
	Student(const char* n, int a, const char* u) : Person(n, a)
	{
		cout << "Constructor Student\n";
		Univer = new char[strlen(u) + 1];
		strcpy_s(Univer, strlen(u) + 1, u);
	}
	~Student()
	{
		delete[]Univer;
		cout << "Destruct Student\n";
		Sleep(1000);
	}
	void Print()
	{
		cout << "Output Student\n";
		Person::Print();
		cout << "University: " << Univer << endl;
	}
	void Input(const char* u)
	{
		delete[]Univer;
		Univer = new char[strlen(u) + 1];
		strcpy_s(Univer, strlen(u) + 1, u);
		Person::Input();
	}
};

class Doctor : public Person
{
	char* speciality;
	int experience;
public:
	Doctor() = default;
	Doctor(const char* n, int a, const char* s, int e) : Person(n, a)
	{
		cout << "Constructor Doctor\n";
		speciality = new char[strlen(s) + 1];
		strcpy_s(speciality, strlen(s) + 1, s);

		experience = e;
	}
	~Doctor()
	{
		delete[]speciality;
		cout << "Destruct Doctor\n";
		Sleep(1000);
	}
	void Print()
	{
		cout << "Output Doctor\n";
		Person::Print();
		cout << "Speciality: " << speciality << endl;
		cout << "Experience: " << experience << endl;
	}
	void Input(const char* s, int e)
	{
		delete[]speciality;
		speciality = new char[strlen(s) + 1];
		strcpy_s(speciality, strlen(s) + 1, s);

		experience = e;
		Person::Input();
	}
};


class Driver : public Person
{
	char* car_number;
	char* serial_number;
public:
	Driver() = default;
	Driver(const char* n, int a, const char* c, const char* s) : Person(n, a)
	{
		cout << "Constructor Driver\n";
		car_number = new char[strlen(c) + 1];
		strcpy_s(car_number, strlen(c) + 1, c);

		serial_number = new char[strlen(s) + 1];
		strcpy_s(serial_number, strlen(s) + 1, s);
	}
	~Driver()
	{
		delete[]car_number;
		delete[]serial_number;
		cout << "Destruct Driver\n";
		Sleep(1000);
	}
	void Print()
	{
		cout << "Output Driver\n";
		Person::Print();
		cout << "Car number: " << car_number << endl;
		cout << "Serial number: " << serial_number << endl;
	}
	void Input(const char* c, const char* s)
	{
		delete[]car_number;
		delete[]serial_number;

		car_number = new char[strlen(c) + 1];
		strcpy_s(car_number, strlen(c) + 1, c);

		serial_number = new char[strlen(s) + 1];
		strcpy_s(serial_number, strlen(s) + 1, s);

		Person::Input();
	}
};

class Teacher : public Person
{
	char* school;
	int salary;
	char* subjects[3];
	int subject_number;
public:
	Teacher() = default;
	Teacher(const char* n, int a, const char* s, int sal) : Person(n, a)
	{
		cout << "Constructor Teacher\n";
		school = new char[strlen(s) + 1];
		strcpy_s(school, strlen(s) + 1, s);

		salary = sal;
		subject_number = 0;
		for (int i = 0; i < 3; i++) 
		{
			subjects[i] = nullptr;
		}
	}
	~Teacher()
	{
		delete[] school;
		for (int i = 0; i < subject_number; i++)
		{
			delete[] subjects[i];
		}
		cout << "Destruct Teacher\n";
		Sleep(1000);
	}
	void InputSubject(const char* subject) 
	{
		if (subject_number >= 3) return;

		if (subjects[subject_number]) delete[] subjects[subject_number];

		subjects[subject_number] = new char[strlen(subject) + 1];
		strcpy_s(subjects[subject_number], strlen(subject) + 1, subject);
		subject_number++;
	}

	void Print()
	{
		cout << "Output Teacher\n";
		Person::Print();
		cout << "School: " << school << endl;
		cout << "Salary: " << salary << endl;
		cout << "Subjects: ";
		for (int i = 0; i < subject_number; i++) 
		{
			if (subjects[i]) 
			{
				cout << subjects[i] << "  ";
			}
		}
		cout << endl;
	}
	void Input(const char* s, int sal, const char* s1, const char* s2, const char* s3)
	{
		delete[]school;

		school = new char[strlen(s) + 1];
		strcpy_s(school, strlen(s) + 1, s);

		salary = sal;

		InputSubject(s1); 
		InputSubject(s2);
		InputSubject(s3);

		Person::Input();
	}
};


int main()
{
	Student a("Oleg", 19, "Step");
	a.Print();
	cout << endl << endl;

	Doctor b("Olena", 21, "Nurse", 2);
	b.Print();
	cout << endl << endl;

	Driver c("Victor", 37, "XX3456XX", "3456X4X5");
	c.Print();
	cout << endl << endl;

	Teacher d;
	d.Input("School#1", 150000, "Math", "Physics", "Geometry");
	d.Print();
	cout << endl << endl;
	system("pause");
}