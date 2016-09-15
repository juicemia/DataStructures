#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "BinaryTree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
	void _add(BTreeNode<T>*, T elem);
	BTreeNode<T>* _removeMin(BTreeNode<T>*);
	BTreeNode<T>* _findMin(BTreeNode<T>*);
	BTreeNode<T>* _remove(BTreeNode<T>*, T);

	public:
		BinarySearchTree(T elem) : BinaryTree<T>(elem)
		{
			//initialize root in base's constructor
		};

		~BinarySearchTree(){}

		void add(T);
		void removeMin();
		void remove(T);
};

template <typename T>
void BinarySearchTree<T>::add(T elem)
{
	_add(this->root, elem);
}

template <typename T>
void BinarySearchTree<T>::removeMin()
{
	this->root = _removeMin(this->root);
}

template <typename T>
void BinarySearchTree<T>::remove(T elem)
{
	_remove(this->root, elem);
}

/***PRIVATE HELPER FUNCTIONS***/
template <typename T>
void BinarySearchTree<T>::_add(BTreeNode<T>* n, T elem)
{
	if(elem >= n->getElement()){
		if(n->getRightChild() != NULL){
			_add(n->getRightChild(), elem);	
		}else{
			n->setRightChild(new BTreeNode<T>(elem));
		}
	}else{
		if(n->getLeftChild() != NULL){
			_add(n->getLeftChild(), elem);
		}else{
			n->setLeftChild(new BTreeNode<T>(elem));
		}
	}
}

template <typename T>
BTreeNode<T>* BinarySearchTree<T>::_removeMin(BTreeNode<T>* n)
{
	if (n->getLeftChild() == NULL) {
		return n->getRightChild();
	}

	n->setLeftChild(_removeMin(n->getLeftChild()));
	return n;
}

template <typename T>
BTreeNode<T>* BinarySearchTree<T>::_findMin(BTreeNode<T>* n)
{
	if (n->getLeftChild() == NULL) {
		return n;
	}

	return _findMin(n->getLeftChild());
}

template <typename T>
BTreeNode<T>* BinarySearchTree<T>::_remove(BTreeNode<T>* n, T elem)
{
	if (n == NULL) {
		return n;
	}
	
	if (elem > n->getElement()) {
		n->setRightChild(_remove(n->getRightChild(), elem));
		return n;
	}
	
	if (elem < n->getElement()) {
		n->setLeftChild(_remove(n->getLeftChild(), elem));
		return n;
	}

	BTreeNode<T>* left = n->getLeftChild();
	BTreeNode<T>* right = n->getRightChild();

	if (left == NULL && right == NULL) {
		return NULL;
	}

	if (left == NULL) {
		return right;
	}

	if (right == NULL) {
		return left;
	}

	// If we got here that means that our target node has two
	// branches, so we must find a suitable candidate to replace
	// it and preserve the binary search tree property.


	n = _findMin(right);


	n->setRightChild(_removeMin(n->getRightChild()));

	return n;
}

#endif //_BINARY_SEARCH_TREE_H_
