//
// Created by weiyuan on 19-3-5.
//

#include "Depository.h"
#include "Menu.h"

/**
 * Depository构造方法
 * 每次被实例化的时候，从文件系统读取数据到GoodsData<Vector>容器
 * 从GoodsDataBase循环读出至Temp(一个Goods结构体的对象)
 * 再从Temp push_back至GoodsData<Vector>容器中
 */

Depository::Depository() {
    ifstream GoodsDataBase("/disk2/playground/Depository.database");//此处为数据库路径
    int DataBaseSize;//声明数据库大小
    if (GoodsDataBase) {
        GoodsDataBase >> DataBaseSize;// 传入数据库大小

        Goods Temp; //新建一个临时Goods结构体Temp，用于将磁盘数据转存至内存

        for (int i = 0; i < DataBaseSize; i++) {
            GoodsDataBase
                    >> Temp.GoodsNum
                    >> Temp.GoodsName
                    >> Temp.GoodsOrigin
                    >> Temp.GoodsQuantity
                    >> Temp.GoodsPrice; //逐步读出一条数据

            GoodsData.push_back(Temp); //将Temp写入GoodsData<Vector>
        }
    }
    GoodsDataBase.close();
}



void Depository::AddGoods(Goods NewGoods) {
    GoodsData.push_back(NewGoods);
}



void Depository::SaveGoods() {
    ofstream GoodsDataBase("/disk2/playground/Depository.database"); //此处为数据库路径
    if (GoodsDataBase) {
        int DataBaseSize = (int) GoodsData.size();
        GoodsDataBase << DataBaseSize << endl;
        for (int i = 0; i < DataBaseSize; i++) {
            GoodsDataBase
                    << GoodsData[i].GoodsNum << " "
                    << GoodsData[i].GoodsName << " "
                    << GoodsData[i].GoodsOrigin << " "
                    << GoodsData[i].GoodsQuantity << " "
                    << GoodsData[i].GoodsPrice << endl;
        }
        GoodsDataBase.close();
        cout << "保存完毕" << endl;
    } else {
        cout << "文件打开错误，保存失败！" << endl;
    }
}



void Depository::DeleteGoods(int GoodsIndex) {
    GoodsData.erase(GoodsData.begin() + GoodsIndex);
    SaveGoods();
}



void Depository::PrintGoods(int GoodsIndex) {
    cout << "产品编号" << GoodsData[GoodsIndex].GoodsNum << endl
         << "产品名" << GoodsData[GoodsIndex].GoodsName << endl
         << "产地" << GoodsData[GoodsIndex].GoodsOrigin << endl
         << "产品数量" << GoodsData[GoodsIndex].GoodsQuantity << endl
         << "产品价格" << GoodsData[GoodsIndex].GoodsPrice << endl;
}



int Depository::SearchGoodsByID() {
    int ResultsIndex = -1; //该变量为搜索结果在容器内的下标，-1为缺省值，说明未查找到相关信息
    cout << "请输入产品编号" << endl;
    int SearchGoodsNum;
    cin >> SearchGoodsNum;
    for (int i = 0; i < (int) GoodsData.size(); i++) {
        if (GoodsData[i].GoodsNum == SearchGoodsNum) {
            ResultsIndex = i;
        }
    }

    if (ResultsIndex == -1) {
        cout << "没有找到符合条件的商品" << endl;
    } else {
        cout << "搜索结果如下" << endl;
        PrintGoods(ResultsIndex);
    }
    return ResultsIndex;
}



int Depository::SearchGoodsByName() {
    int ResultsIndex = -1; //该变量为搜索结果在容器内的下标，-1为缺省值，说明未查找到相关信息
    cout << "请输入产品名" << endl;
    string SearchGoodsName;
    cin >> SearchGoodsName;
    for (int i = 0; i < (int) GoodsData.size(); i++) {
        if (GoodsData[i].GoodsName == SearchGoodsName) {
            ResultsIndex = i;
        }
    }
    if (ResultsIndex == -1) {
        cout << "没有找到符合条件的商品" << endl;
    } else {
        cout << "搜索结果如下" << endl;
        PrintGoods(ResultsIndex);
    }
    return ResultsIndex;
}