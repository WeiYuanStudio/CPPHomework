//
// Created by weiyuan on 19-3-8.
//

#ifndef HOMEWORK3_HISTORY_H
#define HOMEWORK3_HISTORY_H

#include <fstream>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;


//struct HistoryTime {
//    int tm_min; //分钟
//    int tm_hour; //小时
//    int tm_day; //日
//    int tm_mon; //月
//    int tm_year; //年
//};

struct Historys {
    int GoodsIndex; //商品在Goods数组中的Index
    char P_S; //P 进货，S 出货
    tm HistorysTime; //进出货时间
    string Manufacturer; //厂家
    int P_S_Price; //进出货价格
    int NUM; //进货出货量
};



class History {
public:
    History();
    void AddHistory(Historys NewHistorys);
    void SaveHistory();
    void PrintHistory();
    vector <Historys> HistorysData;
    ~History();
};


#endif //HOMEWORK3_HISTORY_H
