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

struct node *findMin(struct node *root){
    struct node *curr = root;
    while (curr->left != NULL){
        curr = curr->left;
    }
    return curr;

}

struct node *findMax(struct node *root){
    struct node *curr = root;
    while (curr->right != NULL){
        curr = curr->right;
    }
    return curr;

}

int height(struct node*root){
    if(root == NULL){
        return -1;
    }else return root->height;

}

int getBalance(struct node *root){
    if(root == NULL){
        return 0;
    }else return height(root->left) - height(root->right);

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

	} else if (value<root->value){
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
    }

	return root;

}

struct node *removeNode(int value, struct node *root){
	
	if(root == NULL){
        return NULL;
        
    }else if(value > root->value){
        root->right = removeNode(value, root->right);

    }else if(value < root->value){
        root->left = removeNode(value, root->left);

    }else{
        if(root->left == NULL && root->right == NULL){
            struct node *temp = root;
            root = NULL;
            free(temp);
            return root; 
			
        }else if(root->right == NULL){ //1 Left Child
            struct node *temp = root;
            root = root->left;
            free(temp);

        }else if(root->left == NULL){ //1 Right Child
            struct node *temp = root;
            root = root->right;
            free(temp);

        }else{ //2 Child
            /* struct node *minValue = findMin(root->right); */
            struct node *maxValue = findMax(root->left);

            /* root->value = minValue->value;
            root->right = removeNode(root->right, minValue->value); */

            root->value = maxValue->value;
            root->left = removeNode(maxValue->value, root->left);
        }
    }

    if(root == NULL){
        return root;
    }
 
    root->height = 1 + max(height(root->left), height(root->right));
 
    int balance = getBalance(root);
	
	if(balance > 1){    
		if(getBalance(root->left) >= 0){
            return rotateRight(root);

        }else if(getBalance(root->left) < 0){
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}

	}else if(balance < -1){
        if(getBalance(root->right) <= 0){
            return rotateLeft(root);

        }else if(getBalance(root->right) > 0){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
	}

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
	
	root = insert(1, root);
	root = insert(3, root);
	root = insert(5, root);
    root = insert(10, root);
	printInOrder(root);

    printf("\n");
    root = removeNode(3, root);
    printInOrder(root);

    printf("\n");
    printf("\t%d\n", root->value);
    printf("       / \\  \n");
    printf("     %d    %d\n", root->left->value, root->right->value);
	
	return 0;
}