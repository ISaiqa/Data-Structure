#include <iostream>

template <class T>
class TreeNode 
{
private:
    T info;
    TreeNode<T>* left;
    TreeNode<T>* right;

public:
    // Constructor
    TreeNode(T info, TreeNode<T>* left = 0, TreeNode<T>* right = 0)
    {
    	this->info = info;
    	this->left = left;
    	this->right = right;
	}

    // Method declarations
    void setInfo(T info);
    void setLeft(TreeNode<T>* left);
    void setRight(TreeNode<T>* right);
    T getInfo();
    TreeNode<T>* getLeft();
    TreeNode<T>* getRight();
    void display();
};
// Setter implementations
template <class T>
void TreeNode<T>::setInfo(T info) {
    this->info = info;
}

template <class T>
void TreeNode<T>::setLeft(TreeNode<T>* left) {
    this->left = left;
}

template <class T>
void TreeNode<T>::setRight(TreeNode<T>* right) {
    this->right = right;
}

// Getter implementations
template <class T>
T TreeNode<T>::getInfo() {
    return info;
}

template <class T>
TreeNode<T>* TreeNode<T>::getLeft() {
    return left;
}

template <class T>
TreeNode<T>* TreeNode<T>::getRight() {
    return right;
}

