#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct students {
	int mssv;
	string name;
	int birth;
};

void find_agemin(students a[], int i){
	int x = a[0].birth;
	for (size_t j = 0; j < i ; j++)
	{


		if (a[j].birth >x)
		{
			x = a[j].birth;
		}
	
	}
	for (size_t j = 0; j < i; j++)
	{
		if (x==a[j].birth)
		{
			cout << a[j].name << endl;
		}
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
	students newsv;
	int a = 0;
	string path = "list_student .txt";
	readfile(path, student, a);
	find_agemin(student, a);

	return 0;
}