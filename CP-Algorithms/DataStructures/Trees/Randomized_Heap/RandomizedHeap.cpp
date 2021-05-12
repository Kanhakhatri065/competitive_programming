#include <bits/stdc++.h>

using namespace std;

struct Tree {
    int value;
    Tree *l = nullptr;
    Tree *r = nullptr;

    Tree() {}
    Tree(int val) : value(val) {}
};

Tree* merge(Tree* t1, Tree* t2) {
    if(!t1 || !t2) return t1 ? t1 : t2;
    if(t2->value < t1->value) swap(t1, t2);
    if(rand() & 1) swap(t1->l, t1->r);

    t1->l = merge(t1->l, t2);
    return t1;
}

int main() {
    Tree* root = new Tree(5);
    root = merge(root, new Tree(3));
    root = merge(root, new Tree(2));
    root = merge(root, new Tree(6));

    cout << "Min of heap : " << root->value << endl;

    return 0;
}
