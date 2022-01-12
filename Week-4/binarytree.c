
#include <stdio.h>
#include <stdlib.h>

int count=0;
struct Node
{
    int key;
    struct Node *left, *right;
};


void inorderTraversal(struct Node* root)
{
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}


void preorderTraversal(struct Node* root)
{
    if (root == NULL) {
        return;
    }

    printf("%d ", root->key);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(struct Node* root)
{

    if (root == NULL)
        return;
    postorderTraversal(root->left);

    postorderTraversal
    (root->right);
    printf("%d ", root->key);
}

struct Node *new_node(int value)
{
struct Node *tmp = (struct node *)malloc(sizeof(struct Node));
tmp->key = value;
tmp->left = tmp->right = NULL;
return tmp;
}
int max(int a,int b){
	if(a>b)
	return a;
	else
	return b;
}
void printvalue(struct Node* root,int l,int h){
	if(root==NULL){
	printf("    null");
	return;
}
	if(l==1){
	int i=0;
	for(i=0;i<h;i++)
	printf("   ");
	printf("%s  ",root->key);
	}
	else if(l >1){
		printvalue(root->left,l-1,h);
		printvalue(root->right,l-1,h);

	}
}
void display(struct Node* root,int h){
	int i,k;
	if(root == NULL)
        printf("Empty Tree");
	for(i=1;i<=h;i++){
		for(k=i;k<h;k++)
		printf("     ");
		printvalue(root,i,h);
		printf("\n");
	}
}
int height(struct Node* node){
	if(node == NULL) {
	  return 0;
	}
	else{
	int leftheight=height(node->left);
	int rightheight=height(node->right);
	return max(leftheight,rightheight)+1;
}
}

struct Node* insert_node(struct Node* node, int value) // inserting nodes!
{
if (node == NULL)
    return new_node(value);
if (value < node->key){
node->left = insert_node(node->left, value);
}
else if (value > node->key)
{
node->right = insert_node(node->right, value);
}
return node;
}

int main()
{
    int n,value,k,i=0,choice=0;
    struct Node *root_node = NULL;

    while (1)
    {
    	printf("\n 1.Insert\n 2.Height\n 3.Display\n 4.Preorder\n 5.Inorder\n 6.Postorder\n 7.Exit\n: ");
    	printf("Enter your choice");
        if(scanf("%d", &choice)==1){
        if(choice==1){
            printf("\nEnter The Number of nodes to insert into a Tree:");
            scanf("%d",&n);
            printf("\nEnter Nodes into Binary Tree:");
            scanf("%d",&value);
            root_node = insert_node(root_node, value);
            for(int i=1;i<n;i++)
            {
            scanf("%d",&value);
            insert_node(root_node, value);
            }
    		}
        else if(choice== 2){
        	int r=height(root_node);
        	printf("Height of the tree:");
			printf("%d\n",r);
        }
        else if(choice== 3) {
            	int r=height(root_node);
            	display(root_node,r);
				printf("\n");
			}
        else if(choice==4) {
        	if(root_node==NULL)
        	printf("Empty");
        	else
            {
            printf("\nThe preorder traversal is ");
            preorderTraversal(root_node);
            }
        }
        else if(choice==5) {
        	if(root_node==NULL)
        	printf("Empty");
        	else
            {
            printf("\nThe Inorder traversal is ");
            inorderTraversal(root_node);
            }
        }
        else if(choice==6)
         {
        	if(root_node==NULL)
        	printf("Empty");
        	else{
          printf("\nThe postorder traversal is ");
           postorderTraversal(root_node);
        	}
        }
        else if(choice==7)
        break;
        else
        	printf("Enter valid choice\n");
        }
        else{
        	printf("Invalid input. Enter choice between 1 to 7\n");
        	exit(0);
		}
  }
    return 0;
}



