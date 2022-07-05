//Binary Search Tree
//       ROOT
//        10 -> 1 node

#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node *left; //untuk menunjuk ke anak kanannya
	struct node *right;
};

struct node *createNewNode(int value){//reservasi memori di komputer untuk data baru baru masuk ke BST 
	struct node *newNode =(struct node *)malloc (sizeof(struct node));
	newNode->value = value;
	newNode->left=NULL;
	newNode->right=NULL;
	
	return newNode;
}

//1. insert -> terapin rekursif tadi
struct node *insert (int value, struct node *root){
	//kasus pertama :posisi root NULL
	if(root == NULL){ //rootnya ketemu null kita masukin angkanya
		return createNewNode(value);
	}
	// kasus dua : value >valuenya root
	else if (value > root-> value){
		root->right =insert(value, root->right);
	}
	//kasus ketiga: value<valuenya root
	else if (value<root->value){
		root->left=insert(value, root->left);
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
	struct node *root =NULL; //ini BST nya
	
	root =insert(10,root); //10= valuenya, root=valuenya
	root =insert(5,root);
	root =insert(25,root);
	printInOrder(root);
	
	return 0;
}



//2. delete
//cari node yang mau di delete
//penghapusan 1. 0 anak; 2. 1 anak; a. anak kiri, b. anak kanan