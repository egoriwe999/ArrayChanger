#include<stdio.h>
#include<stdlib.h>

int* input(int *n, int *arr){
        int* arr = (int*)malloc((*n)*sizeof(int));
        for(size_t i = 0;i < (*n);i++){
                printf("a[%d] = ", i);
                scanf("%d", &arr[i]);
                while(getchar()!='\n'){
                        printf("\nPlease repeat:\n");
                        scanf("%d",&arr[i]);
                }
        }
        return arr;
}

void output(int *arr,int n){
    printf("Array:\n");
    for(size_t i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void remove_array(int* arr,int* n,int dx){
        for(int i=dx; i<(*n-1); i++){
                arr[i]=arr[i+1];
        }
        (*n)--;
}
void insert(int** arr, int* n,int ix, int dx){
        (*n)++;
        *arr=realloc(*arr,(*n)*sizeof(int));
        if(dx>=(*n)){
                (*arr)[(*n)-1]=ix;
        }
        else{
                for(int i=(*n)-1; i>dx; i--){
                        (*arr)[i]=(*arr)[i-1];
                }
        (*arr)[dx]=ix;
        }
}

int sumarray(int **arr,int* n,int **arr2, int* n2){
        int i=0,j=0,k,o=0;
        int sum,maxSum=0,maxi=0,maxj=0;
        *arr2 = (int*)malloc((size_t)1*sizeof(int)); // создаем первую память в массиве , которую пока не используем
        for(i=0; i<(*n); i++){
                for(j=i; j<(*n); j++){
                        sum = 0;
                        for(k=i ; k<=j; k++){
                                        sum += (*arr)[k]; // складываем значения и ищем максимальную сумму и перекладываем в maxSum
                                }
                        if(sum>maxSum){
                                maxSum = sum; // maxSum - максимальная сумма чисел
                                maxj = j; // значение i вытянутое из цикла
                                maxi=i; // значение j вытянутое из цикла
                        }
                }
        }
        (*n2)=maxj-maxi+1;
        int maxii=maxi;
        *arr2=(int*)realloc(*arr2, (size_t)(*n2)*sizeof(int));
        for(int i = maxi; i<=maxj; i++){ // записываем новый массив
                (*arr2)[o]=(*arr)[i];
                o++;
        }
        (*n)=(*n)-(*n2); // изменяем размер старого массива
        maxj++;
        for(maxii;maxii<*n;maxii++){ // перезаписываем старый массив
                (*arr)[maxii]=(*arr)[maxj];
                maxj++;
        }
        *arr=(int*)realloc(*arr,(*n)*sizeof(int));
        return maxSum;

}

// egoriwe999
