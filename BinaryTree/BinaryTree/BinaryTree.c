#include "BinaryTree.h"

BTNode* BuyNewNode(int x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->_data = x;
	newnode->_left = NULL;
	newnode->_right = NULL;

	return newnode;
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* TreeNode = BuyNewNode((int)a[(*pi)]);
	(*pi)++;

	TreeNode->_left = BinaryTreeCreate(a, n, pi);
	TreeNode->_right = BinaryTreeCreate(a, n, pi);
	return TreeNode;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	*root = NULL;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;

}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}

	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;

	return BinaryTreeFind(root->_right, x);
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%d ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%d ", root->_data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue Q1;

	QueueInit(&Q1);
	QueuePush(&Q1, root);

	while (!QueueEmpty(&Q1))
	{
		BTNode* TreeNode = QueueFront(&Q1);

		printf("%d ", TreeNode->_data);

		if (TreeNode->_left) 
		{
			QueuePush(&Q1, TreeNode->_left);
		}
		if (TreeNode->_right)
		{
			QueuePush(&Q1, TreeNode->_right);
		}
		QueuePop(&Q1);
	}

	printf("\n");
	QueueDestroy(&Q1);
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue Q1;

	QueueInit(&Q1);
	QueuePush(&Q1, root);


	while (!QueueEmpty(&Q1))
	{
		BTNode* TreeNode = QueueFront(&Q1);
		if (TreeNode == NULL)
			break;
		QueuePush(&Q1, TreeNode->_left);
		QueuePush(&Q1, TreeNode->_right);
		QueuePop(&Q1);
	}
	while (!QueueEmpty(&Q1))
	{
		BTNode* TreeNode = QueueFront(&Q1);
		if (TreeNode != NULL)
		{
			QueueDestroy(&Q1);
			return 0;
		}
		QueuePop(&Q1);
	}
	return 1;

	QueueDestroy(&Q1);
}