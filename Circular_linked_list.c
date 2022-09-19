#include<Stdio.h>
struct node{
        int data;
        struct node *next;
        };


struct node* CreateList(struct node *last);
void display(struct node *last);
struct node* AddtoEmpty(struct node *last, int value);
struct node* AddtoBeg(struct node *last, int value);
struct node* AddtoEnd(struct node *last, int value);
struct node* AddAfter(struct node *last, int value, int info);
struct node* del(struct node *last, int value);

main(){
    struct node *last = NULL;
    int choice,value,info;
    while(1){
            printf("\n1. Create List");
            printf("\n2. Display List");
            printf("\n3. Add to Empty");
            printf("\n4. Add to Beginning");
            printf("\n5. Add to End");
            printf("\n6. Add to Particular node:");
            printf("\n7. Delete node");
            printf("\n8. Exit");

            printf("\nEnter your choice: ");
            scanf("%d",&choice);
            switch(choice){
            case 1:
                last = CreateList(last);
                break;
            case 2:
                display(last);
                break;
            case 3:
                printf("Enter data for this list:");
                scanf("%d",&value);
                last = AddtoEmpty(last, value);
                break;
            case 4:
                printf("Enter data for this list:");
                scanf("%d",&value);
                last = AddtoBeg(last, value);
                break;
            case 5:
                printf("Enter data for this list:");
                scanf("%d",&value);
                last = AddtoEnd(last, value);
                break;
            case 6:
                printf("Enter the data for new list:");
                scanf("%d",&value);
                printf("Enter the data of the particular no de:");
                scanf("%d",&info);
                last = AddAfter(last, value, info);
                break;
            case 7:
                printf("Enter data for delete:");
                scanf("%d",&value);
                last = del(last, value);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice");
            }
        getch();
        }
    }

struct node *CreateList(struct node *last){
        int value,n,i;
        printf("How many element want to enter in list:");
        scanf("%d",&n);
        printf("Enter First data of the list:");
        scanf("%d",&value);
        last = AddtoEmpty(last, value);
        for(i=2;i<=n;i++){
            printf("Enter data for the element:");
            scanf("%d",&value);
            last = AddtoEnd(last, value);
        }
        return(last);
}

void display(struct node *last){
        struct node *t;
         if(last == NULL)
            printf("List is empty");
        else{
                t = last->next;
             do{
                printf("%d ",t->data);
                t = t->next;
             }while(t!=last->next);
    }
}

struct node *AddtoEmpty(struct node *last, int value){
            struct node *p;
            p = (struct node*)malloc(sizeof(struct node));
            p->data = value;
            last = p;
            last->next = last;
            return(last);
}

struct node* AddtoBeg(struct node *last, int value){
            struct node *t,*p;
            p = (struct node *)malloc(sizeof(struct node));
            p->data = value;
            if(last == NULL)
                printf("List is empty");
            else{
                p->next = last->next;
                last->next = p;
                return(last);
            }
        }

struct node *AddtoEnd(struct node *last, int value){
            struct node *p;
            p = (struct node*)malloc(sizeof(struct node));
            p->data = value;
            if(last == NULL)
                printf("List is empty");
            else{
                p->next = last->next;
                last->next = p;
                last = p;
                return (last);
            }
        }

struct node* AddAfter(struct node *last, int value, int info){
            struct node *t,*p;
            if(last == NULL){
                printf("List is empty");
                return(0);
            }
            t = last->next;
            do{
                if(t->data==info){
                        p = (struct node*)malloc(sizeof(struct node));
                        p->data = value;
                        p->next = t->next;
                        t->next = p;
                        if(t == last)
                            last = p;
                        return(last);
                }
                 t = t->next;
            }while(t != last->next);
            printf("%d is not in this list",info);
            return(last);
        }

struct node* del(struct node *last, int value){
    struct node *t,*p;

    if(last == NULL){
        printf("List is empty");
        return(last);
    }

    if(last==last->next && last->data==value){
        t = last;
        last = NULL;
        free(t);
        return(last);
    }

    if(last->next->data == value){
        t = last->next;
        last->next= t->next;
        free(t);
        return(last);
    }

    p = last->next;
    while(p->next!= last){
            if(p->next->data == value){
                t = p->next;
                p->next = t->next;
                free(t);
                return (last);
            }
            else
             p = p->next;
     }

    if(last->data == value){
        t = last;
        p->next = last->next;
        last = p;
        free(t);
        return(last);
    }
    printf("%d is not found",last);
    return(last);
}




