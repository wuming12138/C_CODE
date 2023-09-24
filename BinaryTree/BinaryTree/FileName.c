#include "BinaryTree.h"
#include "queue.h"



int main()
{
	BTNode* N1 = BuyNewNode(1);
	BTNode* N2 = BuyNewNode(2);
	BTNode* N3 = BuyNewNode(3);
	BTNode* N4 = BuyNewNode(4);
	BTNode* N5 = BuyNewNode(5);
	BTNode* N6 = BuyNewNode(6);
	BTNode* N7 = BuyNewNode(7);
	BTNode* N8 = BuyNewNode(8);

	N1->_left = N2;
	N2->_left = N4;
	N1->_right = N3;
	N3->_left = N5;
	N3->_right = N6;

	N2->_right = N7;

	BinaryTreePrevOrder(N1);
	printf("\n");

	BinaryTreeInOrder(N1);
	printf("\n");

	BinaryTreePostOrder(N1);
	printf("\n");

	printf("%d \n", BinaryTreeSize(N1));

	printf("%d \n", BinaryTreeLeafSize(N1));

	printf("%d \n", BinaryTreeLevelKSize(N1, 3));

	BTNode* ret = BinaryTreeFind(N1, 4);
	printf("%d \n", ret->_data);


	BinaryTreeLevelOrder(N1);

	printf("%d \n", BinaryTreeComplete(N1));

	BinaryTreeDestory(&N1);


	char a[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* Create = BinaryTreeCreate(a, 17, &i);

    BinaryTreePrevOrder(Create);
	
	return 0;
}