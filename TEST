//This is a string match program base on BM algothrim 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 
#include<windows.h>
char DNA[100000000];
int p;
void getdata(char *file);
int bm(char *text,char *find);
int main (int argc,const char *argv[])
{
	clock_t start1,end1,start2,end2,start3,end3;
	double t,u,v;
	start1=clock();
	printf("Please Waiting....\b");
	FILE *file1=fopen("file_1.fa","r");
	FILE *file2=fopen("file_2.fa","r");
    int m,k,w;
	getdata(file1);
	getdata(file2);
	printf("\n");
	end1=clock();
	t=(double)(end1-start1)/CLOCKS_PER_SEC;

    start2=clock();
	printf("OK, Please enter value K ,string S ：\n");
	scanf("%d\n",&k);
	char pattern[k];
    fgets(pattern,k+1,stdin);
    end2=clock();
    u=(double)(end2-start2)/CLOCKS_PER_SEC;
	
	start3=clock();
	if((m=bm(DNA,pattern))!=-1){
		printf("The Closeest String Start at %d line, %d list.\n",((m+1)/100)+1,(m+1)%100);
	}else{
		printf("ERROR!!!\n");
	}
    end3=clock();
    v=(double)(end3-start3)/CLOCKS_PER_SEC;
	
	printf("Set match use %.4f seconds.\n",t);
	printf("Enter data use %.4f seconds.\n",u);
	printf("Use match use %.4f sseconds.\n",v);
	return 0;
 } 
 void getdata(char *file)
 {
 	 char a;
	 while((a=fgetc(file))!=EOF)
	  { 
	    if(a=='A'||a=='T'||a=='C'||a=='G'){
	       DNA[p]=a;
	       p++;
	       }
      }
 }
 int bm(char *text,char *find)
 {
 	if (text == '/0' || find == '/0')  
      return -1;  
    int i, j, k;  
    int text_len = strlen(text);  
    int find_len = strlen(find);  
    if (text_len < find_len)  
        return -1;  
    int delta_1[CHAR_MAX];  
    for (i=0; i<CHAR_MAX; i++)  
        delta_1[i] = find_len;  
    for (i=0; i<find_len; i++)  
        delta_1[find[i]] = find_len - i - 1;  
    int rpr[find_len];  
    rpr[find_len-1] = find_len - 1;  
    for (i=find_len-2; i>=0; i--)  
    {  
        int len = (find_len - 1) - i;  
        //find the reoccurence of the right most (len) chars  
        for (j=find_len-2; j>=(len-1); j--)  
        {  
            if (strncmp(find+i+1, find+j-len+1, len) == 0)  
            {  
                if ((j-len) == -1 || find[i] != find[j-len])  
                {  
                    rpr[i] = j - len + 1;  
                    break;  
                }  
            }  
        }  
        //if the right most (len) chars not completely occur, we find the right  
        //substring of (len). every step, we try to find the right most (len-k)  
        //chars.  
        for (k=1; j<(len-1) && k<len; k++)  
        {  
            if (strncmp(find+i+k, find, len-k) == 0)  
            {  
                rpr[i] = 0 - k;  
                break;  
            }  
        }  
        if (j<(len-1) && k == len)  
        {  
            rpr[i] = 0 - len;  
        }  
    }  
    int delta_2[find_len];  
    for (i=0; i<find_len; i++)  
        delta_2[i] = find_len - rpr[i];  
    i = find_len - 1;  
    j = find_len - 1;  
    while (i < text_len)  
    {  
        if (text[i] == find[j])  
        {  
            i--;  
            j--;  
        }  
        else  
        {  
            if (delta_1[text[i]] > delta_2[j])  
            {  
                i += delta_1[text[i]];  
            }  
            else  
            {  
                i += delta_2[j];  
            }  
            j = find_len - 1;  
        }  
        if (j == -1)  
            return i+1;  
    }  
      
    return -1;  

 }
