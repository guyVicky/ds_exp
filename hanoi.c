#include <stdio.h>
#include <stdlib.h>

typedef struct pillar
{
    int top;
    unsigned int size;
    int *arr;
} Stack;

Stack *create(unsigned int sz)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = sz;
    s->top = -1;
    s->arr = (int *)malloc(sz * sizeof(int));
    return s;
}
int isFull(Stack *a)
{
    return a->top == a->size - 1;
}

int isEmpty(Stack *a)
{
    return a->top == -1;
}

void push(Stack *a, int value)
{
    if (!isFull(a))
    {
        a->top++;
        a->arr[a->top] = value;
        printf(" %d pushed to stack\n", value);
    }
    return;
}

int pop(Stack *a)
{
    if (!isEmpty(a))
    {
        return (a->arr[a->top--]);
    }
    return 0;
}

void toh(Stack *source, Stack *temp, Stack *dest, int n)
{
    if (n == 1)
    {
        push(dest, pop(source));
        printf("Done!\n");
        return;
    }
    toh(source, dest, temp, n - 1);
    push(dest, pop(source));
    toh(source, dest, temp, n - 1);
}

//    ┌┐        ┌┐        ╔╗
//   ▓▓▓▓       ││        ║║
//  ▓▓▓▓▓▓      ││        ║║
// ▓▓▓▓▓▓▓▓     ││        ║║
//▓▓▓▓▓▓▓▓▓▓    ││        ║║
//────┴┴────────┴┴────────╨╨────

int main()
{
    printf("+------------------TOWER OF HANOI------------------+\n");
    printf("|              ┌┐        ┌┐        ╔╗              |\n");
    printf("|             ▓▓▓▓       ││        ║║              |\n");
    printf("|            ▓▓▓▓▓▓      ││        ║║              |\n");
    printf("|           ▓▓▓▓▓▓▓▓     ││        ║║              |\n");
    printf("|          ▓▓▓▓▓▓▓▓▓▓    ││        ║║              |\n");
    printf("|          ────┴┴────────┴┴────────╨╨────          |\n");
    printf("|                                                  |\n");
    printf("|                                                  |\n");
    printf("|This is the implementation of Tower of Hanoi in C |\n");
    printf("|using Stacks created by Group 2 for their DS      |\n");
    printf("|experential learning group project. This version  |\n");
    printf("|of the puzzle requires you to enter the number of |\n");
    printf("|discs you like and then following an algorithm    |\n");
    printf("|solves the puzzle with the least amount of moves  |\n");
    printf("|possible. Use the menu to start the program       |\n");
    printf("|                                                  |\n");
    printf("+--------------------------------------------------+\n");
    Stack *A = create(20);
    Stack *B = create(20);
    Stack *C = create(20); // All three pillars
    do
    {
        printf(" (1) Create a new game\n");
        printf(" (2) Generate a solution\n");
        char c;
        printf("\n Choose an option (Enter 0 to exit):");
        scanf(" %c", &c);
        switch (c)
        {
        case '0':
            printf("\n\n Exiting program...\n");
            for (int i = 0; i <= C->top; i++)
            {
                printf("%d ", C->arr[i]);
            }
            return 0;
        case '1':;
            int sz;
            printf("Enter the number of disks you want:");
            scanf("%d", &sz);
            for (int i = sz; i > 0; i--)
            {
                push(A, i);
            }
            printf("%d disks inserted into pillar A\n", sz);
            break;
        case '2':
            if (A->top > -1)
            {
                toh(A, B, C, A->top + 1);
            }
            break;
        default:
            printf(" 1 not selected\n");
            break;
        }
    } while (1);
    return 0;
}