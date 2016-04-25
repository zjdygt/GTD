//done~gt
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <iomanip>
#include <vector>

#include <time.h>
#include <string.h>

using namespace std;

enum{
    _ERROR = 99999999
};


class Event{
public:
        // 事件的名字
    string name;
        // 事件的描述
    string description;
        // 事件的地点
    string location;
        // 用户设定的提醒时间
        // 可以有多个提醒时间

    struct tm begin, end;


//    struct Time{
//        vector<string> s;
//        vector<struct tm> t;
//    } *remind, *time;
        // time是事件的时间
        // 默认第一个为开始时间，之后是结束时间，剩下的还不知道用来干什么
        // 如果为空，则表示是全天事件
};

ostream& operator<<(ostream &os, const Event &e);

    // 语句分析函数，读入一个字符串，返回一个事件类。
    // 现在先假设： =1 表示名字； =2 描述； =3 开始时间； =4 结束时间； =5 地点； //=6 提醒。
    // 例如，s为
    // "=1 打篮球 =3 1600 =6 10 =5 篮球场"，
    // 就表示今天下午4点在篮球场打篮球，提前十分钟提醒。
    // "=1 ADS作业 =3 4.14 2030 =6 0"，
    // 表示4月14号晚上八点半写ADS作业，准时提醒。
    // "=1 数据库考试 =3 4.27 1400 =4 +120 =6 60 =5 西一303"，
    // 4月27号下午两点数据库考试，考两个小时，在西一303，提前一个小时提醒我。
Event AnalyseSnytax(string s);

    // 在网上安装一个第三方库，解析XML，将数据存入XML文件中，要求能够原样读取出来。
    // XML解析器有很多，并不难。
bool SaveEvent(Event e);
vector<Event> LoadEvents();

int TransInt(char *s);

#endif // EVENT_H
