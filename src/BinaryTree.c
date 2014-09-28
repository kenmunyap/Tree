#include <stdio.h>
#include "BinaryTree.h"
#include "Stack.h"
#include "Traversal.h"



void binaryTreeTraverseInOrder(Node *root){
	Stack *stackPtr = stackNew();
	printf("created a stack\n");
	Node *currentNode = root;
	Node *saveNode = root;
	

while(1){
	if(currentNode->left == NULL && currentNode->right == NULL){
		display(currentNode->data);
		currentNode = stackPop(stackPtr);
	}else if(currentNode->left != NULL){
		currentNode->state = ENTERED_NODE;
		stackPush(stackPtr,currentNode);
		currentNode = currentNode->left;
		currentNode->state = ENTERED_NODE;
	}else if(currentNode->right != NULL){
		currentNode->state = ENTERED_NODE;
		stackPush(stackPtr,currentNode);
		currentNode = currentNode->right;
		currentNode->state = ENTERED_NODE;
	}else{
		currentNode->state = UNKNOWN_NODE_STATE;
	}



	if(currentNode != NULL){
		if(currentNode->state == ENTERED_NODE){
			if(currentNode->right == NULL && currentNode->left == NULL){
				display(currentNode->data);
				saveNode->state = VISITED_LEFT_NODE;
				currentNode = stackPop(stackPtr);
				if(currentNode->left || saveNode->left){
					currentNode->state = VISITED_LEFT_NODE;
				}else{
					currentNode->state = VISITED_RIGHT_NODE;
				}
			}else if(currentNode->left  != NULL){
					currentNode->state = ENTERED_NODE;
					stackPush(stackPtr,currentNode);
					currentNode = currentNode->left;
					saveNode = saveNode->left;
					currentNode->state = ENTERED_NODE;
			}
		}
	}
	
	
	
	if(currentNode != NULL){
		if(currentNode->state == VISITED_LEFT_NODE){
			if(currentNode->right == NULL){
				display(currentNode->data);
				currentNode = stackPop(stackPtr);
			}else if(currentNode->right != NULL){
				display(currentNode->data);
				saveNode->state = VISITED_LEFT_NODE;
				stackPush(stackPtr,currentNode);
				currentNode = currentNode->right;
				saveNode = saveNode->right;
				currentNode->state = ENTERED_NODE;
			}
		}
	}
	
	if(currentNode != NULL){
		if(currentNode->state == ENTERED_NODE){
			if(currentNode->right == NULL && currentNode->left == NULL){
				display(currentNode->data);
				saveNode->state = VISITED_LEFT_NODE;
				currentNode = stackPop(stackPtr);
				if(saveNode->left){
					currentNode->state = VISITED_LEFT_NODE;
				}else{
					currentNode->state = VISITED_RIGHT_NODE;
				}
			}
		}
	}
	
	if(currentNode != NULL){
		if(currentNode->state == VISITED_LEFT_NODE){
			if(currentNode->right == NULL){
				display(currentNode->data);
				currentNode = stackPop(stackPtr);
				currentNode->state = VISITED_LEFT_NODE;
			}else if(currentNode->right != NULL){
				display(currentNode->data);
				saveNode->state = VISITED_LEFT_NODE;
				stackPush(stackPtr,currentNode);
				currentNode = currentNode->right;
				saveNode = saveNode->right;
				currentNode->state = ENTERED_NODE;
				
			}
		}
	}
	
	if(currentNode != NULL){
		if(currentNode->state == VISITED_LEFT_NODE){
			if(currentNode->right == NULL){
				display(currentNode->data);
				currentNode = stackPop(stackPtr);	
			}else if(currentNode->right != NULL){
				display(currentNode->data);
				saveNode->state = VISITED_LEFT_NODE;
				stackPush(stackPtr,currentNode);
				currentNode = currentNode->right;
				saveNode = saveNode->right;
				currentNode->state = ENTERED_NODE;
				
			}
		}
	}

		
	if(currentNode != NULL){
		if(currentNode->state == VISITED_RIGHT_NODE){
			if(currentNode->left == NULL){
				display(currentNode->data);
				currentNode = stackPop(stackPtr);
			}
			if(saveNode->state == VISITED_LEFT_NODE && root->data == currentNode->data){
				currentNode = stackPop(stackPtr);
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



	 


