#include <stdio.h>
#include "BinaryTree.h"
#include "Stack.h"
#include "Traversal.h"


void binaryTreeTraverseInOrder(Node *root){
	Stack *stackPtr = stackNew();
	printf("created a stack\n");
	Node *currentNode = root;
	Node *saveNode = root;
	currentNode->state = ENTERED_NODE;	
while(1){
		//Initial
		if(currentNode != NULL){
			if((currentNode->left == NULL) && (currentNode->right == NULL) && (currentNode->state == ENTERED_NODE)){
					display(currentNode->data);
					currentNode->state = VISITED_RIGHT_NODE;
			}else if(currentNode->left != NULL && currentNode->state == ENTERED_NODE){
					currentNode->state = ENTERED_NODE;
					stackPush(stackPtr,currentNode);
					currentNode = currentNode->left;
					currentNode->state = ENTERED_NODE;
			}else if(currentNode->right != NULL && currentNode->state == ENTERED_NODE){
					display(currentNode->data);
					currentNode->state = VISITED_LEFT_NODE;
			}
		}
		
	
		if(currentNode != NULL){
			if(currentNode->state == VISITED_RIGHT_NODE){
					currentNode = stackPop(stackPtr);
				if(currentNode == NULL){
					break;
				}else if(currentNode->state == ENTERED_NODE){
					display(currentNode->data);
					currentNode->state = VISITED_LEFT_NODE;
				}else if(currentNode->state == VISITED_LEFT_NODE){
					currentNode->state = VISITED_RIGHT_NODE;
				}
			}	
		}
		
		if(currentNode != NULL){
			if(currentNode->state == VISITED_LEFT_NODE){
				if(currentNode->right == NULL){
					currentNode->state = VISITED_RIGHT_NODE;
				}else if(currentNode->right != NULL){
					currentNode->state = VISITED_LEFT_NODE;
					stackPush(stackPtr,currentNode);
					currentNode = currentNode->right;
					currentNode->state = ENTERED_NODE;
				}
			}
		}
		

		if(currentNode == NULL){
			break;
		}
	

}
	stackDel(stackPtr);
	printf("deleted a stack\n");
}







	 


