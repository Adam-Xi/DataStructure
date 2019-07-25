#ifndef _BTREE_H_
#define _BTREE_H_

#include<stdio.h>
#include<Windows.h>


#define ENDTAG '#'
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树 
BTNode* BinaryTreeCreate(BTDataType* a);
void BinaryTreeDestory(BTNode** root);

void BinaryTreePrevOrder(BTNode* root); 
void BinaryTreeInOrder(BTNode* root); 
void BinaryTreePostOrder(BTNode* root);

//广度优先遍历
void BinaryTreeLevelOrder(BTNode* root);

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);


#endif /*_BTREE_H_*/