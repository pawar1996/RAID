#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define DSIZE 10
int acceptdata(int);

int main()
{
int dnum =0;

    printf("Enter number of disks: ");
    scanf("%d",&dnum);

    if((dnum % 2) == 0)
	{ 
	acceptdata(dnum);
	}
    else{
        printf("\nInvalid number of disks.\n");
	return 0;
    }
 }

int acceptdata(int dnum){
	int cnt=0,intdata=0,flag=0,maxIndex=0;
	printf("\nEnter data:\n ");
	int** original = (int**) malloc ((dnum / 2) * sizeof(int*));
    	for(int i = 0; i < (dnum / 2); i++)
	{
        	original[i] = (int*) malloc (DSIZE * sizeof(int));
    	}

    	int** mirror = (int**) malloc ((dnum / 2) * sizeof(int*));
	for(int i = 0; i < (dnum / 2); i++)
	{
       		 mirror[i] = (int*) malloc (DSIZE * sizeof(int));
   	 }
	printf("To stop inputting data, enter -1.:\n");
    	for(int i = 0; i < (dnum / 2); i++){
       		for(int j = 0; j < DSIZE; j++){
           		scanf("%d",&intdata);
            		if(intdata == -1)
			{
               			cnt = (i * DSIZE) + j;
               			printf("\n%d no. of elements entered successfully.\n", cnt);
               			flag = 1;
          		}
            		else{
               			original[i][j] = mirror[i][j] = intdata;                
            		}
           	 	if(flag == 1)  
				 break;
        	}
       		 if(flag == 1)  
			 break;        
    	}

	if(cnt == maxIndex)    printf("\nDisk Is full.\n");

    	int cnt1 = 0;
    	flag = 0;
	maxIndex = ((dnum / 2) * DSIZE) - 1;
	for(int i = 0; i < (dnum / 2); i++){
	 printf("Next set of disks\n");
       	 for(int j = 0; j < DSIZE; j++){
            	cnt1++;
                if(cnt1 > (cnt-1)) flag = 1;
               	printf("%d\t%d\n",original[i][j],mirror[i][j]);
            	
            	if(flag == 1)  
			 break;
        }    
        if(flag == 1)   
		break;
    }

    return 0;	

}

