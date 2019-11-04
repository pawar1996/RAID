#include<stdio.h>
#include<malloc.h>
#define DSIZE 1024
int acceptdata(int);

int main(){

int dnum =0;

    printf("Enter number of disks: ");
    scanf("%d",&dnum);

    if(dnum >=2)
	{ 
	acceptdata(dnum);
	}
    else{
        printf("\nInvalid number of disks.\n");
	return 0;
    }
 }



int acceptdata(int dnum){
    printf("Enter data:\n");
    int  cnt = 0, maxIndex = 0, intdata = 0, flag = 0;

    maxIndex = (dnum * DSIZE) - 1;

    int** original = (int**) malloc (dnum * sizeof(int*));
    for(int i = 0; i < dnum; i++){
        original[i] = (int*) malloc (DSIZE * sizeof(int));
    }

    printf("\nTo stop inputting data enter -1.:\n");


    for(int i = 0; i < DSIZE; i++){
        for(int j= 0; j < dnum; j++){
            scanf("%d",&intdata);

            if(intdata == -1){
                printf("\n%d no. of elements entered successfully\n", cnt);
                flag = 1;
            }
            else{
                cnt++;
                original[j][i] = intdata;                
            }
            if(flag == 1)   break;
        }
        if(flag == 1)   break;        
    }

    if(cnt == maxIndex)    printf("\nDisk Is full\n");

    int cnt1 = 0;
    flag = 0;

    for(int i = 0; i < DSIZE; i++){
        for(int j = 0; j < dnum; j++){

            cnt1++;
    
            if(cnt1 > (cnt-1)) flag = 1;
    
            printf("%d ",original[j][i]);

            if(flag == 1)   break;
        }
        printf("\n");    
        if(flag == 1)   break;
    }

    return 0;
}

