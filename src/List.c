#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

// creating of the Node object
typedef struct Node {
    long data;
    struct Node* next;
    struct Node* prev;
} NodeType;

// creating a list object
typedef struct List {
    NodeType* first;
    NodeType* last;
    NodeType* current;
} ListType;

// setting of the 3 spots on the list object
ListRef newList(void){
    ListRef list = malloc(sizeof(struct List));
    assert (list != NULL);
    list->first = NULL;
    list->current = NULL;
    list->last = NULL;
    return list;
}

// not really sure how to do freeList
void freeList(ListRef* pL);

// return true if list is true and false if not
bool isEmpty(ListRef L){
    return L->first == NULL;
}

// return true if current spot on list is null and false if not
bool offEnd(ListRef L){
    return L->current == NULL;
}

// return true if current spot on list is the first spot and is not null
bool atFirst(ListRef L){
    return L->current == L->first && !offEnd(L);
}

//return true if current spot on the list is the last spot as is not null
bool atLast(ListRef L){
    return L ->current == L->last && !offEnd(L);
}

//if the list is not empty, it returns the value of the first node
long getFirst(ListRef L){
    if(!isEmpty(L))
        return L->first->data;
    
}

// if the list is not empty, it returns the value of the last node
long getLast(ListRef L){
    if(!isEmpty(L))
        return L->last->data;
}

// if list is not empty, returns the value of the current node
long getCurrent(ListRef L){
    if(!offEnd(L)){
        return L->current->data;
    }
}

// runs through the entire list and has a variable that increments while
//the list is not null
int getLength(ListRef L){
    NodeType *node = L->first;
    int length = 0;
    while(node!= NULL){
        length++;
        node = node -> next;
    }
    return length;
}

// runs through both lists at the same and checks if each node is the same
// as the other
// if the lengths of each list are not the same, it will just return false
bool equals(ListRef A, ListRef B){
    NodeType *node1 = A->first;
    NodeType *node2= B->first;
    int count =1; 
    if(getLength(A)==getLength(B)){
        while(node1->data==node2->data){
            node1= node1->next;
            node2= node2->next;
            if(node1==NULL&&node2==NULL&&count==1)
                    return true;
        } return false;
    }
    return false;
}

// sets first value of list to null, when we check if it's empty,
// it will know that it's empty because the first one is empty
void makeEmpty(ListRef L){
    L->first = NULL;
}

// sets current node to the first node
void moveFirst(ListRef L){
    if(!isEmpty(L))
        L->current = L->first;
}

// sets the current node to the last
void moveLast(ListRef L){
    if(!isEmpty(L))
        L->current = L->last;
}

//  sets current node to the previous
void movePrev(ListRef L){
    if(!offEnd(L)){
        NodeType *node = malloc(sizeof(struct Node));
        node=L->current;
        node = node->prev;
        L->current = node;
    }
}

// sets the current node to the next one
void moveNext(ListRef L){
    if(!offEnd(L)){
        NodeType *node = malloc(sizeof(struct Node));
        node = L->current;
        node = node->next;
        L->current =node;
    }
}

// inserts a node in a list before the first one.
// the new node must have a pointer previous to null
// and point the next to the previous "first node"
// the new node now points previous to the new "first node"
void insertBeforeFirst(ListRef L, long data){
    NodeType *node = malloc(sizeof(struct Node));
    node->data = data;
    if(!isEmpty(L)){
        node->prev=NULL;
        node->next = L->first;
        L->first->prev = node;
        L->first=node;
    }else{
        L->first = node;
        L->last = node;
    }
    L->current=node;
}

// inserts a node in a list after the last one.
// the new node must have a pointer next to null
// and point the next to null
// the new node now points next to the new "last node"
void insertAfterLast(ListRef L, long data){
    NodeType *node = malloc(sizeof(struct Node));
    node->data=data;
    if(!isEmpty(L)){
        node->next = NULL;
        node->prev = L->last;
        L->last->next = node;
        L->last=node;
    }else{
        L->first=node;
        L->last = node;
    }
    L->current = node;
    
}

// inserts a node in a list before the current node
// the new node must have a pointer next to current
// and point the previous to the previous of the current of the node
void insertBeforeCurrent(ListRef L, long data){
    NodeType *node = malloc(sizeof(struct Node));
    node ->data = data;
    
    if(!offEnd(L)){
        if(L->current!=L->first){
            node->next = L->current;
            node->prev = L->current->prev;
            node->prev->next=node;
            L->current->prev=node;
            L->current = node;
        }
        else insertBeforeFirst(L, data);
        
    }

}

// inserts a node in a list after the current node
// the new node must have a pointer prev to current
// and point the previous to the next of the current of the node
void insertAfterCurrent(ListRef L, long data){
    NodeType *node = malloc(sizeof(struct Node));
    node ->data = data;
    if(!offEnd(L)){
        if(L->current!=L->last){
            node->prev = L->current;
            node->next= L->current->next;
            L->current->next->prev =node;
            L->current->next = node;
            L->current = node;
        }
        else insertAfterLast(L, data);
        
    }
}

// deletes the elements in the first node
void deleteFirst(ListRef L){
    int count =0;
    if(L->first==L->last)
        makeEmpty(L);
    if(!isEmpty(L)&&count==0){
        L->first= L->first->next;
        L->first->prev= NULL;
        L->current = L->first;
    }
    
}

// deletes the elements in the last node
void deleteLast(ListRef L){
    int count=0;
    if(L->first==L->last)
        makeEmpty(L);
    if(!isEmpty(L)&&count==0){
        L->last = L->last->prev;
        L->last->next=NULL;
        L->current = L->last;
    }
    
}

// deletes the elements in the current node
void deleteCurrent(ListRef L){
    if(L->first==L->last)
        makeEmpty(L);
    if(!isEmpty(L)){
        if(L->current==L->last)
            deleteLast(L);
        else if(L->current==L->first)
            deleteFirst(L);
        else{
        L->current->next->prev=L->current->prev;
        L->current->prev->next=L->current->next;
        }

    }
}

// returns a list that has all the elements of one list given
// that are copied onto this new list
ListRef copyList(ListRef L){
    ListRef copyList=newList();
    int count =0;
    NodeType *node = malloc(sizeof(struct Node));
    if(!isEmpty(L)&&count==0){
        node = L->first;
        while(node != NULL){
            insertAfterLast(copyList,node->data);
            node= node->next;
        }
        return copyList;
    
    }
}

// prints the list in it's entirety
void printList(ListRef L){
    L->current = L->first;
    while(L->current != NULL){
        printf("%7d: %ld\n", getLength(L), getCurrent(L));
        moveNext(L);
    }
}











