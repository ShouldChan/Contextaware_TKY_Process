////3：按用户的时间排序
//#include<iostream>
//#include<algorithm>
//#include<fstream>
//#include<sstream>
//#include<string.h>
//#include<stdio.h>
//#include<vector>
//#include<map>
//#include<cstdlib>
//#include<time.h>
//using namespace std;
//
//#define ifilename "E:\\train3.txt"
//#define ofilename "E:\\train4.txt"
//
//
//time_t StringToDatetime(char *str)
//{
//	tm tm_;
//	int year, month, day, hour, minute, second;
//	sscanf(str, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
//	tm_.tm_year = year - 1900;
//	tm_.tm_mon = month - 1;
//	tm_.tm_mday = day;
//	tm_.tm_hour = hour;
//	tm_.tm_min = minute;
//	tm_.tm_sec = second;
//	tm_.tm_isdst = 0;
//
//	time_t t_ = mktime(&tm_); //已经减了8个时区  
//	return t_; //秒时间  
//}
//int calTime(string s1){
//	tm tm_1;
//	time_t t1;
//	char buf[128] = { 0 };
//	const char *temp1 = s1.data();
//	strcpy(buf, temp1);
//	t1 = StringToDatetime(buf);
//	int result = t1 / 3600;
//	return result;
//}
////自定义结构体，用于存储每行数据
//struct Data{
//	int userid;
//	string poiid;
//	string categoryid;
//	string lat;
//	string lon;
//	string date;
//	string time;
//	string week;
//	string category;
//};
////自定义排序函数，用于调用sort函数 升序
//bool sortBy(const Data &s1, const Data &s2){
//	return s1.userid < s2.userid;
//}
////定义的vector的pushback函数
//void myPushback(vector<Data> & vecData, const int &uid, const string &pid, const string &cid, const string &la, const string &lo, const string &da, const string &ti, const string &we, const string &cat){
//	Data data;
//	data.userid = uid; data.poiid = pid; data.categoryid = cid; data.lat = la; data.lon = lo;
//	data.date = da; data.time = ti; data.week = we; data.category = cat;
//	vecData.push_back(data);
//}
////按用户userid重新排序
//void reSeat(){
//	ifstream fin(ifilename);
//	ofstream fout(ofilename);
//	if (!fin.good()){
//		cerr << "wrong open!" << endl;
//		exit(1);
//	}
//	vector<Data> vecStr;
//	string s;
//	int i = 0;
//	while (!fin.eof()){
//		int uid;
//		string str[8];
//		fin >> uid >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7];
//		getline(fin, s);
//		myPushback(vecStr, uid, str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7]);
//	}
//	//排序并遍历vecStr	
//	//sort(vecStr.begin(), vecStr.end(), sortBy);
//
//	for (int j = vecStr.size() - 1; j > 0; --j){
//		for (int k = 0; k < j; ++k){
//			string kongge = " ";
//			string s1 = vecStr[j].date;
//			s1.append(kongge + vecStr[j].time);
//			string s2 = vecStr[k].date;
//			s2.append(kongge + vecStr[k].time);
//			if (vecStr[j].userid == vecStr[k].userid&&calTime(s1) < calTime(s2)){
//				swap(vecStr[j], vecStr[k]);
//				//cout << "1" << endl;
//			}
//		}
//	}
//	for (vector<Data>::iterator it = vecStr.begin(); it != vecStr.end(); it++){
//		fout << it->userid << "\t" << it->poiid << "\t" << it->categoryid << "\t" << it->lat << "\t" << it->lon << "\t" << it->date << " " << it->time << "\t" << it->week << "\t" << it->category << endl;
//	}
//	fin.close();
//	fout.close();
//}
//
//int main(){
//	reSeat();
//	//string s1="2012/1/5 14:00:00";
//	//cout<<calTime(s1)<<endl;
//	return 0;
//}
//3：按用户的时间排序
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
using namespace std;

#define ifilename "E:\\TKY_train3.txt"
#define ofilename "E:\\TKY_train4.txt"

time_t StringToDatetime(char *str)
{
	tm tm_;
	int year, month, day, hour, minute, second;
	sscanf(str, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
	tm_.tm_year = year - 1900;
	tm_.tm_mon = month - 1;
	tm_.tm_mday = day;
	tm_.tm_hour = hour;
	tm_.tm_min = minute;
	tm_.tm_sec = second;
	tm_.tm_isdst = 0;

	time_t t_ = mktime(&tm_); //已经减了8个时区  
	return t_; //秒时间  
}
int calTime(string s1){
	tm tm_1;
	time_t t1;
	char buf[128] = { 0 };
	const char *temp1 = s1.data();
	strcpy(buf, temp1);
	t1 = StringToDatetime(buf);
	int result = t1 / 3600;
	return result;
}
//自定义结构体，用于存储每行数据
struct Data{
	int userid;
	string poiid;
	string categoryid;
	string lat;
	string lon;
	string date;
	string time;
	string week;
	string category;
};
typedef pair<int, Data> PAIR;

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {

	if (lhs.first == rhs.first)
		return calTime(lhs.second.date + " " + lhs.second.time)<calTime(rhs.second.date + " " + rhs.second.time);
	else return lhs.first<rhs.first;
}

//自定义排序函数，用于调用sort函数 升序
bool sortBy(const Data &s1, const Data &s2){
	return s1.userid < s2.userid;
}
//定义的vector的pushback函数
void myPushback(vector<Data> & vecData, const int &uid, const string &pid, const string &cid, const string &la, const string &lo, const string &da, const string &ti, const string &we, const string &cat){
	Data data;
	data.userid = uid; data.poiid = pid; data.categoryid = cid; data.lat = la; data.lon = lo;
	data.date = da; data.time = ti; data.week = we; data.category = cat;
	vecData.push_back(data);

}
Data getData_value(const int &uid, const string &pid, const string &cid, const string &la, const string &lo, const string &da, const string &ti, const string &we, const string &cat){
	Data data;
	data.userid = uid; data.poiid = pid; data.categoryid = cid; data.lat = la; data.lon = lo;
	data.date = da; data.time = ti; data.week = we; data.category = cat;
	return data;

}
//按用户userid重新排序
void reSeat(){
	ifstream fin(ifilename);
	ofstream fout(ofilename);
	if (!fin.good()){
		cerr << "wrong open!" << endl;
		exit(1);
	}
	//vector<Data> vecStr;
	multimap<int, Data, greater<int>>a;
	string s;
	int i = 0;
	while (!fin.eof()){
		int uid;
		string str[8];
		fin >> uid >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7];
		getline(fin, s);
		Data d = getData_value(uid, str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7]);
		a.insert(make_pair(d.userid, d));
	}

	//根据单个用户的checkin time先后进行排序
	vector<PAIR> name_score_vec(a.begin(), a.end());
	//sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());  
	sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);
	for (int i = 0; i != name_score_vec.size(); ++i) {
		fout << name_score_vec[i].first << "\t" << name_score_vec[i].second.poiid << "\t" << name_score_vec[i].second.lat <<
			"\t" << name_score_vec[i].second.lon << "\t" << name_score_vec[i].second.date << " " << name_score_vec[i].second.time << "\t"
			<< name_score_vec[i].second.week << "\t" << name_score_vec[i].second.category << endl;
	}

	fin.close();
	fout.close();
}

int main(){
	reSeat();
	//string s1="2012/1/5 14:00:00";
	//cout<<calTime(s1)<<endl;
	return 0;
}