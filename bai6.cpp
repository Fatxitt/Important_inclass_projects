#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct students {
	int mssv;
	string name;
	int birth;
};
void getsv(int& n,int x,students student[]) {
	int a;
	bool check = true;
	cout << "nhap ma so sinh vien ban muon xoa : ";cin >> a;
	for (int j = 0; j < x; j++)
	{
		if (a==student[j].mssv)
		{
			n = j;
			check = false;
		}
	}
	if (check==true)
	{
		cout << "khong co mssv hop le :";
		exit(1);
	}
}
void deletesv(string path, int a, students student[],int n) {
	for (size_t i = n; i < a-1; i++)
	{
		student[i] = student[i + 1];
	}
	
	ofstream ofs;
	ofs.open(path, ios::out | ios::trunc);
	if (!ofs)
	{
		cout << "delete student fail" << endl;
		exit(1);
	}
	for (size_t i = 0; i < a-1; i++)
	{
		ofs << student[i].mssv << "," << student[i].name << "," << student[i].birth << endl;
	}
	
	cout << "delete student success";
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
	int xoa;
	int a = 0;
	int n;
	string path = "list_student .txt";
	readfile(path, student, a);
	getsv(n,a,student);
	deletesv( path, a, student,n);


	return 0;
}