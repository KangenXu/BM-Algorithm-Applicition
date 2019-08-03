//This is a string matching program base on BM algothrim 
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

int  COUNT;
char DNA_FRAGMENT[100000000];

void ReadDNADataFile(char *file);
int BMAlogrithm(char *text, char *find);

int main(int argc, const char *argv[])
{
    int matching_result, fragment_length;
    double read_file_time, matching_fragment_time;
    clock_t read_file_start, read_file_end, 
            matching_fragment_start, matching_fragment_end;

    // 读取DNA序列文件内容
    read_file_start = clock();
    printf("Please waiting....\b");
    FILE *file1 = fopen("file_1.fa","r");
    FILE *file2 = fopen("file_2.fa","r");    
    ReadDNADataFile(file1);
    ReadDNADataFile(file2);
    printf("\n");
    read_file_end = clock();
    read_file_time = (double)(read_file_end - read_file_start) / CLOCKS_PER_SEC;

    // 输入匹配DNA片段的字符长度和字符内容
    printf("OK, Please enter the length of fragment, and the fragment：\n");
    scanf("%d\n", &fragment_length);
    char pattern[fragment_length];
    fgets(pattern, fragment_length + 1, stdin);

    // 调用BM算法匹配片段第一次出现位置
    matching_fragment_start = clock();
    if((matching_result = BMAlogrithm(DNA_FRAGMENT, pattern)) != -1){
        printf("The Closest fragment at %d rows, and %d columns.\n", ((matching_result + 1) / 100) + 1, (matching_result + 1) % 100);
    }else{
	printf("ERROR!!!\n");
    }
    matching_fragment_end = clock();
    matching_fragment_time = (double)(matching_fragment_end - matching_fragment_start)/CLOCKS_PER_SEC;
	
    printf("Read DNA file cost %.4f seconds.\n", read_file_time);
    printf("Matching DNA fragment cost %.4f seconds.\n", matching_fragment_time);
    return 0;
} 


void ReadDNADataFile(char *file)
{
    char DNA_char;

    while((DNA_char=fgetc(file))!=EOF){ 
        if(DNA_char=='A' || DNA_char=='T' || DNA_char=='C' || DNA_char=='G'){
            DNA[COUNT] = DNA_char;
			COUNT++;
        }
    }
}
 

int BMAlogrithm(char *text, char *find)
{
    if (text == '/0' || find == '/0') 
    {
      return -1;
    }
    
    int i, j, k;  
    int text_len = strlen(text);  
    int find_len = strlen(find); 
    
    if (text_len < find_len)
　　{
        return -1;
　　}
　　
    int delta_1[CHAR_MAX];  
    
    for (i=0; i<CHAR_MAX; i++) 
    {
        delta_1[i] = find_len;  
    }
    
    for (i=0; i<find_len; i++)  
    {
        delta_1[find[i]] = find_len - i - 1;  
    }
    
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
    {
        delta_2[i] = find_len - rpr[i];   
    }   
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
