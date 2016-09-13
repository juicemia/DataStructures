#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "BinaryTree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
	void _add(BTreeNode<T>*, T elem);
	void _removeMin(BTreeNode<T>*);

	public:
		BinarySearchTree(T elem) : BinaryTree<T>(elem)
		{
			//initialize root in base's constructor
		};

		~BinarySearchTree(){}

		void add(T);
		void removeMin();
};

template <typename T>
void BinarySearchTree<T>::add(T elem)
{
	_add(this->root, elem);
}

template <typename T>
void BinarySearchTree<T>::removeMin()
{
	_removeMin(this->root);
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
void BinarySearchTree<T>::_removeMin(BTreeNode<T>* n)
{
	BTreeNode<T>* left = n->getLeftChild();

	if (left->getLeftChild() == NULL && left->getRightChild() == NULL) {
		n->setLeftChild(n->getRightChild());
		n->setRightChild(NULL);

		return;
	}

	_removeMin(left);
}

#endif //_BINARY_SEARCH_TREE_H_
