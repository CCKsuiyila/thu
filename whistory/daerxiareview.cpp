//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1.�������
//2.ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3.2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

//������,����������㷨   �и����˼·  ���ǲ��ܱ�֤����ʱ   Ȼ��һ��ԭ���Ĵ����
//ͻȻ���ֻ��ǰ������������ڴ�ȽϺ�,ʡ�˺ö��鷳
//����ԭ���Ĵ���Ҳͦ���ص�  �򵥵�˼·,����45����   ˼��һ���ܲ�������һ��Ľ���.
//ͻȻ����hash,�����˰���ĸȫ�������е�,������֪���ܲ��ܼ���ʱ��.�Ǿ������԰�.
//��Ȼ  ˼����һ��   �ٶȿ�Ĳ���һ��  ���̾�50����   ÿ���ٶȶ���ԭ�����˺ü���   ���һ����������Ϊ1/6     Ҫ��˼����

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

struct box{
	char* imprint=new char[10010];     
	int num;
	int sum=0;
};

int match(char*a,char*b,int result,int n){
	for(int i=0;i<n;++i){//2:��n���ڴ�����������δ����
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
	fscanf(stdin,"%d %d",&m,&n);
	getchar();
	box data[m];
	for(int i=0;i<m;++i){
		gets(data[i].imprint);
		int length=strlen(data[i].imprint);
		for(int j=0;j<length;++j){
			data[i].sum += data[i].imprint[j] - 'a';
		}
	}
	box type[m];
	int amount=0;
	for(int i=0;i<m;++i){
		int result=-1;
		for(int j=0;j<amount;++j){//4:һֱ���0 1 2 3 4    �������� jд��i��
			if(data[i].sum==type[j].sum){
				result=match(data[i].imprint,type[j].imprint,type[j].num,n);//4:һֱ���0 1 2 3 4    �������� jд��i��
				if(result>=0){
					break;
				}
			}
		}
		if(result>=0){
			fprintf(stdout,"%d\n",result);
		}else{
			type[amount].imprint=data[i].imprint;//1:��Ч�����鸳ֵ
			type[amount].num=i;
			type[amount].sum=data[i].sum;
			amount=amount+1;
			fprintf(stdout,"%d\n",i);
		}
	}
	return 0;
}