//
// Created by weiyuan on 19-3-5.
//

#ifndef HOMEWORK3_DEPOSITORY_H
#define HOMEWORK3_DEPOSITORY_H

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

struct Goods {
    int GoodsNum;//产品编号
    string GoodsName;//产品名
    string GoodsOrigin;//产地
    int GoodsQuantity;//产品数量
    int GoodsPrice;//产品价格
};

class Depository {
public:
    Depository();
    void AddGoods(Goods NewGoods);
    void SaveGoods();
    void DeleteGoods(int GoodsIndex);
    int SearchGoodsByID();
    int SearchGoodsByName();
    void PrintGoods(int GoodsIndex);
    vector <Goods> GoodsData;
};

#endif //HOMEWORK3_DEPOSITORY_H