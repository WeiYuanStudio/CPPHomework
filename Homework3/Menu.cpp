//
// Created by weiyuan on 19-3-5.
//

#include "Menu.h"
#include "Depository.h"
#include <iostream>

using namespace std;

void Menu::AddGoodsMenu() {
    system("clear"); //清屏
    Depository MyDepository;
    cout << "----Add Goods / 增加商品----" << endl;

    cout << "请输入产品编号" << endl;
    cin.clear();

    int GoodsNum;
    cin >> GoodsNum;
    for (auto &i : MyDepository.GoodsData) {
        if (i.GoodsNum == GoodsNum) {
            cout << "查询到编号重复，请输入未被占用的编号" << endl;
            return;
        }
    }

    cout << "请输入产品名" << endl;
    string GoodsName;
    cin >> GoodsName;

    cout << "请输入产地" << endl;
    string GoodsOrigin;
    cin >> GoodsOrigin;

    cout << "请输入产品数量" << endl;
    int GoodsQuantity;
    cin >> GoodsQuantity;

    cout << "请输入产品价格" << endl;
    int GoodsPrice;
    cin >> GoodsPrice;
    system("clear");
    cout
            << "以下为编辑预览" << endl
            << "产品编号：" << GoodsNum << endl
            << "产品名:" << GoodsName << endl
            << "产地：" << GoodsOrigin << endl
            << "产品数量：" << GoodsQuantity << endl
            << "产品价格：" << GoodsPrice << endl;

    cout << "是否保存（Y/N）" << endl;

    char save = 'N';
    cin >> save;

    if (save == 'Y' || save == 'y') {
        cout << "开始保存！" << endl;
        Goods Temp;
        Temp.GoodsNum = GoodsNum;
        Temp.GoodsName = GoodsName;
        Temp.GoodsOrigin = GoodsOrigin;
        Temp.GoodsQuantity = GoodsQuantity;
        Temp.GoodsPrice = GoodsPrice;
        MyDepository.AddGoods(Temp);
        MyDepository.SaveGoods();
    }
}

void Menu::DeleteGoods() {
    system("clear");
    Depository MyDepository;
    cout << "----Delete Goods / 删除商品----" << endl
         << "请输入你需要删除的商品的编号" << endl;
    int SearchGoodsNum;
    int ResultsIndex = -1;
    cin >> SearchGoodsNum;
    for (int i = 0; i < MyDepository.GoodsData.size(); i++) {
        if (MyDepository.GoodsData[i].GoodsNum == SearchGoodsNum) {
            ResultsIndex = i;
        }
    }

    if (ResultsIndex == -1) {
        cout << "没有找到符合条件的商品" << endl;
    } else {
        cout
                << "搜索结果如下" << endl
                << "产品编号" << MyDepository.GoodsData[ResultsIndex].GoodsNum << endl
                << "产品名" << MyDepository.GoodsData[ResultsIndex].GoodsName << endl
                << "产地" << MyDepository.GoodsData[ResultsIndex].GoodsOrigin << endl
                << "产品数量" << MyDepository.GoodsData[ResultsIndex].GoodsQuantity << endl
                << "产品价格" << MyDepository.GoodsData[ResultsIndex].GoodsPrice << endl
                << "是否要删除该条数据？（Y/N）";
        char save = 'N';
        cin >> save;


        if (save == 'Y' || save == 'y') {
            cout << "开始删除！" << endl;
            MyDepository.DeleteGoods(ResultsIndex);
        }
    }
}

void Menu::EditGoods() {
    system("clear");
    Depository MyDepository;
    cout << "请输入你需要进货的商品的商品编号" << endl;
    int SearchGoodsNum;
    int ResultsIndex = -1;
    cin >> SearchGoodsNum;
    for (int i = 0; i < MyDepository.GoodsData.size(); i++) {
        if (MyDepository.GoodsData[i].GoodsNum == SearchGoodsNum) {
            ResultsIndex = i;
        }
    }

    if (ResultsIndex == -1) {
        cout << "没有找到符合条件的商品" << endl;
    } else {
        cout << "搜索结果如下" << endl;
        MyDepository.PrintGoods(ResultsIndex);
        cout << "是否要修改该条数据？（Y/N）";
        char change = 'N';
        cin >> change;

        if (change == 'Y' || change == 'y') {
            cout << "请输入需要修改的项目信息。若有不修改的信息，请输入０并回车。" << endl;

            cout << "请输入产品编号" << endl;
            int EditGoodsNum;
            cin >> EditGoodsNum;

            cout << "请输入产品名" << endl;
            string EditGoodsName;
            cin >> EditGoodsName;

            cout << "请输入产地" << endl;
            string EditGoodsOrigin;
            cin >> EditGoodsOrigin;

            cout << "请输入产品数量" << endl;
            int EditGoodsQuantity;
            cin >> EditGoodsQuantity;

            cout << "请输入产品价格" << endl;
            int EditGoodsPrice;
            cin >> EditGoodsPrice;

            if (EditGoodsNum) {
                MyDepository.GoodsData[ResultsIndex].GoodsNum = EditGoodsNum;
            }

            if (EditGoodsName[0] != '0') {
                MyDepository.GoodsData[ResultsIndex].GoodsName = EditGoodsName;
            }

            if (EditGoodsOrigin[0] != '0') {
                MyDepository.GoodsData[ResultsIndex].GoodsOrigin = EditGoodsOrigin;
            }

            if (EditGoodsQuantity) {
                MyDepository.GoodsData[ResultsIndex].GoodsQuantity = EditGoodsQuantity;
            }

            if (EditGoodsPrice) {
                MyDepository.GoodsData[ResultsIndex].GoodsPrice = EditGoodsPrice;
            }

            cout << "产品信息如下" << endl;
            MyDepository.PrintGoods(ResultsIndex);
            cout << "是否保存修改(Y/N)" << endl;
            char save = 'N';
            cin >> save;
            if (save == 'Y' || save == 'y') {
                MyDepository.SaveGoods();
            }
        }
    }
}

