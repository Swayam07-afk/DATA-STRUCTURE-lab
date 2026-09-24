#include<stdio.h>
#include<string.h>
#define SIZE 100

#define MAX 50


int main(){
    char frontstack[SIZE][MAX];
    char backstack[SIZE][MAX];
    
    int fronttop=-1;
    int backtop=-1;

    char currentpage[SIZE]="Home";
    char newpage[SIZE];
    int choice;
 
    do{
       printf("\n");
       printf("\nBrowser navigation\n");
       printf("\n1.Visit new page");
       printf("\n2.back page");
       printf("\n3.forward page");
       printf("\n4.display");
       printf("\n5.exit");
       printf("\nEnter your choice:");
       scanf("%d",&choice);
       switch(choice){
             case 1:
                  printf("\nEnter the page name:");
                  scanf("%s",newpage);
                  backtop++; 
                  strcpy(backstack[backtop],currentpage);
                  strcpy(currentpage,newpage);

                  fronttop=-1;
                  printf("\nCurrent Page %s",currentpage);
                  break;
             case 2://backward navigation
                  if(backtop==-1){
                     printf("The broswer pages are already empty");
                  }
                  else{
                    fronttop++;
                    strcpy(frontstack[fronttop],currentpage);
                    strcpy(currentpage, backstack[backtop]);
                    backtop--;
                    printf("\nCurrent page: %s",currentpage);
                  }
                  break;

             case 3://forward navigation
                  if(fronttop==-1){
                     printf("forward is empty");
                  }
                  else{
                    
                     backtop++;
                     strcpy(backstack[backtop],currentpage);
                     strcpy(currentpage,frontstack[fronttop]);
                     fronttop--;
                     printf("\nCurrent Page %s",currentpage);
                  }
                  break;


             case 4://display
                  printf("\nCurrent page: %s",currentpage);
                  break;
                   
             case 5:
                  printf("Exiting......"); 
                  break;
       }
    }while(choice!=5);
    return 0;
}
