//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1.�������
//2.ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3.2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

//������,֪��Ҫ���ֵ���,����������û��������ݽṹʵ�ֵľ���ϸ��   �Ͳ�������һ����
//��ԭ���Ŀ�����  Ȼ���Ż�һ�¾ͺ�
//��ԭ��C�Ķ��ĳ�C++��   ���ǻ���40��    ��ʾ�����ֵ�����̬����   �Ҹо����õľ��Ƕ�̬����(��������,��90����,��������)

#include<iostream>
#include<cstdio>
#include<string.h>
#define MAX 26
using namespace std;

class TrieNode{
public:
	TrieNode();
	TrieNode *next[MAX];
	int v;
};
TrieNode::TrieNode(){
	for(int j=0;j<MAX;++j){
		next[j]=NULL;
	}
	v=0;
}

int count=0;
//�����ֵ���
int createTrie(char*str,TrieNode *root){
	int len=strlen(str);
	TrieNode* p=root;
	for(int i=0;i<len;++i){
		int index=str[i]-'a';
		if((p->next[index])!=NULL){//�����������
			p=p->next[index];
		}else{
			TrieNode* q = new TrieNode;
			p->next[index]=q;
			p=p->next[index];
		}
	}
	p->v=p->v+1;
	if((p->v)>count){
		count=p->v;
		return count;
	}else{
		return 0;
	}
}

int main(){
	char output[9];
	TrieNode* root=new TrieNode;  //(TrieNode*)malloc(sizeof(TrieNode));//�޸���������������
	int n;
	fscanf(stdin,"%d",&n);
	getchar();
	int a;
	for(int i=0;i<n;++i){
		char* name=new char[9];
		gets(name);
		a=createTrie(name,root);
		if(a!=0){
			for(int i=0;i<=strlen(name);++i){
				output[i]=name[i];
			}	
		}
		delete [] name;   //free(name);
	}
	fprintf(stdout,"%s %d",output,count);
	return 0;
}