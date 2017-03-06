//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1.�������
//2.ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3.2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

//��������������ع��ǵ���һЩ��     ���Ļ�  ��ʱ���õݹ��     �ио�ֱ������
//����о��ʹ�����һ��   û�����    ͻȻ֮��ͻ����Լ��������ǲ�����Щ�˷�ʱ��
//���µ����������Լ���������ĥ��

//����ֱ�Ӱ�ԭ���ĸ��˸�   ��Ȼ�ǲ����Լ�ԭ�����˶���ʱ��,Ҳ�ǲ��õ�ʱ�ǲ����ұ��˵�ģ���� 
//���Ǹо���ʱд�����Ǽ��
//�о�Ӧ�ð���Щ����Ķ����ǵ�������    ����ÿ�ζ�����д    ��ϰ��Ŀ�ľ��ڴ˰�  
//��ʱ��ı���

#include<iostream>
#include<cstdio>
using namespace std;

//treeNode
class treeNode{
public:
	treeNode();
	treeNode* leftchild;
	treeNode* rightchild;
	int data;
};
treeNode::treeNode(){
	treeNode* leftchild = NULL;
	treeNode* rightchild = NULL;
	data = 0;
}

int sign=9;
treeNode* treeStore= new treeNode[500100];
int count_treeStore=0;

//output����
int output(treeNode*root){
	if(NULL!=root->leftchild){
		output(root->leftchild);
	}
	if(NULL!=root->rightchild){
		output(root->rightchild);
	}
	fprintf(stdout,"%d ",root->data);
	return 0;
}

//����������
treeNode *rebuild(int *preorder,int *inorder,int prefrom,int infrom,int length){
	if(length<=0){
		return NULL;
	}
	treeNode *root=&(treeStore[count_treeStore++]);
	root->data=preorder[prefrom];
	int i,j;
	for(i=infrom,j=0;j<length&&inorder[i]!=preorder[prefrom];++i,++j);
	if(j==length){
		sign=6;
		return NULL;
	}
	root->leftchild=rebuild(preorder,inorder,prefrom+1,infrom,i-infrom);
	root->rightchild=rebuild(preorder,inorder,prefrom+i-infrom+1,i+1,length-i+infrom-1);
	return root;
}

int main(){
	//input
	int n;
	fscanf(stdin,"%d",&n);
	int* preorder=new int[500100];
	int* inorder= new int[500100];
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&preorder[i]);
	}
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&inorder[i]);
	}
	
	//process
	treeNode*tree_root=rebuild(preorder,inorder,0,0,n);
	
	//output
	if(sign==9){
		output(tree_root);
	}else{
		fprintf(stdout,"%d ",-1);
	}
	
	return 0;
}
