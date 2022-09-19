#include<stdio.h>

struct node {
        struct node *prev;
        int info;
        struct node *next;
        };

void insertstart(struct node **s, int data);
void insertlast(struct node **s, int data);
void insertmiddle(struct node **s,struct node *, int data);
struct node* find(struct node **s, int data);
int deletefirst(struct node **s);
int deletelast(struct node **s);
int deleteintermediate(struct node **s,struct node *ptr);
void ViewList(struct node **s);
int GetFirst(struct node **s);
int GetLast(struct node **s);

main(){
    struct node *ptr;
    struct node *start = NULL;
    insertstart(&start,10);
    insertlast(&start,20);
    insertlast(&start,30);
    insertlast(&start,40);
    printf("First Value is %d\n",GetFirst(&start));
    printf("Last value is %d\n",GetLast(&start));
    insertafter(&start,find(&start,30),56);
    printf("\nTotal value After insertafter 30 is :");
    ViewList(&start);
    printf("\nTotal value After deleting 20 is :");
    deleteintermediate(&start, find(&start,20));
    ViewList(&start);
    deletefirst(&start);
    deletelast(&start);
    printf("\nAfter deleting first value and last value total list value is :");
    ViewList(&start);


}


int GetFirst(struct node **s){
        struct node *t;
        if(*s == NULL){
            printf("List is empty");
            return(-1);
        }
        else{
            return((*s)->info);
        }
}

int GetLast(struct node **s){
        struct node *t;
        if(*s == NULL){
            printf("List is empty");
            return(-1);
        }
        else{
            t = *s;
            while(t->next!=NULL)
                t= t->next;
                return(t->info);
            }
    }

void ViewList(struct node **s){
    struct node *t;
     if(*s == NULL)
        printf("List is empty");
     else{
        t=*s;
        while(t!=NULL){
            printf("%d ",t->info);
            t = t->next;
        }
     }
}
int deleteintermediate(struct node **s,struct node *ptr){



    if(*s == NULL){
        return(0);
    }
     if(ptr->prev == NULL){
        *s=ptr->next;
        free(ptr);
        return(1);
    }
    if(ptr->next == NULL){
        ptr->prev->next = ptr->next;
        free(ptr);
        return(1);
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return(1);
    }
int deletelast(struct node **s){
        struct node *t;
        if(*s == NULL){
            return(0);
        }
        else{
            t = *s;
            while(t->next!=NULL)
                t=t->next;
                if((*s)->next == NULL)
                    *s = NULL;
                else{
                     t->prev->next = NULL;
                     free(t);
                     return(1);
                }

            }
}

int deletefirst(struct node **s){
        struct node *t;
        if(*s == NULL)
            return(0);
        else{
            t = *s;
            *s = (*s)->next;
            (*s)->prev = NULL;
            free(t);
            return(1);
        }
}

struct node* find(struct node **s, int data){
        struct node *t;
        if(*s == NULL)
            return(NULL);
        else{
            t = *s;
            while(t!=NULL){
                if(t->info == data)
                    return(t);
                t = t->next;
            }
            return(NULL);
        }
}

void insertafter(struct node **s, struct node *ptr,int data){
    struct node *p;
    if(ptr == NULL){
        printf("Invalid Insertion");
    }

    p = (struct node*)malloc(sizeof(struct node));
    p->info = data;
    p->prev = ptr;
    p->next = ptr->next;
    if(ptr->next!=NULL)
        ptr->next->prev =p;
        ptr->next = p;
    }

void insertlast(struct node **s, int data){
            struct node *p,*t;
            p = (struct node *)malloc(sizeof(struct node));
            p->info = data;
            p->next = NULL;
            if(*s == NULL){
                p->prev = NULL;
                p->next = NULL;
                *s = p;
            }
            else{
                t=*s;
                while(t->next!=NULL)
                    t = t->next;
                    p->prev = t;
                    t->next = p;
            }
}

void insertstart(struct node **s, int data){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info=data;
    p->prev = NULL;

    if(*s==NULL){
        p->next = NULL;
        *s = p;
    }
    else{
        p->next=*s;
    }
}








