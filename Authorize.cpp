#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct user{
  int id;
  string login;
  string pass;
  bool Authorisation =false ;
};

class Auth
{
private:
  int id;
  string login;
  string pass;
  int check;
  vector <user> Users;

public:
    user User;
  Auth()
  {

  }

  void PrintUsers()
  {
    cout << "\nСписок лиц: " << endl;
    for(auto i : Users){
    cout << i.login << " " << i.pass << endl;
    }
  }

  void Inisialize()
  {
    string pass2;
    ifstream fin("List.txt");
  	while(!fin.eof()){
  	pass2 = User.pass;
  	getline(fin,User.login,' ');
    getline(fin,User.pass, ' ');
    if (pass2 != User.pass)
  	Users.push_back(User);
  	}
  }

  void AddUser(user& Use)
	{
	ofstream fout;
	fout.open("List.txt",ios_base::app); //открываем файл для добавления инфы в конец файла
	fout << Use.login << " " << Use.pass << " ";
	fout.close();

	}

  user GetUser() const
  {
    return User;
  }

  void ConvertToUser(string &Str)
  {
    int numer = Str.length();
    string temporary;
    for (int j=0, i=0; j < numer; j++, i++)
		{
			if(Str[j] == ' ')
			{
				User.login = temporary;
				temporary.clear();
				i=0;
			}
				else {
					temporary += Str[j];
				}

		}
    User.pass = temporary;
    if(CheckUser(User))
    User.Authorisation = true;
  }

  bool CheckUser(user &Use)
  {
    for (auto i : Users)
    {
      if (i.login == Use.login){
      return true;
      }
    }

  }

};



int main()
{
  Auth auth;
  string User;
  user Use;
  getline (cin, User, '\n');
  auth.Inisialize();//Инициализация вектора Юзеров
  auth.ConvertToUser(User);//преобразование строки в структру Юзера
  cout << auth.User.Authorisation;//проверка, есть ли Юзер в списке
  //Use = auth.GetUser();
  //auth.AddUser(Use);

  auth.PrintUsers();//показать, кто есть в списке



  return 0;
}
