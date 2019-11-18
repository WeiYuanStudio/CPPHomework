#include <string>
#include <iostream>

using namespace std;

template <class T>
class HuffmanTree {
private:
    struct Node {
        T data; //数据
        int weight; //权值
        int parent, left, right; //父，左，右
        Node() { //构造
            weight = parent = left = right = 0;
        }
    };

    struct HuffmanCode {
        T data;
        string code; //保存data的哈夫曼编码
        HuffmanCode() {
            code = "";
        }
    };

    Node *hfTree; //顺序储存结构，保存Huffman树
    HuffmanCode *hfCode; //顺序储存结构，保存Huffman编码
    int size; //叶节点个数
    void selectMin(int m, int &p); //选择最小元素
public:
    HuffmanTree(int initSize);
    ~HuffmanTree() {
        delete []hfTree;
        delete []hfCode;
    }
    void createHuffmanTree(const T *d, const double *w); //创建哈夫曼树
    void huffmanEncoding(); //获取哈夫曼编码
    void printHuffmanCode(); //输出哈夫曼编码
};

template <class T>
HuffmanTree<T>::HuffmanTree(int initSize) {
    size = initSize; 
    hfTree = new Node[2*size];
    hfCode = new HuffmanCode[size];
}

template <class T>
void HuffmanTree<T>::createHuffmanTree(const T *d, const double *w) {
    int i, min1, min2; //最小数，次小数
    for(i = size; i < 2 * size; ++i) {
        hfTree[i].data = d[i - size];
        hfTree[i].weight = w[i - size];
    }
    
    for(i = size - 1; i > 0; --i) {
        selectMin(i+1, min1);
        hfTree[min1].parent = i;
        selectMin(i+1, min2);
        hfTree[min2].parent = i;

        hfTree[i].weight = hfTree[min1].weight + hfTree[min2].weight;
        hfTree[i].left = min1;
        hfTree[i].right = min2;
    }
}

template <class T>
void HuffmanTree<T>::selectMin(int m, int &p) {
    int j = m;
    while(hfTree[j].parent != 0) j++;
    for(p = j, j+=1; j < 2*size; j++) {
        if((hfTree[j].weight < hfTree[p].weight) && 0 == hfTree[j].parent) {
            p = j;
        }
    }
}

template <class T>
void HuffmanTree<T>::huffmanEncoding() {
    int f, p; //p当前处理的下标，f双亲节点下标
    for(int i = size; i < 2 * size; ++i) {
        hfCode[i - size].data = hfTree[i].data;
        p = i;
        f = hfTree[p].parent;
        while(f) {
            if (hfTree[f].left == p) //p是其双亲f的左孩子，编码+'0'
                hfCode[i - size].code = '0' + hfCode[i - size].code;
            else //+'1'
                hfCode[i- size].code = '1' + hfCode[i - size].code;
            p = f;
            f = hfTree[p].parent;
        }
    }
}

template <class T>
void HuffmanTree<T>::printHuffmanCode() {
    for (int i = 0; i < size; ++i) {
        cout << hfCode[i].data << ' ' << hfCode[i].code << endl;
    }
}
