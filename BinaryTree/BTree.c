#include"BTree.h"
#include"Queue.h"


// ͨ��ǰ�����������"ABD##E#H##CF##G##"���������� 
BTNode* BinaryTreeCreate(BTDataType* a)
{
	BTNode * cur;
	static i = 0; //static ����̬����תΪȫ��

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

//������ȱ���
//�������
void BinaryTreePrevOrder(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
//�������
void BinaryTreeInOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
//�������
void BinaryTreePostOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
}

//������ȱ���
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
