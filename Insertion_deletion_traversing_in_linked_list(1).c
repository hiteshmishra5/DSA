#include<stdio.h>

struct node{
        int info;
        struct node *link;
        };
struct node *START = NULL;
struct node* createnode(){
        struct node *n;
        n = (struct node *)malloc(sizeof(struct node));
        return(n);
}
//Insertion from last //
void insertnode()
        {
        struct node *temp,*t;
        temp = createnode();
        printf("Enter a element:");
        scanf("%d",&temp->info);
        temp->link=NULL;

        if(START == NULL)
            START = temp;
        else{
            t = START;
            while(t->link!=NULL)
            t = t->link;
            t->link = temp;
}
}

// Delete Node //
void deletenode(){
        struct node *r;
        if(START == NULL)
            printf("list is empty");
        else{
            r = START;
            START = START->link;
            free(r);
        }
        }

//access node info value //
void viewlist(){
    struct node *t;
    if(START == NULL)
        printf("List is empty");
    else{
        t = START;
        while(t!=NULL){
            printf("%d ",t->info);
            t = t->link;
        }
    }
}

int menu(){
    int ch;
    printf("\n1.Add value of the list:");
    printf("\n2.Delete first node:");
    printf("\n3.View list");
    printf("\n4.Exit");
    printf("\nEnter your choice");
    scanf("%d",&ch);
    return(ch);
}

void main(){
    while(1){
        switch(menu()){
        case 1:
            insertnode();
            break;
        case 2:
            deletenode();
            break;
        case 3:
            viewlist();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
        }
    getch();
      }
    }
