/***********************************************************************
 *                                                                     *
 *                                                                     *
 *     Binary Search Tree.                                             *
 *     data structure that store elements hierarchically.              * 
 *     BST(binary search tree) is also known ordered binary tree.      *                                                                     *
 *     the nodes are arranged in an order.                             *
 *     All the nodes in the left sub-tree have a value less than       *                    
 *     that of the root node.                                          *
 *     All the nodes in the right sub-tree have a value greater than   *
 *     that of the root node.                                          *
 *                                                                     *
 *                                                                     *  
 ***********************************************************************/
 
 


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insertNode(struct node *p, int val);
struct node *deleteNode(struct node *p, int key);
void InorderTrav(struct node *p);
void PreorderTrav(struct node *p);
void PostorderTrav(struct node *p);
struct node *minValue(struct node *p);

int main(void)
{
    struct node *root = NULL;
    int key, val, oper;                       //key for deleteNode, val for insertNode.

    while(1){
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. In-order Traversal\n");
        printf("4. Pre-order Traversal\n");
        printf("5. Post-order Traversal\n");
        printf("6. EXIT\n");
        scanf("%d", &oper);

        switch(oper){
        case 1:
            printf("Enter a value to be added tree: ");
            scanf("%d", &val);
            root = insertNode(root, val);
            break;
        case 2:
            printf("Enter a value to be deleted in tree: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 3:
            printf("Print result of In-order traversal\n");
            InorderTrav(root);
            printf("\n");
            break;
        case 4:
            printf("Print result of pre-order traversal\n");
            PreorderTrav(root);
            printf("\n");
            break;
        case 5:
            printf("Print result of post-order traversal\n");
            PostorderTrav(root);
            printf("\n");
            break;
        case 6:
            printf("BYE~\n");
            exit(0);
        default:
            printf("Unknown command\n");
            break;
        }
    }


    return 0;
}

/**************************************************************
 *                                                            *
 *                                                            *
 *         Insert a node in tree.                             *
 *                                                            *
 *         add a new node with a given value at the           *
 *         'correct position' in the BST.                     *
 *         correct position means that the new node           *
 *         should not violate the properties of the BST.      *
 *                                                            *
 *         Insertion function requires time proportional      *
 *         to the height of the tree in the worst case.       *
 *         It takes O(log n) time to execute in average case  *
 *         and O(n) time in the worst case.                   *
 **************************************************************/
 
struct node* insertNode(struct node *p, int val)
{

    if (p == NULL){   // added node at space.
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        p = new_node;
        p -> data = val;
        p -> left = p -> right = NULL;
    }else if (val < p -> data)                 //new node value is less than current node value 
        p -> left = insertNode(p -> left, val); //
     else                                      // new node value is greater than current node value.
        p -> right = insertNode (p -> right, val);

     return p;
}

/**************************************************************
 *                                                            *
 *                                                            *
 *         Delete a node in tree.                             *
 *                                                            *
 *   3 - properties for delete node                           *
 *         1. Deleting a node that has no children            *
 *         - Simply remove this node without any issue.       *
 *                                                            *
 *         2. Deleting a node with onde child                 *
 *         -If the node is the left child of its parent,      *
 *         the node's child becomes the left child of the     *
 *         node's parent.  (left -> right...)                 *
 *                                                            *
 *         3. Deleting a node with two children               * 
 *         - replace the node's value with its inorder prede- *
 *         cessor or inorder successor.                       *
 *         The inorder predecessor or the successor can then  *
 *         be deleted using any of the above cases            *
 *                                                            *    
 *        delete function require time proportional to the    *
 *        height of the tree in the worst case                *
 *        It takes O(log n) time to execute in the average    *
 *        case and ohm(n) time in the worst case              *
 **************************************************************/

struct node* deleteNode (struct node *p, int key)
{
    if (p == NULL)
        return p;
    else if (key < p -> data)
        p -> left = deleteNode(p ->left, key);
    else if (key > p -> data)
        p -> right = deleteNode(p -> right, key);
    else {
        if (p -> left == NULL){
            struct node *temp = p -> right;
            free(p);
            return temp;
        }else if (p -> right == NULL){
            struct node *temp = p -> left;
            free(p);
            return temp;
        }

        struct node *temp = minValue(p -> right);

        p -> data = temp -> data;

        p -> right = deleteNode(p -> right, temp -> data);
    }

    return p;
}

void InorderTrav(struct node *p)
{
    if (p != NULL){
        InorderTrav (p -> left);
        printf("%d  ", p -> data);
        InorderTrav (p -> right);
    }
}
void PreorderTrav(struct node *p)
{
    if (p != NULL){
        printf("%d  ", p -> data);
        PreorderTrav(p -> left);
        PreorderTrav(p -> right);
    }
}
void PostorderTrav(struct node *p)
{
     if (p != NULL){
        PostorderTrav(p -> left);
        PostorderTrav(p -> right);
        printf("%d  ", p -> data);
     }
}
struct node *minValue(struct node *p)
{
        struct node *cur = p;

        while (cur -> left != NULL)
            cur = cur -> left;

        return cur;
}
