#include <bits/stdc++.h>

using namespace std;

//并查集。使用union by rank；find时进行路径压缩。
class UnionFind {
private:
    //parent[i]表示i节点的父节点
    vector<int> parent;
    //rank[i]表示以i节点为根的树的高度
    vector<int> rank;
    //记录连通分量数
    int count;

public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        count = n;

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; //进行路径压缩
            x = parent[x];
        }
        return x;
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    void unionElements(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot)
            return;

        if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else if (rank[yRoot] > rank[xRoot]) {
            parent[xRoot] = yRoot;
        } else {//相等，把一个合并到任意一个上去
            parent[xRoot] = yRoot;
            rank[yRoot]++;
        }

        count--;
    }

    //返回连通分量个数
    int getCount() {
        return count;
    }
};