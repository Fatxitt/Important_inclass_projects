#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct student {
	int mssv;
	string name;
	int birth;
};
void readfile(string path, student a[]) {
	ifstream ifs;
	ifs.open(path);
	if (!ifs)
	{
		cout << "Error: file not opened." << endl;
		exit(1);
	}
	int i = 0;
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
	student student[100];


	readfile("list_student .txt", student);

	for (size_t i = 0; i < 4; i++)
	{
		cout << student[i].name << endl;
	}
	
	return 0;

}