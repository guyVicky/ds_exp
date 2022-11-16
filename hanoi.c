#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void repeatChar(char *str, int *start, int length, char c)
{
    for (int i = *start; i < *start + length; i++)
    {
        str[i] = c;
    }
    *start += length;
}

char *toBlockStr(int val, int sz)
{
    char *out = (char *)malloc(sizeof(char) * (sz * 2 + 2));
    out[sz * 2 + 1] = 0;
    int next = 0;
    if (val == 0)
    {
        repeatChar(out, &next, sz * 2 + 1, ' ');
        out[sz] = '|';
    }
    else
    {
        repeatChar(out, &next, sz - val, ' ');
        out[next++] = '(';
        repeatChar(out, &next, val - 1, '[');
        out[next++] = '|';
        repeatChar(out, &next, val - 1, ']');
        out[next++] = ')';
        repeatChar(out, &next, sz - val, ' ');
    }
    return out;
}

void show(Stack *A, Stack *B, Stack *C, int sz)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%s", toBlockStr(0, sz));
    }
    printf("\n");
    for (int y = sz - 1; y >= 0; y--)
    {
        for (int x = 0; x < 3; x++)
        {
            switch (x)
            {
            case 0:
                printf("%s", toBlockStr(A->arr[y], sz));
                break;
            case 1:
                printf("%s", toBlockStr(B->arr[y], sz));
                break;
            case 2:
                printf("%s", toBlockStr(C->arr[y], sz));
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
}

//    ┌┐        ┌┐        ╔╗
//   ▓▓▓▓       ││        ║║
//  ▓▓▓▓▓▓      ││        ║║
// ▓▓▓▓▓▓▓▓     ││        ║║
//▓▓▓▓▓▓▓▓▓▓    ││        ║║
//────┴┴────────┴┴────────╨╨────

void toh(Stack *source, Stack *temp, Stack *dest, int n)
{
    if (n == 1)
    {
        push(dest, pop(source));
        printf("Done!\n");
        // sleep(1);
        system("clear");
        return;
    }
    toh(source, dest, temp, n - 1);
    push(dest, pop(source));
    toh(temp, source, dest, n - 1);
}

void displayTitle()
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
}

void test()
{
    Stack *X = create(20);
    Stack *Y = create(20);
    Stack *Z = create(20);
    push(X, 3);
    push(X, 2);
    push(X, 1);
    push(Y, 5);
    push(Y, 4);
    show(X, Y, Z, 5);
}

int main()
{
    test();
    scanf("%c");
    displayTitle();
    Stack *A = create(20);
    Stack *B = create(20);
    Stack *C = create(20); // All three pillars
    int fg = 0;
    int sz;
    do
    {
        printf("\n\n\n (1) Create a new game\n");
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
            printf("Enter the number of disks you want:");
            scanf("%d", &sz);
            for (int i = sz; i > 0; i--)
            {
                push(A, i);
            }
            printf("%d disks inserted into pillar A\n", sz);
            show(A, B, C, sz);
            fg = 1;
            break;
        case '2':
            if (fg)
            {
                toh(A, B, C, sz);
                displayTitle();
            }
            else
            {
                printf("No disks present in the pillars...\n");
            }
            break;
        default:
            printf("Please select a valid option\n");
            break;
        }
    } while (1);
    return 0;
}