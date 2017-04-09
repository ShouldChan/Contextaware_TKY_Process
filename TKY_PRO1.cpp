//process1:处理数据集的category属性和日期时间
#include<iostream>
#include<fstream>
#include<ostream>
#include<sstream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

#define ifiletest "E:\\TKY_train0.txt"
#define ofiletest1 "E:\\TKY_train1.txt"
#define ofiletest2 "E:\\TKY_train2.txt"

//1：将category和时间中的空格处理为“，”方便文件流的操作
void spaceProcess(){
	char ch;
	FILE *fin = fopen(ifiletest, "r");
	FILE *fout = fopen(ofiletest1, "w");
	while (!feof(fin)){
		ch = fgetc(fin);
		if (ch == ' '){
			ch = ',';
		}
		//cout << ch;
		fputc(ch, fout);
	}
	fclose(fin);
	fclose(fout);
}

//c++的switch语句不支持string做条件？？？
int changeMonth(string s){
	if (s == "Jan")return 1;
	if (s == "Feb")return 2;
	if (s == "Mat")return 3;
	if (s == "Apr")return 4;
	if (s == "May")return 5;
	if (s == "Jun")return 6;
	if (s == "Jul")return 7;
	if (s == "Aug")return 8;
	if (s == "Sep")return 9;
	if (s == "Oct")return 10;
	if (s == "Nov")return 11;
	if (s == "Dec")return 12;
}
int changeDate(string s){
	if (s == "01")	return 1; if (s == "02") return 2; if (s == "03") return 3; if (s == "04") return 4; if (s == "05") return 5; if (s == "06") return 6; if (s == "07") return 7; if (s == "08") return 8; if (s == "09") return 9; if (s == "10") return 10;
	if (s == "11") return 11; if (s == "12") return 12; if (s == "13") return 13; if (s == "14") return 14; if (s == "15") return 15; if (s == "16") return 16; if (s == "17") return 17; if (s == "18") return 18; if (s == "19") return 19; if (s == "20") return 20;
	if (s == "21") return 21; if (s == "22") return 22; if (s == "23") return 23; if (s == "24") return 24; if (s == "25") return 25; if (s == "26") return 26; if (s == "27") return 27; if (s == "28") return 28; if (s == "29") return 29; if (s == "30") return 30; if (s == "31") return 31;
}
//2：重新排列
void reSeat(){
	ifstream fin(ofiletest1);
	ofstream fout(ofiletest2);
	if (!fin.good()){
		cerr << "wrong open!" << endl;
		exit(0);
	}
	string s;
	while (!fin.eof()){
		string str[8];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7];
		getline(fin, s);
		//处理最后一列字符串 用stringstream抽取时间	Tue,Apr,03,18:06:19,+0000,2012	#3 7 10 19-25
		str[7][3] = str[7][7] = str[7][10] = str[7][19] = str[7][20] = str[7][21] = str[7][22] = str[7][23] = str[7][24] = str[7][25] = ' ';
		stringstream ostr(str[7]);
		string weekday, month, date, time, year;
		ostr >> weekday >> month >> date >> time >> year;
		//cout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[4] << "\t" << str[5] << "\t" << year << "/" << changeMonth(month) << "/" << changeDate(date) << " " << time << "\t" <<weekday<< "\t" << str[3] << endl;
		fout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[4] << "\t" << str[5] << "\t" << year << "/" << changeMonth(month) << "/" << changeDate(date) << " " << time << "\t" << weekday << "\t" << str[3] << endl;
		//fout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << "\t" << str[6] << "\t" << str[7] << endl;
	}

	fin.close();
	fout.close();
}
int main(){
	spaceProcess();//1
	reSeat();//2
	return 0;
}