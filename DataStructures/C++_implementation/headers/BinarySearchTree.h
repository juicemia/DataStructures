#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "BinaryTree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
	void _add(BTreeNode<T>*, T elem);
	
	public:
		BinarySearchTree(T elem) : BinaryTree<T>(elem)
		{
			//initialize root in base's constructor
		};

		void add(T);
};

template <typename T>
void BinarySearchTree<T>::add(T elem)
{
	
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

#endif //_BINARY_SEARCH_TREE_H_
