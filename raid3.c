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

    
int paritycnt=0,parity=0;

    for(int i = 0; i < DSIZE; i++){
        for(int j= 0; j < (dnum-1); j++){
             if(ch == EOF){flag = 1;}
            
		if(paritycnt==0){
		parity= 0^ch;
                }
		else{parity ^= ch;}
                if ( ch != '\n'){
           	 
                	cnt++;
               		original[j][i] = ch;
			paritycnt++;             
           	 }
		else {
            		original[j][i]= '\0';
           		cnt++;
			paritycnt++;
       		 }
		ch = getc ( fptr );          
            	
		
            if(flag == 1)   break;
        }
	original[dnum-1][i] = parity;
	cnt++;
        if(flag == 1)   break;        
    }
//printf("cnt=%d\n",cnt);

     
    

    int cnt1 = 0;
    flag = 0;
    
    for(int i = 0; i < (dnum - 1); i++){
    	printf("Disk%d\t",(i + 1));
    }
    printf("Parity\n");
    
    for(int i = 0; i < (cnt+cnt/(dnum-1)); i++){
        for(int j = 0; j < dnum-1; j++){

            cnt1++;
    
            if(cnt1 > (cnt-2)) {flag = 1;}
    	    
            printf("%c\t ",original[j][i]);

            if(flag == 1)   break;
        }cnt1++;
	 printf("%d\t ",original[dnum-1][i]);
        printf("\n");    
        if(flag == 1)   break;
    }
	
 if(cnt >= maxIndex)    printf("\nDisk Is full\n");
fclose ( fptr );
    return 0;
}



