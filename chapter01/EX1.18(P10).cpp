#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::istream;
using std::vector;
enum Sex{female,male};
enum Schoolname{A,B,C,D,E};
struct grades
{
	string project;//项目名称
	Sex sex;
	Schoolname schools;
	unsigned scores;
};

struct sums
{
	unsigned malescores=0;//男性总分
	unsigned femalescores=0;//女性总分
	unsigned teamscores=0;//团队总分
};

void readingdatas(istream& is,vector<grades>&vec)
{
	string _project;
	Sex _sex;
	Schoolname _schoolname;
	unsigned _scores;
	grades g;
	while (is >> _project >> (int&)_sex >> (int&)_schoolname >> _scores)//这里忽略更完善的输入检查
	{
		g.project = _project;
		g.sex = _sex;
		g.schools = _schoolname;
		g.scores = _scores;
		vec.push_back(g);
	}
}
void report(const vector<grades>& vec)
{
	sums arr[5];//存储五所学校分数
	for (auto e : vec)
	{
		switch (e.schools)
		{
		case A:
			arr[0].teamscores += e.scores;
			if (e.sex == female)
				arr[0].femalescores += e.scores;
			else
				arr[0].malescores += e.scores;
			break;
		case B:
			arr[1].teamscores += e.scores;
			if (e.sex == female)
				arr[1].femalescores += e.scores;
			else
				arr[1].malescores += e.scores;
			break;
		case C:
			arr[2].teamscores += e.scores;
			if (e.sex == female)
				arr[2].femalescores += e.scores;
			else
				arr[2].malescores += e.scores;
			break;
		case D:
			arr[3].teamscores += e.scores;
			if (e.sex == female)
				arr[3].femalescores += e.scores;
			else
				arr[3].malescores += e.scores;
			break;
		case E:
			arr[4].teamscores += e.scores;
			if (e.sex == female)
				arr[4].femalescores += e.scores;
			else
				arr[4].malescores += e.scores;
			break;
		}
	}
	std::cout << "A: " << arr[0].femalescores << " " << arr[0].malescores << " " << arr[0].teamscores<<std::endl;
	std::cout << "B: " << arr[1].femalescores << " " << arr[1].malescores << " " << arr[1].teamscores<<std::endl;
	std::cout << "C: " << arr[2].femalescores << " " << arr[2].malescores << " " << arr[2].teamscores<<std::endl;
	std::cout << "D: " << arr[3].femalescores << " " << arr[3].malescores << " " << arr[3].teamscores<<std::endl;
	std::cout << "E: " << arr[4].femalescores << " " << arr[4].malescores << " " << arr[4].teamscores<<std::endl;
}
int main()
{
	vector<grades>vec;
	readingdatas(std::cin, vec);
	sums arr[5];
	report(vec);
}