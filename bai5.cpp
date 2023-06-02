#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct students {
	int mssv;
	string name;
	int birth;
};
void getsv(students& newsv,int &x,int a,students student[]) {
	cout << "nhap mssv sinh vien ban muon : ";
	cin >> newsv.mssv;
	cout << "nhap ten sinh vien ban muon thay doi: ";
	cin.ignore();
	getline(cin, newsv.name);
	for (size_t i = 0; i < a; i++)
	{
		if (newsv.mssv==student[i].mssv)
		{
			x = i;
		}
	}
	
}
void insertsv(students newsv, string path, int a, students student[]) {
	ofstream ofs;
	ofs.open(path, ios::out | ios::trunc);
	if (!ofs)
	{
		cout << "modify student fail" << endl;
		exit(1);
	}
	for (size_t i = 0; i < a; i++)
	{
		ofs << student[i].mssv << "," << student[i].name << "," << student[i].birth << endl;
	}
	
	cout << "modify student success";
	ofs.close();
}

void readfile(string path, students a[], int& i) {
	ifstream ifs;
	ifs.open(path);
	if (!ifs)
	{
		cout << "modify student fail" << endl;
		exit(1);
	}
	i = 0;
	while (!ifs.eof())
	{
		ifs >> a[i].mssv;
		ifs.seekg(1, 1);
		getline(ifs, a[i].name, ',');
		ifs >> a[i].birth;
		i++;
	}
	ifs.close();
}
int main() {
	students student[100];
	students newsv;
	int a = 0;
	int x=0;
	string path = "list_student .txt";
	readfile(path, student, a);
	getsv(newsv,x,a,student);
	 student[x].name=newsv.name;
	
	insertsv(newsv, path, a, student);


	return 0;
}