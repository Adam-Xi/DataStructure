#include"BTree.h"
#include"Queue.h"


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树 
BTNode* BinaryTreeCreate(BTDataType* a)
{
	BTNode * cur;
	static i = 0; //static 将静态变量转为全局

	if (a[i] == ENDTAG)
	{
		i++;
		return NULL;
	}
	else
	{
		cur = (BTNode *)malloc(sizeof(BTNode));
		cur->_data = a[i];
		i++;
		cur->_left = BinaryTreeCreate(a);
		cur->_right = BinaryTreeCreate(a);
		return cur;
	}
}


void BinaryTreeDestory(BTNode** root);

//深度优先遍历
//先序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
//中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
//后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
}

//广度优先遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue * pq = (Queue *)malloc(sizeof(Queue));
	QueueInit(pq, root);
	QueueNode * cur;

	while (pq->_front != NULL)
	{
		if (pq->_front->_data->_left != NULL)
		{
			QueuePush(pq, pq->_front->_data->_left);
		}
		if (pq->_front->_data->_right != NULL)
		{
			QueuePush(pq, pq->_front->_data->_right);
		}
		printf("%c ", pq->_front->_data->_data);
		cur = pq->_front;
		pq->_front = pq->_front->_next;
		free(cur);
	}
}

int BinaryTreeSize(BTNode* root)
{
	static int sum = 0;
	if (root != NULL)
	{
		sum++;
		BinaryTreeSize(root->_left);
		BinaryTreeSize(root->_right);
	}
	return sum;
}

int BinaryTreeLeafSize(BTNode* root)
{
	static int count = 0;
	if (root != NULL && root->_left == NULL && root->_right == NULL)
	{
		count++;
	}
	if (root != NULL)
	{
		BinaryTreeSize(root->_left);
		BinaryTreeSize(root->_right);
	}
	return count;
}

int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
