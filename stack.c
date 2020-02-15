#include<stdio.h>
struct STACK{
 int data[10];
 int size;
 int header;
};

struct STACK createStack(int);
void initialize(struct STACK*);
void dummyInitialize(struct STACK*,int);
void display(struct STACK*);
void pop(struct STACK*);
void push(struct STACK*,int);
int isEmpty(struct STACK*);
int peek(struct STACK*);
int getLength(struct STACK*);
void clear(struct STACK*);

void main(){
int size=10;
 struct STACK stack=createStack(size);
 dummyInitialize(&stack,5);
 pop(&stack);
 display(&stack);
 push(&stack,111);
 display(&stack);
 printf("\nStack isEmpty : %d",isEmpty(&stack));
 printf("\nStack peek value : %d",peek(&stack));
 printf("\nStack Length : %d\n",getLength(&stack));
 clear(&stack);
 display(&stack);
 
 }


struct STACK createStack(int size){
 struct STACK  stack;
 for(int i=0;i<size;i++){
   stack.data[i]=-1;
 }
 stack.header=0;
 stack.size=size;
 return stack; 
 }

void dummyInitialize(struct STACK * stack,int dataSize){
  if(stack->size>=dataSize)
   {
     for(int i=0;i<dataSize;i++){
        stack->data[i]=i+1;
        stack->header++;
     }
   }
   else{
       printf("Stack over flow condition!!! size must be less then or equal to %d \n",stack->size);
   }
}

void display(struct STACK* stack){
   
   for(int i=0;i<stack->header;i++){
     if(stack->data[i]>0)
     printf("%d\n",stack->data[i]);
    }
  }

void pop(struct STACK* stack){
    if(stack->header>0){
       stack->data[stack->header-1]=-1;
      stack->header--;
    }
    else{
      printf("Stack under flow \n");
   }
 }

void push (struct STACK* stack,int insertData){
   if(stack->header<stack->size){
    stack->data[stack->header]=insertData;
    stack->header++;
   }
   else{
    printf("Stack overflow \n");
    }
   
 }

int isEmpty(struct STACK* stack){
      if(stack->header>0)
       {
         return 0;
       }
      else{
        return 1;
    }
 }
  

int peek(struct STACK* stack ){
     if(stack->header>0)
   return (stack->data[stack->header-1]);
  printf("Stack over flow\n");
   return -1;
   
  }

int getLength(struct STACK* stack){
   return (stack->header);
  }

void clear(struct STACK* stack){
  for(int i=0;i<stack->header;i++){
      stack->data[i]=-1;
      stack->header--;
    }
   }




