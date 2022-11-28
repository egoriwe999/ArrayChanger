#include<stdio.h>
#include<stdlib.h>
#include"f2.h"

int main(){
        int *arr = NULL; // первый массив
        int *arr2; // второй массив , который в итоге чистим сразу
        int n2=0; // размер второго массива
        int n=0; // размер первого массива
        int menu=1,dx,ix,d; // dx - индекс массива, ix - элемент для перемещения
        while(menu!=5){
                printf("\n-------------------------------------------------------------");
                printf("\nHello! You must select item:");
                printf("\nPress 1 to Set values of array.");
                printf("\nPress 2 to Inserting a new element into the array by index.");
                printf("\nPress 3 to Removing an array element by index.");
                printf("\nPress 4 to Do personal task.");
                printf("\nPress 5 to Finish program.");
                printf("\n-------------------------------------------------------------\n");
                scanf("%d",&menu);
                while(getchar()!='\n'){
                        printf("You have a mistake, repeat print:\n");
                        scanf("%d",&menu);
                }
                switch(menu){
                case 1:
                        if(arr!=NULL){
                                free(arr);
                        }
                        printf("Print size:\n");
                        scanf("%d/n", &n);
                        if(n<=0 || getchar()!='\n'){
                                printf("Error! Size must be > 0");;
                        }
                        else{
                                arr = input(&n);
                                output(arr,n);
                        }
                        break;

                case 2:
                        if(n!=0){
                                printf("\nPrint index:\n");
                                scanf("%d",&dx);
                                while(dx>(n-1)){
                                        printf("Error! False index,print new:\n");
                                        scanf("%d",&dx);
                                }
                                printf("Print element:\n");
                                scanf("%d",&ix);
                                printf("New array:\n");
                                insert(&arr,&n,ix,dx);
                                output(arr,n);
                        }else if(n=0 || getchar()!='n'){
                                printf("Return to 1 item!");
                        }
                        break;

                case 3:
                        if(n!=0){
                                printf("index to delete:\n");
                                scanf("%d",&dx);
                                while(n<=dx || getchar()!='\n'){
                                        printf("\nPlease repeat index:");
                                        scanf("%d",&dx);
                                }
                                remove_array(arr,&n,dx);
                                output(arr,n);
                        }
                        else if(n<=0){
                                printf("Return to 1 item");
                        }
                        break;

                case 4:
                        if(n!=0){
                                printf("Maximum sum between i and j: %i\n", sumarray(&arr,&n,&arr2,&n2));
                                printf("Old ");
                                output(arr,n);
                                printf("New ");
                                output(arr2,n2);
                                free(arr2);
                        }
                        else if(n<=0 || getchar()!='\n'){
                                printf("You should return to 1 item!");
                        }
                        break;

                case 5:

                printf("Program is finished\n");
                return 0;

                default:
                        printf("You have a mistake, repeat please:\n");
                }
        }
        free(arr);
}
// egoriwe999
                        
