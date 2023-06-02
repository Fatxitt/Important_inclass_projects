#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct students {
	int mssv;
	string name;
	int birth;
};
void getsv(int& checksv) {
	cout << "nhap mssv sinh vien ban muon hien thi: ";
	cin >> checksv;
}
void check(int checksv, students a[], int i) {
	bool tf = false;
	for (size_t j = 0; j < i; j++)
	{
		if (checksv == a[j].mssv)
		{
			cout << a[j].mssv << endl;
			cout << a[j].name << endl;
			cout << a[j].birth;
			tf = true;
		}
	}
	if (tf == false)
	{
		cout << "khong co sinh vien co ma so tuong ung";
	}

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
	int checksv;
	int a = 0;


	readfile("list_student .txt", student, a);
	getsv(checksv);

	check(checksv, student, a);


	return 0;
}