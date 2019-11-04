#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define DSIZE 1024
int acceptdata(int,int,char *);

int main(){

    int dnum,stripSize ;
    char filename[15];
    printf("Enter the filename to be opened \n");
    scanf("%s", filename);
    printf("Enter number of disks: ");
    scanf("%d",&dnum);
    printf("Enter stripe size: ");
    scanf("%d",&stripSize);

    if(dnum >=2)
	{ 
	acceptdata(dnum,stripSize,filename);
	}
    else{
        printf("\nInvalid number of disks.\n");
	return 0;
    }
 }


int acceptdata(int dnum,int stripSize, char * filename){
    //printf("Enter data:\n");
 	FILE *fptr;
    long int size=0;
    fptr = fopen(filename, "r");
    fseek(fptr,0,SEEK_END);
    size=ftell(fptr);
    printf("len of fptr=%ld\n",size);
    rewind(fptr);

    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    int  cnt = 0, maxIndex = 0, flag = 0;
    char ch = getc ( fptr );
    maxIndex = ((dnum-1) * DSIZE) - 1;

    char** original = (char**) malloc (dnum * sizeof(char*));
    for(int i = 0; i < dnum; i++){
        original[i] = (char*) malloc (DSIZE * sizeof(char));
    }

int k=(dnum-1),parity=0;


//int kkk=1;
	parity=0;
    for(int i = 0; i < DSIZE; i++){
        for(int j= 0; j < (dnum); j++){
		
                
		if(j!=k){
            	ch = getc ( fptr );    
	    	parity^=ch;//put here xor logic i dont know how to do i have done for simple 'or' 
            	if(ch == EOF){
                	printf("\n%d no. of elements present in file\n", cnt);
                	flag = 1;
			break;
            		}else{
			original[j][i] = ch;
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
	k=dnum-1;
    for(int i = 0; i < index; i++){
        for(int j = 0; j < dnum; j++){
		cnt1++;
    	    if(cnt1 >=(index)) {if(j==(dnum-1))flag = 1;}
		if(j!=k){
            		printf("%c \t ",original[j][i]);
		}else{
			printf("%d \t ",original[j][i]);
			k--;
			if(k==-1) k=dnum-1;}
		
            if(flag == 1)   break;
        }
	
        printf("\n");    
        if(flag == 1)   break;
    }

    return 0;
}



