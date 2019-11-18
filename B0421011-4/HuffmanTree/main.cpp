#include "HuffmanTree.h"

int main() {
    char d[] = "GOLESD ";
    double w[] = {4, 6, 1, 2, 1, 1, 2};
    HuffmanTree<char> tree(7);
    tree.createHuffmanTree(d, w);
    tree.huffmanEncoding();
    tree.printHuffmanCode();
    return 0;
}