void Menu::SearchGoods() {
    system("clear"); //清屏
    Depository MyDepository;
    cout
            << "----Search Goods / 搜索商品----" << endl
            << "请输入序号选择搜索条件" << endl
            << "1.产品编号" << endl
            << "2.产品名" << endl;

    int MenuCode;
    cin >> MenuCode;
    switch (MenuCode) {
        case 1: {
            cout << "请输入产品编号" << endl;
            int SearchGoodsNum;
            int ResultsIndex = -1;
            cin >> SearchGoodsNum;
            for (int i = 0; i < (int) MyDepository.GoodsData.size(); i++) {
                if (MyDepository.GoodsData[i].GoodsNum == SearchGoodsNum) {
                    ResultsIndex = i;
                }
            }

            if (ResultsIndex == -1) {
                cout << "没有找到符合条件的商品" << endl;
            } else {
                cout << "搜索结果如下" << endl;
                MyDepository.PrintGoods(ResultsIndex);
            }
            break;
        }
        case 2: {
            cout << "请输入产品名" << endl;
            string SearchGoodsName;
            int ResultsIndex = -1;
            cin >> SearchGoodsName;
            for (int i = 0; i < (int) MyDepository.GoodsData.size(); i++) {
                if (MyDepository.GoodsData[i].GoodsName == SearchGoodsName) {
                    ResultsIndex = i;
                }
            }

            if (ResultsIndex == -1) {
                cout << "没有找到符合条件的商品" << endl;
            } else {
                MyDepository.PrintGoods(ResultsIndex);
            }
            break;
        }
        default:
            cout << "输入了错误的菜单序号" << endl;
    }
}


void Menu::Purchase() {
    system("clear");
    Depository MyDepository;
    cout << "----Purchase＆Shipment / 进货＆出货----" << endl;
    cout << "请输入产品编号" << endl;
    int SearchGoodsNum;
    int ResultsIndex = -1;
    cin >> SearchGoodsNum;
    for (int i = 0; i < (int) MyDepository.GoodsData.size(); i++) {
        if (MyDepository.GoodsData[i].GoodsNum == SearchGoodsNum) {
            ResultsIndex = i;
        }
    }
    if (ResultsIndex == -1) {
        cout << "没有找到符合条件的商品" << endl;
    } else {
        cout << "搜索结果如下" << endl;
        MyDepository.PrintGoods(ResultsIndex);
    }

    cout << "进货还是出货呢(进／出)(P/S)" << endl;
    char P_S = 'N';
    int P_SNum = 0;
    cin >> P_S;
    if (P_S == 'P' || P_S == 'p') {
        cout << "进货多少呢？" << endl;
        cin >> P_SNum;
    } else if (P_S == 'S' || P_S == 's') {
        cout << "出货多少呢？" << endl;
        cin >> P_SNum;
    } else {
        cout << "请输入正确的菜单序号(进／出)(P/S)" << endl;
        return;
    }

    cout << "商品:" << MyDepository.GoodsData[ResultsIndex].GoodsName << (P_S == 'P' || P_S == 'p' ? "进货" : "出货")
         << P_SNum << endl;


}


void Menu::PrintList() {
    system("clear");
    Depository MyDepository;
    cout << "数据库一共有" << MyDepository.GoodsData.size() << "条数据" << endl;
    for (auto &i : MyDepository.GoodsData) {
        cout
                << "产品编号" << i.GoodsNum << endl
                << "产品名" << i.GoodsName << endl
                << "产地" << i.GoodsOrigin << endl
                << "产品数量" << i.GoodsQuantity << endl
                << "产品价格" << i.GoodsPrice << endl << endl << endl;
    }
    Menu::PauseMenu();
}

/**
 * PauseMenu
 * 该方法用于暂停菜单
 */
void Menu::PauseMenu() {
    cout << "按回车键继续" << endl;
    cin.clear();
    cin.ignore();
    cin.get();
    system("clear");
}