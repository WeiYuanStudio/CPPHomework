//
// Created by weiyuan on 19-3-8.
//

#include "History.h"
#include "Depository.h"


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
                    >> Temp.P_S_Quantity;

            HistorysData.push_back(Temp);
        }
    }
}

void History::AddHistory(Historys NewHistorys) {
    time_t now = time(0);
    tm *time = localtime(&now);
    NewHistorys.HistorysTime.tm_min = time->tm_min;
    NewHistorys.HistorysTime.tm_hour = time->tm_hour;
    NewHistorys.HistorysTime.tm_mday = time->tm_mday;
    NewHistorys.HistorysTime.tm_mon = time->tm_mon;
    NewHistorys.HistorysTime.tm_year = time->tm_year;
    HistorysData.push_back(NewHistorys);
}

void History::SaveHistory() {
    ofstream HistoryDataBase("/disk2/playground/History.database");
    if (HistoryDataBase) {
        int DataBaseSize = (int) HistorysData.size();
        HistoryDataBase << DataBaseSize << endl;
        for (auto &i: HistorysData) {
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
                    << i.P_S_Quantity << endl;
        }
    }
}

void History::PrintHistory() {
    for (auto i:HistorysData) {
        Depository MyDepository;
        cout << "时间："
             << i.HistorysTime.tm_year + 1900 << "年"
             << i.HistorysTime.tm_mon << "月"
             << i.HistorysTime.tm_mday << "日"
             << i.HistorysTime.tm_hour << ":"
             << i.HistorysTime.tm_min << endl
             << "产品编号：" << MyDepository.GoodsData[i.GoodsIndex].GoodsNum << endl
             << "产品名：" << MyDepository.GoodsData[i.GoodsIndex].GoodsName << endl
             << "进出货：" << (i.P_S == 'P' || i.P_S == 'p' ?"进货":"出货") << endl
             << "交易方：" << i.Manufacturer << endl
             << "交易价格:" << i.P_S_Price << endl
             << "交易数量:" << i.P_S_Quantity << endl;
    }
}

History::~History() {
    SaveHistory();
}