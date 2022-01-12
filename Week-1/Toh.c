#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <limits.h> 
 
// A structure to represent a stack 
struct Stack 
{ 
unsigned capacity; 
int top; 
int *array; 
}; 
 
// function to create a stack of given capacity. 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = 
        (struct Stack*) malloc(sizeof(struct Stack)); 
    stack -> capacity = capacity; 
    stack -> top = -1; 
    stack -> array = 
        (int*) malloc(stack -> capacity * sizeof(int)); 
    return stack; 
} 
 
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
return (stack->top == stack->capacity - 1); 
} 
 
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ 
return (stack->top == -1); 
} 
 
// Function to add an item to stack. It increases top by 1 
void push(struct Stack *stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack -> array[++stack -> top] = item; 
} 
 
// Function to remove an item from stack. It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack -> array[stack -> top--]; 
} 
 
//Function to show the movement of disks 
void moveDisk(char fromPeg, char toPeg, int disk) 
{ 
    printf("Move the disk %d from \'%c\' to \'%c\'\n", 
        disk, fromPeg, toPeg); 
}
 
// Function to implement legal movement between two poles 
void moveDisksBetweenTwoPoles(struct Stack *source, 
            struct Stack *destination, char s, char d) 
{ 
    int pole1TopDisk = pop(source); 
    int pole2TopDisk = pop(destination); 
 
    // When pole 1 is empty 
    if (pole1TopDisk == INT_MIN) 
    { 
        push(source, pole2TopDisk); 
        moveDisk(d, s, pole2TopDisk); 
    } 
 
    // When pole2 pole is empty 
    else if (pole2TopDisk == INT_MIN) 
    { 
        push(destination, pole1TopDisk); 
        moveDisk(s, d, pole1TopDisk); 
    } 
 
    // When top disk of pole1 > top disk of pole2 
    else if (pole1TopDisk > pole2TopDisk) 
    { 
        push(source, pole1TopDisk); 
        push(source, pole2TopDisk); 
        moveDisk(d, s, pole2TopDisk); 
    } 
 
    // When top disk of pole1 < top disk of pole2 
    else
    { 
        push(destination, pole2TopDisk); 
        push(destination, pole1TopDisk); 
        moveDisk(s, d, pole1TopDisk); 
    } 
} 
 
//Function to implement TOH puzzle 
void Toh(int num_of_disks, struct Stack 
            *source, struct Stack *auxiliary, 
            struct Stack *destination) 
{ 
    int i, total_num_of_moves; 
    char s = 'x', d = 'y', a = 'z'; 
 
    //If number of disks is even, then interchange destination pole and auxiliary pole 
    if (num_of_disks % 2 == 0) 
    { 
        char temp = d; 
        d = a; 
        a = temp; 
    } 
    total_num_of_moves = pow(2, num_of_disks) - 1; 
 
    //Larger disks will be pushed first 
    for (i = num_of_disks; i >= 1; i--) 
        push(source, i); 
 
    for (i = 1; i <= total_num_of_moves; i++) 
    { 
        if (i % 3 == 1) 
        moveDisksBetweenTwoPoles(source, destination, s, d); 
 
        else if (i % 3 == 2) 
        moveDisksBetweenTwoPoles(source, auxiliary, s, a); 
 
        else if (i % 3 == 0) 
        moveDisksBetweenTwoPoles(auxiliary, destination, a, d); 
    } 
} 
 
int main() 
{ 
    // Input: number of disks 
    unsigned num_of_disks = 3; 
 
    struct Stack *source, *destination, *auxiliary; 
 
    // Create three stacks of size 'num_of_disks' to hold the disks 
    source = createStack(num_of_disks); 
    auxiliary = createStack(num_of_disks); 
    destination = createStack(num_of_disks); 
 
    Toh(num_of_disks, source, auxiliary, destination); 
    return 0; 
}  