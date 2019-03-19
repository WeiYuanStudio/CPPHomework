/**
 * @author 04181010魏源
 * @since G++ 8.2.1
 * @version 0.1
 */

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "Depository.h"
#include "Menu.h"

using namespace std;

int main() {
    system("clear");
    while (true) {
        //system("clear");
        int MenuCode = -1;
        cout
            << "--------Menu / 菜单--------" << endl
            << "1.Add Goods / 增加商品" << endl
            << "2.Delete Goods / 删除商品" << endl
            << "3.Edit Goods / 编辑商品" << endl
            << "4.Search Goods / 搜索商品" << endl
            << "5.Purchase＆Shipment / 进货＆出货" << endl
            << "6.Inquiry Purchase Or Shipment Record / 查询进出货记录" << endl
            << "7.Print List / 输出所有商品列表" << endl
            << "8.Exit / 退出" << endl
            << "9.历史记录" << endl;
        cin >> MenuCode;
        switch (MenuCode) {
            case 1:
                Menu::AddGoodsMenu(); //调用增加商品方法
                Menu::PauseMenu();
                break;
            case 2:
                Menu::DeleteGoods(); //调用删除商品方法
                Menu::PauseMenu();
                break;
            case 3:
                Menu::EditGoods(); //编辑商品方法
                Menu::PauseMenu();
                break;
            case 4:
                Menu::SearchGoods(); //调用搜索商品方法
                Menu::PauseMenu();
                break;
            case 5:
                Menu::Purchase(); //调用进货方法
                Menu::PauseMenu();
                break;
            case 7:
                Menu::PrintList();
                break;
            case 8:
                exit(0);
            case 9:
                Menu::PrintHistory();
                break;
            default:
                system("clear");
                cout << "输入了错误的菜单序号!" << endl;
        }
    if (cin.fail()){
        system("clear");
        cout << "检测到输入发生错误，请勿输入错误的数据类型，这会导致所有输入流无效！！！" << endl
             << "输入流陷入错误状态，将会使程序进入死循环!!!" << endl
             << "这段代码将清理进入fail状态的cin，由于时间和精力原因，无法让每一个输入都加入错误判断!！！" << endl;
        cin.clear();
        cin.ignore();
    }
    }
}