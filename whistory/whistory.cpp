#include<iostream>
#include<cstdio>
#include<string.h>
#include<malloc.h>
using namespace std;

struct box{
	char *imprint=(char*)malloc(10010*sizeof(char));//�޸ĵ�������1        
	int num;
};

int match(char*a,char*b,int result,int n){
	for(int i=0;i<n;i++){//2:��n���ڴ�����������δ����
		if(b[i]==a[0]){
			int num=i;
			int sign=9;
			for(int j=0,k=num;k<n;k++,j++){//3:�� ISO��for���������У���k�������Ʋ����б仯 [-fpermissive](������ΪС���ź����д�˸��ֺ�)
				if(b[k]!=a[j]){
					sign=10;
					break;
				}
			}
			if(9==sign){
				for(int j=n-num,k=0;j<n;k++,j++){
					if(b[k]!=a[j]){
						sign=10;
						break;
					}
				}
				if(9==sign){
					return result;
				}
			}
		}
	}
	return -1;
}

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	getchar();
	box data[m];
	for(int i=0;i<m;i++){
		gets(data[i].imprint);
	}
	box type[m];
	int amount=0;
	for(int i=0;i<m;i++){
		int result=-1;
		for(int j=0;j<amount;j++){//4:һֱ���0 1 2 3 4    �������� jд��i��
			result=match(data[i].imprint,type[j].imprint,type[j].num,n);//4:һֱ���0 1 2 3 4    �������� jд��i��
			if(result>=0){
				break;
			}
		}
		if(result>=0){
			printf("%d\n",result);
		}else{
			type[amount].imprint=data[i].imprint;//1:��Ч�����鸳ֵ
			type[amount].num=i;
			amount=amount+1;
			printf("%d\n",i);
		}
	}
	return 0;
}