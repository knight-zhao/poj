#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	short int num=-1;
	char str[10000][10];
	char ch;
	short int tag=-1;
    short int i=0;
	short int j=0;
    short int base_count_0[10]={0};
	short int base_count_1[10]={0};
	short int base_num;
    short int arr_0[10][10]={-1};
    short int arr_1[10][10]={-1};
    short int base=0;
    short int index=-1;

    short int sorted[10];
    short int now=0;
    short int next=0;

    short int sub=0;
    short int all=0;

	scanf("%d",&num);
	getchar();
	while(i<num){
		gets(str[i]);
		tag=-1;
		next=0;
		while(tag<6){
			if(str[i][next]=='-') next++;
			else if(str[i][next]>=48 && str[i][next]<=57)
				 str[i][++tag]=str[i][next++];
		    else if(str[i][next]>=65 && str[i][next]<90){
		        if(str[i][next]=='Q') return -1;
				else if(str[i][next]>=82)
				    ch=((int)str[i][next]-66)/3;
				else
				    ch=((int)str[i][next]-65)/3;
                next++;
                switch(ch){
                	case 0 :
                           str[i][++tag]='2';
                           break;
                    case 1 :
               	           str[i][++tag]='3';
               	           break;
                   	case 2 :
                   		    str[i][++tag]='4';
                   		    break;
               		case 3 :
               			    str[i][++tag]='5';
               			    break;
     				case 4 :
     					    str[i][++tag]='6';
     					    break;
   					case 5 :
   						    str[i][++tag]='7';
   						    break;
					case 6 :
						    str[i][++tag]='8';
						    break;
					case 7 :
						    str[i][++tag]='9';
						    break;
	            }
			}
			else {
				printf("wrong character!");
				return -1;
			}
		}
        str[i][++tag]='\0';
        i++;
	}

	i=0;
	//���½׶�ʹ�õ��ǻ���������㷨�����е����ֽ�������
	// ���У��м����ʹ������������ʹ�õ����� �����Ǻ�ŵ����Ϸ�е�����
	// ͨ��������
	while(i<num){
        base_num= (int)str[i][6]-48;
        arr_0[base_num][base_count_0[base_num]]=i++;
        base_count_0[base_num]++;
	}
	//��ʱ�ӵ�����������ʼ��������
	base_num=5;
	while(base_num>=0){
        if(base_num%2==1){
            //��ʹ��1���ݴ���������֮ǰ��������й��㣨-1�����������ݳ��ִ���
            i=0;
            while(i<=9){
                j=0;
                while(j<base_count_1[i]){
                    arr_1[i][base_count_1[j]]=-1;
                    j++;
                }
                i++;
            }
            i=0;
            while(i<=9){
                base_count_1[i]=0;
                i++;
            }
            //����ɹ������֮������ʹ���ݴ��������л�������
            i=0;
            while(i<=9){
                j=0;
                while(j<base_count_0[i]){
                    index=arr_0[i][j];
                    base=(int)str[index][base_num]-48;
                    arr_1[base][base_count_1[base]]=index;
                    base_count_1[base]++;
                    j++;
                }
                i++;
            }
            //  �������洢ͳ�Ƹ����ʹ洢�±�����鶼���� ������ִ���
        }

        else{//ͬ���Ƚ��������������
            i=0;
            while(i<=9){
            j=0;
            while(j<base_count_0[i]){
                arr_0[i][base_count_0[j]]=-1;
                j++;
            }
            i++;
            }
            i=0;
            while(i<=9){
                base_count_0[i]=0;
                i++;
            }
            //ʵ�ʹ�������
            i=0;
            while(i<=9){
                j=0;
                while(j<base_count_1[i]){
                    index=arr_1[i][j];
                    base=(int)str[index][base_num]-48;
                    arr_0[base][base_count_0[base]]=index;
                    base_count_0[base]++;
                    j++;
                }
                i++;
            }
        }
        base_num--;
	}
	//���յ��������洢����0���ݴ����鵱��


    i=0;
    while(i<=9){
        j=0;
        while(j<base_count_0[i]){
            sorted[now]=arr_0[i][j];
            now++;
            j++;
        }
        i++;
    }

    now=0;
    next=1;
    while(next<=num){
        if(strcmp(str[sorted[now]],str[sorted[next]])==0) next++;
        else{
            i=0;
            while(i<3){
                printf("%c",str[sorted[now]][i]);
                i++;
            }
            printf("-");
            while(i<7){
                printf("%c",str[sorted[now]][i]);
                i++;
            }
            base=next-now;;
            j=(base==1)?1:base;
            printf(" %d\n",j);
            now=next;
        }
    }
    if(now!=num){
        i=0;
        while(i<3){
            printf("%c",str[sorted[now]][i]);
            i++;
        }
        printf("-");
        while(i<7){
            printf("%c",str[sorted[now]][i]);
            i++;
        }
        base=next-now;;
        j=(base==1)?1:base;
        printf(" %d\n",j);
    }
	return 0;
}
