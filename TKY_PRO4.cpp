//4:֮������5 function���Է������±�� ���㹤���պ���ĩ ���зֳ�����
#include<iostream>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<map>
#include<cstdlib>
#include<time.h>
#include <functional> 
#include<stdlib.h>
using namespace std;

#define ifilename "E:\\TKY_train4.txt"
#define ofilename "E:\\TKY_train5.txt"
#define categoryname "E:\\TKY_category.txt"

////�Զ���ṹ�壬���ڴ洢ÿ������
//struct Data{
//	int userid;
//	string poiid;
//	string lat;
//	string lon;
//	string date;
//	string time;
//	string week;
//	string category;
//};
//
//int changeMonth(string s){
//	if (s == "Jan")return 1;
//	if (s == "Feb")return 2;
//	if (s == "Mat")return 3;
//	if (s == "Apr")return 4;
//	if (s == "May")return 5;
//	if (s == "Jun")return 6;
//	if (s == "Jul")return 7;
//	if (s == "Aug")return 8;
//	if (s == "Sep")return 9;
//	if (s == "Oct")return 10;
//	if (s == "Nov")return 11;
//	if (s == "Dec")return 12;
//}
//int changeDate(string s){
//	if (s == "01")	return 1; if (s == "02") return 2; if (s == "03") return 3; if (s == "04") return 4; if (s == "05") return 5; if (s == "06") return 6; if (s == "07") return 7; if (s == "08") return 8; if (s == "09") return 9; if (s == "10") return 10;
//	if (s == "11") return 11; if (s == "12") return 12; if (s == "13") return 13; if (s == "14") return 14; if (s == "15") return 15; if (s == "16") return 16; if (s == "17") return 17; if (s == "18") return 18; if (s == "19") return 19; if (s == "20") return 20;
//	if (s == "21") return 21; if (s == "22") return 22; if (s == "23") return 23; if (s == "24") return 24; if (s == "25") return 25; if (s == "26") return 26; if (s == "27") return 27; if (s == "28") return 28; if (s == "29") return 29; if (s == "30") return 30; if (s == "31") return 31;
//}
////�Զ����vector��pushback����
//void myPushback(vector<Data> & vecData, const int &uid, const string &pid, const string &la, const string &lo, const string &da, const string &ti, const string &we, const string &cat){
//	Data data;
//	data.userid = uid; data.poiid = pid; data.lat = la; data.lon = lo;
//	data.date = da; data.time = ti; data.week = we; data.category = cat;
//	vecData.push_back(data);
//
//}

//������ĩ�͹����� ������Ϊ1 ��ĩΪ2	
int calWeek(string s){
	if (s == "Mon" || s == "Tue" || s == "Wed" || s == "Thu" || s == "Fri")	return 1;//������
	if (s == "Sat" || s == "Sun")	return 2;//��ĩ
}
//����������0��00�D6:00�賿,6:00�D11:00���磬11:00�D13:00���磬13:00�D16:00���磬16:00�D18:00����18:00�D24:00����
int calTime(string s1){
	/*tm tm_1;
	time_t t1;
	char buf[128] = { 0 };
	const char *temp1 = s1.data();
	strcpy(buf, temp1);*/
	string tmp = s1.substr(0, 2);
	//if (tmp == "00" || tmp == "01" || tmp == "02" || tmp == "03" || tmp == "04" || tmp == "05")	return 1;//�賿
	//if (tmp == "06" || tmp == "07" || tmp == "08" || tmp == "09" || tmp == "10" )	return 2;//����
	//if (tmp == "11" || tmp == "12" )	return 3;//����
	//if (tmp == "13" || tmp == "14" || tmp == "15" )	return 4;//����
	//if (tmp == "16" || tmp == "17" )	return 5;//����
	//if (tmp == "18" || tmp == "19" || tmp == "20" || tmp == "21" || tmp == "22" || tmp == "23")	return 6;//����

	if (tmp == "06" || tmp == "07" || tmp == "08" || tmp == "09" || tmp == "10" || tmp == "11")	return 1;//����
	if (tmp == "12" || tmp == "13" || tmp == "14" || tmp == "15" || tmp == "16" || tmp == "17")	return 2;//����
	if (tmp == "18" || tmp == "19" || tmp == "20" || tmp == "21" || tmp == "22" || tmp == "23" || tmp == "00" || tmp == "01" || tmp == "02" || tmp == "03" || tmp == "04" || tmp == "05")	return 3;//����
}
//���±��cate�������ܼ���������
void reNumcate(){
	ifstream fin(ifilename);
	ofstream fout(ofilename);
	ofstream ffout(categoryname);
	if (!fin){
		cout << "error!" << endl;
		exit(1);
	}
	map<string, int> mapcate;
	map<string, int>::iterator it;
	string s;
	int count = 0;
	while (!fin.eof()){
		string str[8];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7];
		getline(fin, s);
		it = mapcate.find(str[7]);
		if (it != mapcate.end()){}//�ҵ�Ԫ�� ���������
		else{
			//δ�ҵ�Ԫ�� �Ͳ���map
			mapcate.insert(pair<string, int>(str[7], ++count));
		}
	}
	fin.close();
	//����map������ļ�
	map<string, int>::iterator its;
	for (its = mapcate.begin(); its != mapcate.end(); its++){
		ffout << its->second << "\t" << its->first << endl;
	}
	ffout << "cateNum:" << count << endl;
	//�ٴζ�ȡ�ļ��޸����ںͼ���������
	fin.open(ifilename);
	while (!fin.eof()){
		string str[8];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7];
		getline(fin, s);
		fout << str[0] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << " " << str[5] << "\t" << calTime(str[5]) << "\t" << calWeek(str[6]) << "\t" << mapcate[str[7]] << endl;
	}
	fin.close();
	fout.close();
	ffout.close();
}

int main(){
	//reNumcate();
	//Ϊ����ͼ ����timeofday �� dayofweek�ķֲ�����
	double p, r;
	cout << "input:" << endl;
	cin >> p >> r;
	double f1 = (2.0*p*r) / (p + r);
	cout << "output:" << f1 << endl;
	return 0;
}