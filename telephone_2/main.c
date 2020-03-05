#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	char str[100000][9]={"/0"};
	char string_temp[10000];
	char convert[5000][9]={"/0"};
int comp(const void * str1,const void * str2);
int main(){
	 int num=-1;
	 char ch;
	 short int tag=-1;
     int i=0;
	 int j=0;
	int count=0;
     int now=0;
     int next=0;
     short int dirty=0;
     short int all=0;
     short res=0;
	scanf("%d",&num);
	getchar();
	while(i<num){
        gets(string_temp);
		tag=-1;
		next=0;
		while(tag<6){
            tag++;
			if(string_temp[next]=='-') tag--;
			else if(string_temp[next]<=57) string_temp[tag]=string_temp[next];
            else{
                if(string_temp[next]<82) ch=((int)string_temp[next]-65)/3;
                else ch=((int)string_temp[next]-66)/3;
                string_temp[tag]=(char)(ch+50);
                if(tag<3) dirty=1;
            }
			next++;
		}
        string_temp[++tag]='/0';
        strncpy(str[i],string_temp,3);
        str[i][3]='-';
        strncpy(&str[i][4],&string_temp[3],4);
        if(dirty){
            strcpy(convert[count],str[i]);
            count++;
            dirty=0;
        }
        i++;
	}
	qsort(str,num,sizeof(str[0]),comp);
    qsort(convert,count,sizeof(convert[0]),comp);
    i=0;
    next=1;
    while(next<=num){
        if(strcmp(str[now],str[next])==0) next++;
        else{
            j=next-now;
            if(j>1){
                all=0;
                while(i<count){
                    res=strcmp(str[now],convert[i]);
                    if(res==-1) break;
                    all++;
                    i++;
                }
                if(all>1) continue;
                printf("%s %d\n",str[now],j);
            }

            now=next;
        }
    }
    j=next-now;
    if(j>1){
        while(i<count){
            all=0;
            res=strcmp(str[now],convert[i]);
            if(res==-1) break;
            all++;
            i++;
        }
        if(all>1) return 0;
        printf("%s %d\n",str[now],j);
    }
	return 1;
}
int comp(const void * str1,const void * str2){
    return strcmp((char *)str1,(char *)str2);
}
