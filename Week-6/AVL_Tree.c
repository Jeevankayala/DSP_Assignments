
// AVL tree implementation in C

#include <stdio.h>
#include <stdlib.h>

// Create Node
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

int max(int a, int b);

// Calculate height
int height(struct Node *N){
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b){
  return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int key){
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y){
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x){
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct Node *N){
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert node
struct Node *insert(struct Node *node, int key){
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node){
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key){
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void preorder(struct Node* root)
{
    if (root != NULL)
   {
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
    }
}

void Inorder(struct Node* root)
{
    if (root != NULL)
   {
    Inorder(root->left);
    printf("%d ", root->key);
    Inorder(root->right);
    }
}

void postorder(struct Node* root)
{
    if (root != NULL)
   {
    postorder(root->left);

    postorder(root->right);
    printf("%d ", root->key);
   }
}

int tree_height(struct Node* root) {
    if (!root)
        return 0;
    else {

        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void print_level(struct Node* root, int level_no) {

    if (!root)
        return;
    if (level_no == 0) {

        printf("%d -> ", root->key);
    }
    else {

        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}

void Levelorder_Traversal(struct Node* root)
{
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
    }
    printf("\nThe Level-order traversal is ");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}

int sum=0;
void Sum_Leftsubtree(struct Node* root)
{

	if(root==NULL)
	return;
	else{
	sum+=root->key;
	Sum_Leftsubtree(root->left);
	Sum_Leftsubtree(root->right);
	}
}


int main()
{
    int n,val;
    int choice=0;

     struct Node *root = NULL;

    while (choice!=8)
    {
    	printf("\n 1.Insertion into AVL tree\n 2.Delete by value\n 3.Inorder traversal\n 4.Preorder traversal\n 5.Postorder traversal\n 6.Level-order traversal\n 7.Sum of all nodes in the left subtree\n 8.Exit\n Enter your choice : ");
        if(scanf("%d", &choice)==1){
        if(choice==1){
            printf("\nInsert into AVL Tree:");
            scanf("%d",&val);
            root = insert(root,val);
    		}
        else if(choice== 2){
            printf("\ndelete by value :");
            scanf("%d",&val);
           root = deleteNode(root, val);
        }
        else if(choice== 3) {
            printf("\nInorder : ");
            Inorder(root);
			}
        else if(choice==4) {
            printf("\npreorder : ");
            preorder(root);
        }
        else if(choice==5) {
             printf("\npostorder : ");
           postorder(root);
        }
        else if(choice==6) {Levelorder_Traversal(root); }
        else if(choice==7) { Sum_Leftsubtree(root->left);
            printf("\nSum of all nodes in the leftsubtree: %d",sum); }
        else if(choice==8) break;
        else
        	printf("choose between 1 to 8\n");
        }
        else{
        	printf("Enter integers values only\n");
        	exit(0);
		}
      }
    return 0;
}
