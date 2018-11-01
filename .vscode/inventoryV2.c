/*Computer Science II
 *Robert Wheeler
 *Dr. Lee
 *Date created: Oct 29 2018 
 *Date Updated: Oct 30 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void)
{
    char code;

    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);

        while (getchar() != '\n') /* skips to end of line */
            ;
        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'q':
            return 0;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }
}

//Finds a part in the linked list 
struct part *find_part(int number)
{
    struct part *p;

    for (p = inventory;
         p != NULL && number > p->number;
         p = p->next)
        ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

//asks the user for information about a part and adds it to the list.
void insert(void)
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL)
    {
        printf("Database is full; cannot add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
        ;
    if (cur != NULL && new_node->number == cur->number)
    {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

//Searches for a part in the list by number then prints its name and quanity. If none
//Function will print "Part not found"
void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL)
    {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
    else
        printf("Part not found.\n");
}

//Prompts you to enter a part number, then asks you to update the amount of parts on hand
void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    }
    else
        printf("Part not found.\n");
}

//Prints the list of parts, including number and quantity
void print(void)
{
    struct part *p;

    printf("Part Number   Part Name                  "
           "Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%7d       %-25s%11d\n", p->number, p->name,
               p->on_hand);
}