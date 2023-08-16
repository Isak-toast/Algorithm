/*
DFS -> preorder, inorder, postorder

BFS -> levelorder
*/
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

void preorder(vector<char>& tree, int cur, int n)
{
    if (cur >= n) // n개의 정점 (인덱스-1)까지 반복
        return;

    cout << tree[cur] << endl;
    preorder(tree, 2 * cur, n);
    preorder(tree, 2 * cur + 1, n);
}

void inorder(vector<char>& tree, int cur, int n)
{
    if (cur >= n) // n개의 정점 (인덱스-1)까지 반복
        return;

    preorder(tree, 2 * cur, n);
    cout << tree[cur] << endl;
    preorder(tree, 2 * cur + 1, n);
}

void postorder(vector<char>& tree, int cur, int n)
{
    if (cur >= n) // n개의 정점 (인덱스-1)까지 반복
        return;

    preorder(tree, 2 * cur, n);
    preorder(tree, 2 * cur + 1, n);
    cout << tree[cur] << endl;
}

void levelorder(vector<char>& tree)
{
    queue<int> que;
    que.push(1);

    int n = tree.size();
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            int v = que.front();
            que.pop();

            cout << tree[v] << endl;
            if (2 * v < n)
                que.push(2 * v);
            if (2 * v + 1 < n)
                que.push(2 * v + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<char> tree{' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    //preorder(tree, 1, tree.size());

    levelorder(tree);
    return 0;
}