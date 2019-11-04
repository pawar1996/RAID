#include<stdio.h>
#include<malloc.h>
#define DSIZE 1024
#include<stdlib.h>
int acceptdata(int);

int main(){

    int dnum ;
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

    maxIndex = ((dnum-1) * DSIZE) - 1;
    int** original = (int**) malloc (dnum * sizeof(int*));
    for(int i = 0; i < dnum; i++){
        original[i] = (int*) malloc (DSIZE * sizeof(int));
    }

    printf("\nTo stop inputting data enter -1.:\n");
int k=(dnum-1),parity=0;


//int kkk=1;
	parity=0;
    for(int i = 0; i < DSIZE; i++){
        for(int j= 0; j < (dnum); j++){
		
                
		if(j!=k){
            	scanf("%d",&intdata);
	    	parity^=intdata;//put here xor logic i dont know how to do i have done for simple 'or' 
            	if(intdata == -1){
                	printf("\n%d no. of elements entered successfully\n", cnt);
                	flag = 1;
			break;
            		}else{
			original[j][i] = intdata;
			cnt++;
			}
		}
            }
        if(flag == 1)   break; 
			original[k][i] = parity;
			k--;
			parity=0;
		if(k==-1) k=dnum-1;
		//kkk++;

        }
    if(cnt == maxIndex)    printf("\nDisk Is full\n");

    int cnt1 = 0;
    flag = 0;
    
    for(int i = 0; i < (dnum); i++){
    	printf("Disk%d\t",(i + 1));
    }
    printf("\n");
    
   
	int index;
	index=cnt+(cnt/(dnum-1));
	
    for(int i = 0; i < index; i++){
        for(int j = 0; j < dnum; j++){
		cnt1++;
    	    if(cnt1 >=(index)) {if(j==(dnum-1))flag = 1;}
            printf("%d \t ",original[j][i]);

            if(flag == 1)   break;
        }
	
        printf("\n");    
        if(flag == 1)   break;
    }

    return 0;
}



