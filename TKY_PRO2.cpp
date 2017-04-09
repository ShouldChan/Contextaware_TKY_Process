//2：按用户排序
#include<iostream>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<cstdlib>
using namespace std;

#define ifilename "E:\\TKY_train2.txt"
#define ofilename "E:\\TKY_train3.txt"
#define oofilename "E:\\TKY_train4.txt"

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
//按用户userid重新排序
void reSeat(){
	ifstream fin(ifilename);
	ofstream fout(ofilename);
	if (!fin.good()){
		cerr << "wrong open!" << endl;
		exit(1);
	}
	vector<Data> vecStr;
	string s;
	int i = 0;
	while (!fin.eof()){
		int uid;
		string str[8];
		fin >> uid >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7];
		getline(fin, s);
		myPushback(vecStr, uid, str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7]);
	}
	//排序并遍历vecStr	
	sort(vecStr.begin(), vecStr.end(), sortBy);
	for (vector<Data>::iterator it = vecStr.begin(); it != vecStr.end(); it++){
		fout << it->userid << "\t" << it->poiid << "\t" << it->categoryid << "\t" << it->lat << "\t" << it->lon << "\t" << it->date << " " << it->time << "\t" << it->week << "\t" << it->category << endl;
	}

	fin.close();
	fout.close();
}
void mapreno(){
	ifstream fin(ofilename);
	ofstream fout(oofilename);
	if (!fin.good()){
		cerr << "wrong open!" << endl;
		exit(1);
	}
	string s;
	map<string, int> mapuser;
	map<string, int>::iterator iteruser;
	int i = 1;//记录user的个数
	while (!fin.eof()){
		string str[9];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7] >> str[8];
		getline(fin, s);
		iteruser = mapuser.find(str[0]);
		if (iteruser != mapuser.end()){
			//找到元素不插入
		}
		else{
			//未找到元素插入
			mapuser.insert(pair<string, int>(str[0], i));
			i++;
		}
	}
	fin.close();
	fin.open(ifilename);
	//遍历map
	map<string, int>::iterator iter;
	for (iter = mapuser.begin(); iter != mapuser.end(); iter++){
		fout << iter->first << "\t" << iter->second << endl;
	}
	fout << "user num:" << i << endl;
	while (!fin.eof()){
		string str[9];
		fin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7] >> str[8];
		getline(fin, s);
		//iteruser = mapuser.find(str[0]);
		//fout << mapuser[str[0]] <<"\t"<< mappoi[str[1]]<<endl;
		//if (iteruser != mapuser.end() && iterpoi != mappoi.end()){
		//cout << iteruser->second << "\t" << iterpoi->second << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << endl;
		fout << mapuser[str[0]] << "\t" << str[1] << "\t" << str[2] << "\t" << str[3] << "\t" << str[4] << "\t" << str[5] << "\t" << str[6] << " " << str[7] << "\t" << str[8] << endl;
		//}
	}
	cout << "user num:" << mapuser.size() << endl;

	fin.close();
	fout.close();
}


int main(){
	//reSeat();
	mapreno();
	return 0;
}