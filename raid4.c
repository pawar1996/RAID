#include<stdio.h>
#include<malloc.h>
#define DSIZE 10
int acceptdata(int);

int main(){

    int dnum ;
    printf("Enter number of disks: ");
    scanf("%d",&dnum);

    if(dnum >=3)
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

    maxIndex = ((dnum-1) * DSIZE) - 1;

    int** original = (int**) malloc (dnum * sizeof(int*));
    for(int i = 0; i < dnum; i++){
        original[i] = (int*) malloc (DSIZE * sizeof(int));
    }

    printf("\nTo stop inputting data enter -1.:\n");
int paritycnt=0,parity=0;

    for(int i = 0; i < DSIZE; i++){
        for(int j= 0; j < (dnum-1); j++){
            scanf("%d",&intdata);

            if(intdata == -1){
                printf("\n%d no. of elements entered successfully\n", cnt);
                flag = 1;
            }
            else {
		if(paritycnt==0){
		parity= 0^intdata;
                }
		else{parity ^= intdata;}
                cnt++;
                original[j][i] = intdata;  
		//printf("original[%d][%d]=%d\n",j,i,original[j][i]); 
		paritycnt++;             
            	}
		
            if(flag == 1)   break;
        }
	original[dnum-1][i] = parity;
	parity=0;
	cnt++;
        if(flag == 1)   break;        
    }
//printf("cnt=%d\n",cnt);

     
    if(cnt == maxIndex)    printf("\nDisk Is full\n");

    int cnt1 = 0;
    flag = 0;
    
    for(int i = 0; i < (dnum - 1); i++){
    	printf("Disk%d\t",(i + 1));
    }
    printf("Parity\n");
    
    for(int i = 0; i < (cnt+cnt/(dnum-1)); i++){
        for(int j = 0; j < dnum; j++){

            cnt1++;
    
            if(cnt1 > (cnt-2)) {flag = 1;}
    	    
            printf("%d\t ",original[j][i]);

            if(flag == 1)   break;
        }
        printf("\n");    
        if(flag == 1)   break;
    }
	

    return 0;
}



