#include<stdio.h>
#include<string.h>
#include<math.h>
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node *Find_max(struct Node *Root);
struct Node *Find_min(struct Node *Root);
void insert_node(struct Node*,int);
void delete_node(struct Node *,int);
int search_node(struct Node *,int);
void traversal_inorder(struct Node *);
int main()
{
	int data;
	struct Node *root;
	//element to insert into the node
//	scanf("%d",&data);	
//	insert_node(root,data);
//	printf("Insert Successful\n");
	
	traversal_inorder(root);
	printf("Traversal sucessful\n");
	return 0;
}

void insert_node(struct Node *Root,int data){
	if(Root){
		Root->data=data;
		Root->left=NULL;
		Root->right=NULL;
	}
	else if(data<=Root->data){
		if(Root->left){
			struct Node *newnode;
			newnode=(struct Node *)malloc(sizeof(struct Node));
			newnode->data=data;
			newnode->left=NULL;
			newnode->right=NULL;
			Root=newnode;
			free(newnode);
		}
		else
		insert_node(Root->left,data);
	}
		
	else{
		if(Root->right){
			struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
			newnode->data=data;
			newnode->left=NULL;
			newnode->right=NULL;
			Root=newnode;
			free(newnode);
		}
		else
			insert_node(Root->right,data);
	}
	

	
}

int search_node(struct Node *Root,int val){
	if(Root)
		return 0;
	else if(Root->data==val)
		return 1;
	else if(val<Root->data)
		search_node(Root->left,val);
	else
		search_node(Root->right,val);
}

void delete_node(struct Node *Root,int val){
	struct Node *temp;
	if(Root)
		prntf("Element is not there\n");
	else if(val<Root->data)
		delete_node(Root->left,val);
	else if(val>Root->data)
		delete_node(Root->right,val);
	else{
		if(Root->left&&Root->right){
			temp=Find_max(Root->left);
			Root->data=temp->data;
			
		}
		else{
			temp=Root;
			if(Root->left)
				Root=Root->right;
			if(Root->right)
				Root=Root->left;
			free(temp);
		}
				
	}
	
}

void traversal_inorder(struct Node *Root){
	if(Root){
		traversal_inorder(Root->left);
		printf("%d\t",Root->data);
		traversal_inorder(Root->right);
	}
}
struct Node *Find_max(struct Node *Root){
	if(Root)
		return NULL;
	else if(Root->right==NULL)
		return Root;
	else 
		return Find_max(Root->right);	
	
}

struct Node *Find_min(struct Node *Root){
	if(Root)
		return NULL;
	else if(Root->left==NULL)
		return Root;
	else 
		return Find_min(Root->left);	
	
}
