//
// Created by weiyuan on 19-3-8.
//

#include "History.h"


History::History() {
    ifstream HistoryDataBase("/disk2/playground/History.database"); //历史记录数据库
    int DataBaseSize;
    if (HistoryDataBase) {
        HistoryDataBase >> DataBaseSize;
        Historys Temp;
        for (int i = 0; i < DataBaseSize; i++) {
            HistoryDataBase
                >> Temp.GoodsIndex
                >> Temp.P_S
                >> Temp.HistorysTime.tm_min
                >> Temp.HistorysTime.tm_hour
                >> Temp.HistorysTime.tm_mday
                >> Temp.HistorysTime.tm_mon
                >> Temp.HistorysTime.tm_year
                >> Temp.Manufacturer
                >> Temp.P_S_Price
                >> Temp.NUM;
        }
    }
}

void History::AddHistory(Historys NewHistorys) {
    time_t t;
    NewHistorys.HistorysTime.tm_min = localtime(&t)->tm_min;
    NewHistorys.HistorysTime.tm_hour = localtime(&t)->tm_hour;
    NewHistorys.HistorysTime.tm_mday = localtime(&t)->tm_mday;
    NewHistorys.HistorysTime.tm_mon = localtime(&t)->tm_mon;
    NewHistorys.HistorysTime.tm_year = localtime(&t)->tm_year;
    HistorysData.push_back(NewHistorys);
}

void History::SaveHistory() {
    ofstream HistoryDataBase("/disk2/playground/History.database");
    if (HistoryDataBase) {
        int DataBaseSize = (int) HistorysData.size();
        HistoryDataBase << DataBaseSize << endl;
        for (auto i: HistorysData) {
            HistoryDataBase
                    << i.GoodsIndex << "\t"
                    << i.P_S << "\t"
                    << i.HistorysTime.tm_min << "\t"
                    << i.HistorysTime.tm_hour << "\t"
                    << i.HistorysTime.tm_mday << "\t"
                    << i.HistorysTime.tm_mon << "\t"
                    << i.HistorysTime.tm_year << "\t"
                    << i.Manufacturer << "\t"
                    << i.P_S_Price << "\t"
                    << i.NUM << endl;
        }
    }
}

void History::PrintHistory() {
    for (auto i:HistorysData) {
        cout << "产品编号：" << i.GoodsIndex << endl
             << "进出货：" <<i.P_S << endl
             << "时间："
             << i.HistorysTime.tm_year << "年"
             << i.HistorysTime.tm_mon << "月"
             << i.HistorysTime.tm_mday << "日"
             << i.HistorysTime.tm_hour << ":"
             << i.HistorysTime.tm_min << endl;
    }
}

History::~History() {
    SaveHistory();
}
