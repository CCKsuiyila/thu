//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1.�������
//2.ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3.2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

//��Ȼ  �����ֱ�Ӹı�mooc�Ǹ���   ������Ǹ��򵥵�
#include<iostream>
#include<cstdio>
using namespace std;

class STACK{
	public:
		STACK(int length);//���캯��,ȷ��ջ�ĳ���
		bool empty();//�ж�ջ��
		bool full();//�ж�ջ��
		bool push(int value);//��ջ
		int pop();//��ջ
	private:
		int max_length;
		int  current_length;
		int* array;
};
STACK::STACK(int length){
	max_length = length;
	current_length = 0;
	array = new int[length+10];
}

bool STACK::empty(){
	if(current_length ==0){
		return true;
	}else{
		return false;
	}
}

bool STACK::full(){
	if(current_length == max_length){
		return true;
	}else{
		return false;
	}
}

bool STACK::push(int value){
	if(!full()){
		array[current_length] = value;
		current_length = current_length + 1;
		return true;
	}else{
		return false;
	}
}

int STACK::pop(){
	if(!empty()){
		current_length = current_length - 1;
		int temp = array[current_length];
		return temp;
	}
}



int line[1600000+100];


int main(){
	
	int n;
	int m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		fscanf(stdin,"%d",&(line[i]));
	}
	STACK train_stack(m);
	int i = 1;
	int count_line = 0;
	while((i<=n)||(!train_stack.empty())){
		if(i < line[count_line]){
			if(train_stack.push(i)){
				++i;
				continue;
			}else{
				fprintf(stdout,"%s\n","No");
				return 0;
			}
		}
		if(i == line[count_line]){
			if(!train_stack.full()){
				++i;
				++count_line;
				continue;
			}else{
				fprintf(stdout,"%s\n","No");
				return 0;
			}
		}
		if(i > line[count_line]){
			if(train_stack.pop() == line[count_line]){
				++count_line;
			}else{
				fprintf(stdout,"%s\n","No");
				return 0;
			}
		}
	}
	fprintf(stdout,"%s\n","Yes");
	return 0;
}