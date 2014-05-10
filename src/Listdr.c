#include <stdio.h>
#include "List.h"
int main(){

    //start off with a list of longs
    long number1 = 11111;
    long number2= 22222;
    long number3 = 33333;
    long number4= 44444;
    
    //Creating of 3 lists
    ListRef ListOne=newList();
    ListRef ListTwo=newList();
    ListRef ListThree=newList();
    
    //Checks if the lists are empty and says if they are
    if(isEmpty(ListOne))
        printf("List One is empty\n");
    if(isEmpty(ListTwo))
        printf("List Two is empty\n");
    if(isEmpty(ListThree))
        printf("List Three is empty\n");
    
    //inserts longs with Lists
    insertBeforeFirst(ListOne, number3);
    insertAfterLast(ListThree, number2);
    insertBeforeCurrent(ListThree, number1);
    insertBeforeFirst(ListTwo, number2);
    insertAfterCurrent(ListOne, number1);
    insertAfterCurrent(ListTwo, number4);
    insertBeforeFirst(ListThree, number2);
    insertAfterLast(ListTwo, number3);
    insertBeforeCurrent(ListTwo, number1);
    insertBeforeFirst(ListOne, number2);
    
    
    //prints the three lists
    printList(copyList(ListOne));
    printList(copyList(ListTwo));
    printList(copyList(ListThree));
    
    // if lists are not equal, state that they are not equal
    if(!equals(ListOne, ListTwo))
        printf("ListOne and ListTwo are different. equals function works\n");
    
    movePrev(ListOne);
    printf("getFirst= %ld getLast =%ld  getCurrent= %ld\n", getFirst(ListOne), getLast(ListOne),
           getCurrent(ListOne));
    
    // if no lists are empty, it says so
   if(!isEmpty(ListOne)&&!isEmpty(ListTwo)&&!isEmpty(ListThree))
       printf("The lists are NOT empty now\n");
    
    // perform manipulation procedures on ListTwo
    moveFirst(ListTwo);
    if(atFirst(ListTwo))
        printf("-moveFirst function performed and atFirst is checked correctly\n");
    moveLast(ListTwo);
    if(atLast(ListTwo))
        printf("-moveLast function performed and atLast is checked correctly\n");
 
    // show that delete fuctions work as well as makeEmpty
    deleteFirst(ListOne);
    deleteLast(ListOne);
    makeEmpty(ListThree);
    if(isEmpty(ListThree)){
        printf("-List Three is now empty, and delete/makeEmpty functioned correctly");
    }

    
}