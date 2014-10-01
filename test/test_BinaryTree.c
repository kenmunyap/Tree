#include "unity.h"
#include "BinaryTree.h"
#include "mock_Print.h"
#include "mock_Stack.h"
#include "Traversal.h"
void setUp(void){}

void tearDown(void){}

/**
*	 6
*	/ \
*  -   - 
*/
void test_binary_tree_with_1_node(void){
	Node root = {NULL, NULL, 6};
	Node *currentNode;
	Stack stack;
	
	printf("Starts test_binary_tree_with_1_node\n");
	stackNew_ExpectAndReturn(&stack);
	display_Expect(6);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
	
}

/**
*	10
*	/ \
*  5   - 
*/

void test_binary_tree_with_2_nodes_parent_and_left_child(void){
	Node node5 = {NULL,NULL,5};
	Node root = {&node5, NULL, 10};

	Stack stack;
	
	printf("Starts test_binary_tree_with_2_nodes_parent_and_left_child\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack,&root);
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack,&root);
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack,NULL);
	
	stackDel_Expect(&stack);
	binaryTreeTraverseInOrder(&root);
	
}

/**
*	10
*	/ \
*  -   5 
*/
void test_binary_tree_with_2_nodes_parent_and_right_child(void){
	Node node5 = {NULL,NULL,5};
 	Node root = {NULL,&node5, 13};

	Stack stack;
	
	printf("Starts test_binary_tree_with_2_nodes_parent_and_right_child\n");
	stackNew_ExpectAndReturn(&stack);
	display_Expect(13);
	stackPush_Expect(&stack,&root);
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack,&root);
	stackPop_ExpectAndReturn(&stack,NULL);
	
	stackDel_Expect(&stack);
	binaryTreeTraverseInOrder(&root);
	
}

/**
*	 8
*	/ \
*  6   12 
*/
void test_binary_tree_with_3_nodes_parent_and_left_child_and_right_child(void){
	Node leftChild = {NULL,NULL,5};
	Node rightChild = {NULL,NULL,20};
	Node root = {&leftChild,&rightChild,10};
	
	Stack stack;
	
	printf("Starts test binary tree with 3 node parent,left child and right child \n");
	stackNew_ExpectAndReturn(&stack);
	
	stackPush_Expect(&stack,&root); 
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack,&root);
	display_Expect(10);
	stackPush_Expect(&stack,&root); 
	display_Expect(20);
	stackPop_ExpectAndReturn(&stack,&root);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}



/**
*		10
*		/ \
* 	   5	
*     / \
*	 3   -
*/

void test_binary_tree_with_3_nodes_parent_and_left_child(void){
	Node node7 = {NULL,NULL,2};
	Node node6 = {&node7,NULL,3};
	Node node5 = {&node6,NULL,5};
	Node root = {&node5, NULL, 10};

	Stack stack;
	
	printf("Starts test_binary_tree_with_3_nodes_parent_and_left_child\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack,&root);
	stackPush_Expect(&stack,&node5);
	stackPush_Expect(&stack,&node6);
	display_Expect(2);
	stackPop_ExpectAndReturn(&stack,&node6);
	display_Expect(3);
	stackPop_ExpectAndReturn(&stack,&node5);
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack,&root);
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack,NULL);
	
	stackDel_Expect(&stack);
	binaryTreeTraverseInOrder(&root);
	
}

/**
*		10
*		/ \
* 	   5	
*     / \
*	 3   6
*/

void test_binary_tree_with_4_nodes_parent_and_left_trunk_and_left_child_and_right_child(void){
	Node node6 = {NULL,NULL,6};
	Node node3 = {NULL,NULL,3};
	Node node5 = {&node3,&node6,5};
	Node root = {&node5,NULL,10};
	
	Stack stack;
	
	printf("Starts test_binary_tree_with_4_nodes_parent_and_left_trunk_and_left_child_and_right_child\n");
	stackNew_ExpectAndReturn(&stack);
	
	stackPush_Expect(&stack,&root); 
	stackPush_Expect(&stack,&node5); 
	display_Expect(3);
	stackPop_ExpectAndReturn(&stack,&node5);
	display_Expect(5);
	stackPush_Expect(&stack,&node5); 
	display_Expect(6);
	stackPop_ExpectAndReturn(&stack,&node5);
	stackPop_ExpectAndReturn(&stack,&root);
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/**
*		10
*		/ \
* 	   	   5	
*         / \
*	     3   6
*/



void test_binary_tree_with_4_nodes_parent_and_right_trunk_and_left_child_and_right_child(void){
	Node node6 = {NULL,NULL,6};
	Node node3 = {NULL,NULL,3};
	Node node5 = {&node3,&node6,5};
	Node root = {NULL,&node5,10};
	
	Stack stack;
	
	printf("Starts test_binary_tree_with_4_nodes_parent_and_right_trunk_and_left_child_and_right_child\n");
	stackNew_ExpectAndReturn(&stack);
	
	display_Expect(10);
	stackPush_Expect(&stack,&root); 
	stackPush_Expect(&stack,&node5); 
	display_Expect(3);
	stackPop_ExpectAndReturn(&stack,&node5);
	display_Expect(5);
	stackPush_Expect(&stack,&node5); 
	display_Expect(6);
	stackPop_ExpectAndReturn(&stack,&node5);
	stackPop_ExpectAndReturn(&stack,&root);	
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}

/**
*		 10
*		/   \
* 	   5     7
*     / \   /  \
*	 3   6  8   9
*/

void test_binary_tree_with_7_nodes_parent_and_left_and_right_trunk_and_left_child_and_right_child(void){
	Node node8 = {NULL,NULL,8};
	Node node9 = {NULL,NULL,9};
	Node node7 = {&node8,&node9,7};
	Node node6 = {NULL,NULL,6};
	Node node3 = {NULL,NULL,3};
	Node node5 = {&node3,&node6,5};
	Node root = {&node5,&node7,10};
	
	Stack stack;
	
	printf("Starts test_binary_tree_with_7_nodes_parent_and_left_and_right_trunk_and_left_child_and_right_child\n");
	stackNew_ExpectAndReturn(&stack);
	
	stackPush_Expect(&stack,&root); 
	stackPush_Expect(&stack,&node5); 
	display_Expect(3);
	stackPop_ExpectAndReturn(&stack,&node5);
	display_Expect(5);
	stackPush_Expect(&stack,&node5); 
	display_Expect(6);
	stackPop_ExpectAndReturn(&stack,&node5);
	stackPop_ExpectAndReturn(&stack,&root);
	display_Expect(10);
	stackPush_Expect(&stack,&root);
	stackPush_Expect(&stack,&node7);
	display_Expect(8);
	stackPop_ExpectAndReturn(&stack,&node7);
	display_Expect(7);
	stackPush_Expect(&stack,&node7);
	display_Expect(9);
	stackPop_ExpectAndReturn(&stack,&node7);
	stackPop_ExpectAndReturn(&stack,&root);
	stackPop_ExpectAndReturn(&stack,NULL);
	stackDel_Expect(&stack);
	
	binaryTreeTraverseInOrder(&root);
}
