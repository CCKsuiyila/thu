//��Ȼ���ǵ�һ��һ����,processע�͵���Ȼû������,����˵process���־�Ȼ��Ӱ������
//������Ҳ������Լ��� while�����3��forѭ��ȫ��++A_index. ����ѭ���Ź���
//������ľͲ���һ��ʼ�ͼ����  �ǵõ��԰���  ������   ���������˹���
//������������Ժ������С�ڿ��������������ɹ���

//�������������hash��  ��ԭ���ı���һ�� �����ٶȻ����ڴ涼����ԭ���� 
//ԭ�����Ǹ����ٰ�Ļ����粻���ٰ��   ������һ�εĴ��볤�ȼ��ٲ���ԭ��(73)���(55)
//�����´�Ŷ�ԭ������ôд����   ���ڿ͹����۵Ļ�,�������ڵĴ���ö�һ��   ���һ��
//������Ȼ��    ��ͬһ�����Ӷ��ھͲ���̫������    ϵ���̫��Ͳ���

//2017-02-26 22:27:21    50��
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	//input
	int n;
	fscanf(stdin, "%d", &n);
	int* A = new int[n+10];
	int* B = new int[n+10];
	int* C = new int[n+10];
	for(int i=0;i<n;++i){
		fscanf(stdin,"%d",&(A[i]));
	}
	for(int i=0;i<n;++i){
		fscanf(stdin,"%d",&(B[i]));
	}
	for(int i=0;i<n;++i){
		fscanf(stdin,"%d",&(C[i]));
	}
	int k;
	fscanf(stdin,"%d",&k);
	
	//process
	int* hash = new int[n+10];
	int A_index=0;
	int B_index=0;
	int C_index=0;
	for(int i=0;i<(n+10);++i){
		hash[i] = 0;
	}
	int sign = 0;
	while(sign==0){
		for(;hash[(A[A_index])]!=0;++A_index);
		if(A[A_index]==k){
			cout<<"A";
			sign = 1;
		}
		hash[(A[A_index])]=8;
		++A_index;
		for(;hash[(B[B_index])]!=0;++B_index);
		if(B[B_index]==k){
			cout<<"B";
			sign = 1;
		}
		hash[(B[B_index])]=8;
		++B_index;
		for(;hash[(C[C_index])]!=0;++C_index);
		if(C[C_index]==k){
			cout<<"C";
			sign = 1;
		}
		hash[(C[C_index])]=8;
		++C_index;
	}
	return 0;
}

