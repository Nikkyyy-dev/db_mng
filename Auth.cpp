#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class People{
private:
	string name;
	string surname;
	int age;
	int id;
public:
	People (){
	name = "Ivan";
	surname = "Ivanov";
	age = 0;
	id = 1;
	}
	People (int Id, string Name, string Surname, int Age){
	id = Id;
	name = Name;
	surname = Surname;
	age = Age;
	}
	void GetPeople() const{
	cout << id << " " << name << " " << surname << " " << age << "лет." << endl;
	}
	void SetPeople() {
	cout << "Введите имя: "; cin >> name;
	cout << "Введите фамилию: "; cin >> surname;
	cout << "Введите возраст: "; cin >> age; cout << endl;
	}

	void SetPeople2(int Id, string Name,string Surname, int Age) {
	name = Name;
	surname = Surname;
	age = Age;
	id = Id;
	}

	void SavePeople()
	{
	ofstream fout;
	fout.open("People.txt",ios_base::app); //открываем файл для добавления инфы в конец файла
	fout << id << " " << name << " " << surname << " " << age << "\n";
	fout.close();
	}

	void DeletePeople()
	{
	ofstream fout;
	fout.open("People.txt");

	fout.close();
	}

	void SetID(int Id)
	{
	id = Id;
	}

};

class People2{
	int Size;
	vector<People> Massive;
	People Man;
	string name;
	string surname;
	int age;
	int id;
	int check;
public:
	void Inisialize()
	{
	ifstream fin("People.txt");
	while(!fin.eof()){
	check = id;
	fin >> id;
	fin >> name;
	fin >> surname;
	fin >> age;
	if(check !=id)	{
	Man.SetPeople2(id, name,surname,age);
	Massive.push_back(Man);
		}
	}
	}

	void PrintPeople2(){
	for(auto i: Massive)
	i.GetPeople();
	}

	int GetSize()
	{
	Size = Massive.size();
	return Size;
	}
};


int main(){
	int n;

	cout << "Введите команду (-1 - очистить БД, 0 - показать список, >0 - добавить людей): "; cin >> n; cout << endl;

	if (n<0){
	People people; people.DeletePeople(); cout << "БД очищена!" << endl; return 0;}

	vector <People> Massive(n);

	People2 Massive2;
	Massive2.Inisialize();
	int id = Massive2.GetSize();

	for(auto &i : Massive)
	{
	i.SetPeople();
	i.SetID(++id);
	i.SavePeople();
	}

	Massive2.Inisialize();
	Massive2.PrintPeople2();
	return 0;
}
