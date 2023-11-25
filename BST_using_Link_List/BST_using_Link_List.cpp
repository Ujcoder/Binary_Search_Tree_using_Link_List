#include<iostream>
using namespace std;

struct Node {
    int data,  index;  
    Node* left, *right;
    Node(int value, int i) : data(value), index(i), left(0), right(0) {}
};

Node* insertBST(Node* root, int value, int index)
{
    if (root == 0)
        return new Node(value, index);
    if (value < root->data) 
        root->left = insertBST(root->left, value, index);
    else 
        root->right = insertBST(root->right, value, index);
    return root;
}

Node* buildBST(int A[], int n)
{
    Node* root = 0;
    for (int i = 0; i < n; ++i)
        root = insertBST(root, A[i], i);
    return root;
}

Node* searchBST(Node* root, int x) 
{
    if (root == 0 || root->data == x) 
        return root;
    if (x < root->data)
        return searchBST(root->left, x);
    else 
        return searchBST(root->right, x);
}

int main(void)
{
    int A[20], i, n, x;
    cout << "Enter Size of Array   : ";
    cin >> n;
    cout << "Enter Elements in Sorted Order  : " << endl;
    for (i = 0; i < n; i++)
        cin >> A[i];
    Node* root = buildBST(A, n);
    cout << "Enter the element to search: ";
    cin >> x;
    Node* resultNode = searchBST(root, x);
    if (resultNode == 0)
        cout << "Element not found.........!";
    else
        cout << "Element found at index " << resultNode->index << " with value : " << resultNode->data;
    return 0;
}
