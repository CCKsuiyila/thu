//��о����    �б�õ�ģ����    �������Сʱ�ͳ�����  ����һ�ι�, ��Ȼ����Ƚϼ�(��Ȼ�ѵ���ڱ��Ǹ�ģ���)
//����Ĺ����оͲ��Ϸ�װ�Լ��Ĺ��߰�    �Ժ��Խ��Խ���
//����Խ��   ����Խ��      ��Ҳ�Ǹ��߼������Ե��ŵ�֮һ��   ��ô��Щ����ʹ�õ��Ѷȿ����֪����ܸ�
//���������ѵ��°�(��Զ���)    �򵥵��Ժ�ѧ Ҳ����


//2017-02-27 09:46:02	     50.0/50.0
#include<cstdio>
using namespace std;

//cycle_list
class listnode{
	public://����Ҫ��˽�еľͻ�һ�Ѵ���
		listnode*prev;
		listnode*succ;
		int ball;
};
class list{
	public:
		list(int length);//���캯��,lengthΪ�б����󳤶�,Ҳ�����ܹ���������ڴ�
		listnode*list_head;//ͷָ��
		int total;//�б�Ԫ������
		void initialize(int ball);//��ʼ���б�,��������һ��Ԫ��
		listnode*append(int ball);//���б�ĩβ���Ԫ��
		listnode*insertbehind(int num,int ball);//������λ����� �����б�Ԫ����Ŵ�1��ʼ   numΪ1ָ�ڵ�һ��Ԫ�غ����Ԫ��   numΪ0���������,��ʱ���ڵ�һ��Ԫ��ǰ�����Ԫ��,���������Ԫ�س�ΪͷԪ��(�ı�ͷָ��)
	private: 
		int rank;//�ڴ��õ�����
		listnode* data;//������ڴ�
};

void list::initialize(int ball){//��ʼ���б�,��������һ��Ԫ��
			listnode*pnode = &(data[rank++]);
			list_head=pnode;
			list_head->prev=list_head;
			list_head->succ=list_head;
			list_head->ball=ball;
			total = 1;
}
listnode* list::append(int ball){//���б�ĩβ���Ԫ��
			listnode*pnode = &(data[rank++]);
			pnode->prev=list_head->prev;
			pnode->succ=list_head;
			list_head->prev=pnode;
			pnode->prev->succ = pnode;
			pnode->ball=ball;
			total = total + 1;
			return pnode;
}
listnode* list::insertbehind(int num,int ball){//������λ����� �����б�Ԫ����Ŵ�1��ʼ   numΪ1ָ�ڵ�һ��Ԫ�غ����Ԫ��   numΪ0���������,��ʱ���ڵ�һ��Ԫ��ǰ�����Ԫ��,���������Ԫ�س�ΪͷԪ��(�ı�ͷָ��)
			listnode*pnode = &(data[rank++]);
			if(0 == num){//�����ʵ�Ǹı�ͷԪ��
				pnode->prev=list_head->prev;
				pnode->succ=list_head;
				pnode->prev->succ=pnode;
				pnode->succ->prev=pnode;
				pnode->ball=ball;
				list_head = pnode;
				total = total + 1;
				return pnode;
			}else{//������������  ��ĳ��Ԫ�غ������
				listnode*container=list_head;
				for(int i=1;i<num;i++){
					container=container->succ;
				}
				pnode->prev=container;
				pnode->succ=container->succ;
				pnode->prev->succ=pnode;
				pnode->succ->prev=pnode;
				pnode->ball=ball;
				total = total + 1;
				return pnode;
			}
}
list::list(int length){
	data = new listnode[length];
	rank = 0;
	total = 0;
}

int main(){
	//input
	int n,m;
	fscanf(stdin,"%d %d",&n,&m);
	int* input = new int[n+10];
	for(int i=0;i<n;++i){
		fscanf(stdin,"%d",&(input[i]));
	}
	//process
	list mylist(n);
	mylist.initialize(input[0]);
	for(int i=1;i<n;++i){
		listnode* change_list_head = mylist.insertbehind(m,input[i]);
		mylist.list_head = change_list_head;
	}
	//output
	listnode* temporary_index = mylist.list_head;
	for(int i=0;i<n;++i){
		fprintf(stdout,"%d ",temporary_index->ball);
		temporary_index = temporary_index->prev;
	}
	return 0;
}