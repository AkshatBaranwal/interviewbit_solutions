#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
struct node {
	struct node *left, *right;
	int data;
};
struct node* new(int data) {
	struct node *lol = (struct node*)malloc(sizeof(struct node));
	lol->left = lol->right = NULL;
	lol->data = data;
	return lol;
}
void insertBST(struct node *root, int data) {
	if(root->data > data) {
		if(root->left != NULL) insertBST(root->left, data);
		else root->left = new(data);
	}
	else {
		if(root->right != NULL) insertBST(root->right, data);
		else root->right = new(data);
	}
}
void inorder(struct node* root) {
	if(root != NULL) {
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
struct node* search(struct node* root, int data) {
	if(root != NULL) {
		if(root->data == data) return root;
		if(root->data > data) return search(root->left, data);
		return search(root->right, data);
	}
	else return NULL;
}
struct node* minNode(struct node* root) {
	while(root->left != NULL && root->left->left != NULL) root = root->left;
	return root;
}
struct node* maxNode(struct node* root) {
	while(root->right != NULL && root->right->right != NULL) root = root->right;
	return root;
}
void delete(struct node* root, int data) {
	if(root == NULL) return;
	if(root->data == data) {
		if(root->right != NULL) {
			struct node* lol = minNode(root->right);
			if(lol->left == NULL) {
				root->data = lol->data;
				root->right = lol->right;
			}
			else {
				root->data = lol->left->data;
				lol->left = lol->left->right;
			}
		}
		else {
			struct node* lol = maxNode(root->left);
			if(lol->right == NULL) {
				root->data = lol->data;
				root->left = lol->left;
			}
			else {
				root->data = lol->right->data;
				lol->right = lol->right->left;
			}
		}
	}
	else if(root->data > data) {
		if(root->left->data == data && root->left->left == NULL && root->left->right == NULL) root->left = NULL;
		else delete(root->left, data);
	}
	else {
		if(root->right->data == data && root->right->right == NULL && root->right->left == NULL) root->right = NULL;
		else delete(root->right, data);
	}
}
int height(struct node* root) {
	if(root != NULL) return max(height(root->left),height(root->right))+1;
	return 0;
}
int bstcheck(struct node* root) {
	if(root == NULL) return 0;
	if(bstcheck(root->left) == 0 && bstcheck(root->right) == 0) return 0;
	return 1;
}
int sumLeaf(struct node* root) {
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return root->data;
	return sumLeaf(root->left)+sumLeaf(root->right);
}
int sumTree(int n, int *a) {
	int i, b[n];
	for(i=0;i<n;++i) b[i] = a[i];
	b[n/2-1] += a[n-n%2-1];
	b[n/2-1] += (n&1)*a[n-1];
	for(i=n/2-1;i>0;--i) b[i-1] += b[2*i] + b[2*i-1];
	for(i=0;i<n;++i) printf("%d ",b[i]); printf("\n");
	for(i=0;i<n/2;++i) if(a[i]!=(b[i]/2)) return 0;
	return 1;  
}
void duplicate(struct node* root) {
	if(root != NULL) {
		while(search(root->right,root->data)!=NULL) {
			if(root->data == root->right->data) root->right = root->right->right;
			else delete(root->right,root->data);
		}
		duplicate(root->left);
		duplicate(root->right);
	}
}
int distance(struct node* root, int a, int b) {
	if(a>b) {a=a+b;b=a-b;a=a-b;}
	if(a==b) return 0;
	if(root == NULL) return 0;
	if(root->data == a) return distance(root->right,root->right->data,b)+1;
	if(root->data == b) return distance(root->left,a,root->left->data)+1;
	if(root->data < a) return distance(root->right,a,b);
	if(root->data > b) return distance(root->left,a,b);
	return distance(root,a,root->data)+distance(root,root->data,b);
}
struct node* inputBST(int n) {
	int k;
	scanf("%d",&k);
	struct node* root = new(k);
    while(--n) scanf("%d",&k), insertBST(root, k);
    return root;
}
int main() {
	int n;
    scanf("%d",&n);
    struct node* root = inputBST(n);
    
}