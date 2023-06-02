
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct students {
	int mssv;
	string name;
	int birth;
};
void getsv(students & newsv) {
	cout << "nhap mssv sinh vien ban muon them: ";
	cin >> newsv.mssv;
	cout << "nhap ten sinh vien ban muon them: ";
	cin.ignore();
	getline(cin,newsv.name);
	
	cout << "nhap nam sinh sinh vien ban muon them: ";
	cin >> newsv.birth;
}
void insertsv(students newsv,string path,int a,students student[]) {
	ofstream ofs;
	ofs.open(path, ios::out | ios::trunc);
	if (!ofs)
	{
		cout << "insert student fail." << endl;
		exit(1);
	}
	for (size_t i = 0; i < a; i++)
		{
			ofs << student[i].mssv << "," << student[i].name <<"," << student[i].birth << endl;
		}
	ofs << newsv.mssv << "," << newsv.name << ","<<newsv.birth ;
		cout << "insert student success";
		ofs.close();
}

void readfile(string path, students a[], int& i) {
	ifstream ifs;
	ifs.open(path);
	if (!ifs)
	{
		cout << "Error: file not opened." << endl;
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
	string path = "list_student .txt";
    readfile(path, student, a);
	getsv(newsv);
	insertsv(newsv, path, a, student);
	

	return 0;
}