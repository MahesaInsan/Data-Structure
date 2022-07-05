#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *left;
	struct node *right;
    int height;
};

struct node *createNewNode(int value){
	struct node *newNode =(struct node *)malloc(sizeof(struct node));
	newNode->value = value;
	newNode->left=NULL;
	newNode->right=NULL;
    newNode->height= 0;
	
	return newNode;
}

int max(int a, int b){
    if(a > b){
        return a;
    }else return b;

}

int height(struct node*root){
    if(root == NULL){
        return -1;
    }else return root->height;

}

struct node *rotateRight(struct node *root){
    struct node *y = root->left;
    struct node *suby = y->right;

    y->right = root;
    root->left = suby;

    root->height= 1 + max(height(root->left), height(root->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct node *rotateLeft(struct node *root){
    struct node *y = root->right;
    struct node *suby = y->left;

    y->left = root;
    root->right = suby;

    root->height= 1 + max(height(root->left), height(root->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct node *insert (int value, struct node *root){

	if(root == NULL){ 
		return createNewNode(value);

	} else if (value > root-> value){
		root->right = insert(value, root->right);

	} else if (value < root->value){
		root->left = insert(value, root->left);
	}

    root->height= 1 + max(height(root->left), height(root->right));

    //Calculate balance value
    int balance = height(root->left) - height(root->right);

    //Check whether it's heavier on the left or right
    if(balance > 1){ //Heavier on the left
        if(value < root->left->value){
            return rotateRight(root);

        }else if(value > root->left->value){
            root->left = rotateLeft(root->left);
            return rotateRight(root);

        }

    }else if(balance < -1){ //Heavier on the right
        if(value > root->right->value){
            return rotateLeft(root);

        }else if(value < root->right->value){
            root->right = rotateRight(root->right);
            return rotateLeft(root);

        }
    }else

	return root;

}

void printInOrder(struct node *root){
	if (root != NULL){
		printInOrder(root->left);
		printf("%d-", root->value);
		printInOrder(root->right);
	}
}

int main (){
	struct node *root =NULL;
	
	root = insert(10,root);
	root = insert(5,root);
	root = insert(25,root);
    root = insert(17,root);
    root = insert(21,root);
    root = insert(13,root);
    root = insert(7,root);
	printInOrder(root);
	
	return 0;
}