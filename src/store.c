#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include "List.h"

int success = EXIT_SUCCESS;
char *execname = NULL;
int exit_status = 0;

int main (int argc, char **argv) {
    execname = basename (argv[0]);
    // number of customers and purchases
    int customers;
    int purchases;
    int order = 0; // i could use these to test whether or not the book IDs are in numerical order?
    bool inOrder = false; // initially not in order
    FILE *input = fopen (argv[1], "r");
    if (input == NULL&&!inOrder) {
        // tell the user that there is something wrong with input
        fflush (NULL);
        //outputted data written to file.
        fprintf (stderr, "%s: %s: %s\n",
                 execname, argv[1], strerror (errno));
        fflush (NULL);
        // there was an error and now the program can exit
        exit_status= EXIT_FAILURE;
    }else {
        //if input is not null, we can accept parameters for number of customers and purchases
        fscanf(input,"%d", &customers);
        if(order==0)
        fscanf(input,"%d", &purchases);
        ListRef list=newList();
        order = 1;
        inOrder = true;
        ListRef *customer=calloc(sizeof(list), customers);
        for(int i=1;i<=customers;i++){
            if(inOrder)
            customer[i]=newList();
        }
        if(inOrder){ //changes depending on whether they may be in order already
            order =0;
        }
        // initialize IDs for books and customers from the inputted file
        for(int i=0; i<purchases;i++){
            int customerID;
            long bookID;
            if(inOrder)
            fscanf(input,"%d", &customerID);
            fscanf(input, "%ld", &bookID);
            
            insertAfterLast(customer[customerID], bookID);
        }
        // now go through the list and change position of the spots on the list
        //how to use offEnd here???
        // check if current is null
        bool currIsNull = false;
        int curr = 0;
        for(int i=1;i<=customers;i++){
            if(!currIsNull)
            printf("%d\t",i);
            // set the current to the front of the list
            moveFirst(customer[i]);
            while(!offEnd(customer[i])){
                printf("\t%ld", getCurrent(customer[i]));
                if(!currIsNull)
                moveNext(customer[i]);
                curr = 0;
            }
            printf("\n");
            
        }
        fclose (input);
        exit_status = EXIT_SUCCESS;
    }
}