#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node{
    struct tree_node *left;
    struct tree_node *right;
    int key;
};

void insert(struct tree_node** tree, struct tree_node* new){
    if(*tree==NULL){
        *tree = new;
        (*tree)->left=NULL;
        (*tree)->right=NULL;
    }else{
        if(new->key < (*tree)->key)
            insert(&(*tree)->left,new);
        else if(new->key > (*tree)->key){
            insert(&(*tree)->right,new);
        }else{
            printf("Chiave duplicata!\n");
        }
    }
}

void in_order_view(struct tree_node *tree){
    if(tree != NULL){
        in_order_view(tree->left);
        printf("Key: %d\n",tree->key);
        in_order_view(tree->right);

    }
}

struct tree_node *nodo(int k){
    struct tree_node *n = (struct tree_node*)malloc(sizeof(struct tree_node));
    n->key = k;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct tree_node* find_by_key(struct tree_node *tree,int key){
    if(tree==NULL){
        return NULL;
    }else{
        if(key<tree->key){
            return find_by_key(tree->left,key);
        }else if(key>tree->key){
            return find_by_key(tree->right,key);
        }else{
            return tree;
        }
    }
}

int main(){
    struct tree_node *tree;
    struct tree_node *a;
    int k;
    char n;
    int kDaCercare;

    printf("Inserire la chiave root: ");
    fflush(stdin);
    scanf("%d",&k);

    tree = nodo(k);
    k=0;

    do{
        printf("Inserire chiave nodo: ");
        fflush(stdin);
        scanf("%d",&k);
        a = nodo(k);
        insert(&tree,a);
        printf("Ancora? ");
        fflush(stdin);
        scanf("%c",&n);
    }while(n!= 'n');
    in_order_view(tree);
    printf("Inserire la chiave del nodo da cercare: ");
    fflush(stdin);
    scanf("%d",&kDaCercare);
    printf("%d",find_by_key(tree,kDaCercare)->key);
    return 0;
}