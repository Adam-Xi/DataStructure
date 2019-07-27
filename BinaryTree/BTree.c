#include"BTree.h"
#include"Queue.h"
#include"Stack.h"


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


void BinaryTreeDestory(BTNode* root)
{
	BTNode * left, *right;
	if (root)
	{
		left = root->_left;
		right = root->_right;
		free(root);
		BinaryTreeDestory(left);
		BinaryTreeDestory(right);
	}
}


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
//�ǵݹ�������ȱ��� non-recursion ��ջʵ�֣�
//����
void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack  st;
	BTNode * cur = root;
	StackInit(&st, 100);

	while (cur || !StackIsEmpty(&st))
	{
		putchar(cur->_data);
		if (cur->_right)
		{
			StackPush(&st, cur->_right);
		}
		if (cur->_left)
		{
			cur = cur->_left;
		}
		else
		{
			cur = StackFront(&st); //����δ���
			StackPop(&st);
		}

	}
	StackDestory(&st);
}
/*
//����
void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);

	while (1)
	{
		for (; cur; cur = cur->_left)
		{
			StackPush(&st, cur);
		}

		while (1)
		{
			cur = StackFront(&st);//
			putchar(cur->_data);
			StackPop(&st);

			if (cur->_right)
			{
				cur = cur->_right;
				break;
			}

			if (StackIsEmpty(&st))
			{
				StackDestory(&st);
				return;
			}
		}
	}
}
*/

void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode * cur = root;

	Stack st;
	StackInit(&st, 100);

	while (cur || !StackIsEmpty(&st))  //��curΪ����ջΪ��ʱ
	{
		for (; cur; cur = cur->_left)
		//1����Ŀǰ�ĸ������е�����ѹջ��ֱ���Ҳ�������
		//2����Ŀǰ���Һ�����Ϊ��������������������ѹջ
		{
			StackPush(&st, cur);
		}

		if (!StackIsEmpty(&st))
		{
			cur = StackFront(&st);
			//���ӱ�����Ϻ󣬵�һ��û�����ӵĽڵ����
			//����Һ���Ϊ�գ���ʱջ�ｫ������һ��Ҫ���ʵ�
			//������Һ��ӣ���ô��ʱջ
			putchar(cur->_data);
			StackPop(&st);
			cur = cur->_right;
		}
	}
	StackDestory(&st);
}


//����
int SeqFind(BTNode * src[], size_t size, BTNode * f)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (src[i] == f)
		{
			return 1;
		}
	}
	return 0;
}
void BinaryTreePostOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root;
	BTNode * tmp = NULL;
	BTNode * visited[20];
	BTNode * printed[20];
	size_t size = 0, sizep = 0;
	int flag = 0;
	StackInit(&st, 100);
	StackPush(&st, root);
	while (cur || !StackIsEmpty(&st))
	{
		if (cur->_right)
		{
			if (!SeqFind(visited, size, cur->_right))
			{
				StackPush(&st, cur->_right);
				visited[size] = cur->_right;
				size++;
			}
		}

		if (cur->_left)
		{
			if (!SeqFind(visited, size, cur->_left))
			{
				StackPush(&st, cur->_left);
				visited[size] = cur->_left;
				size++;
				cur = cur->_left;
			}
		}
		else
		{
			if (!SeqFind(printed, sizep, cur->_right))
			{
				cur = cur->_right;
			}
		}
		if ((cur->_left == NULL || SeqFind(visited, size, cur->_left)) &&
			(cur->_right == NULL || SeqFind(visited, size, cur->_right)))
		{
			putchar(cur->_data);
			StackPop(&st);
			printed[sizep] = cur;
			sizep++;
			cur = StackFront(&st);
		}
	}
	StackDestory(&st);
}



//������ȱ���������ʵ�� ��
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


int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode * tmp;
	int leafflag = 0;

	QueueInit(&qu, root);

	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		tmp = QueueFront(&qu);
		printf("%c", tmp->_data);

		QueuePop(&qu);
		if (leafflag)
		{
			if (tmp->_left || tmp->_right)
			{
				return 0;
			}
			continue;
		}

		if (tmp->_left && tmp->_right)
		{
			QueuePush(&qu, tmp->_left);
			QueuePush(&qu, tmp->_right);
		}
		else if (tmp->_right && !tmp->_left)
		{
			return 0;
		}
		else
		{
			leafflag = 1;
			if (tmp->_left)
			{
				QueuePush(&qu, tmp->_left);
			}
		}
	}
	QueueDestory(&qu);
	return 1;
}