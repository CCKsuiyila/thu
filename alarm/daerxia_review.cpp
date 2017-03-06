//�� ����һ���Լ�������˼·(���ÿ��һ��Ͱ����ճ��ȥ)
//1. �������
//2. ȷ������˼·(ѡ�����ݽṹ�㷨ʲô��)   ȷ���ܽ���������,Ҳ���ÿ���̫�ิ�Ӷ�
//3. 2�ﵽ֮��, ��ʼ���Ǹ��ֽ������������������   Ȼ�󿴿���û�и��Ӷȸ��͵�˼·

//��������� �������˹鲢����,��������,���ֲ���.....�о����ĸ���������֮��
//û��   ���Ƿ��η�    �����ֱ���Ƿ��η��ľ���Ӧ��    ����

//���⻹���Ը��ӵ�    ��һ��������15��ֹͣ
//��ĩ��Ϣ������,�����������ҫ������    
//Ȼ����һ������ֽ���˻�,������˼·    �ܿ��Ҽ�һ��©��(��֪�����Ļ���ʲô���,��֪�����˸��Ͻ�,�����ܴ��ڿ���֮��)
//Ȼ��͸���,Ȼ��ʹ�15�ֵ���50��
//֮ǰ��->15Ҳ�Ƿ�����һ��©��
//����Ҫ���ɺ�ϰ�߰�    �Ͻ�һ��  ��ȡ����˼·��©��   һ���ȥ���
//�����������
//
#include<cstdio>
#include<iostream>
using namespace std;
class Line{
public:
	long long int x;
	long long int y;
};

class Use_for_quicksort{
	public:
		int compare;
		long long int store_one;
		long long int store_two;
		int result;
};

int process(Use_for_quicksort* point, Line* line, int low, int high, int line_low, int line_high){
	int line_middle = (line_low+line_high)/2;
	int lef = low;
	int righ = high-1;
	Use_for_quicksort temp = point[righ];
	while(lef<righ){
		while(lef<righ){
			if(((line[line_middle].x)*(point[lef].store_two)+(line[line_middle].y)*(point[lef].store_one)-(line[line_middle].x)*(line[line_middle].y))<0){
				point[lef].result = line_middle;
				++lef;
			}else{
				point[lef].result = line_middle+1;
				point[righ] = point[lef];
				--righ;
				break;
			}
		}
		while(lef<righ){
			if(((line[line_middle].x)*(point[righ].store_two)+(line[line_middle].y)*(point[righ].store_one)-(line[line_middle].x)*(line[line_middle].y))>=0){
				point[righ].result = line_middle+1;
				--righ;
			}else{
				point[righ].result = line_middle;
				point[lef] = point[righ];
				++lef;
				break;
			}
		}
	}
	point[lef] = temp;
	if(((line[line_middle].x)*(point[lef].store_two)+(line[line_middle].y)*(point[lef].store_one)-(line[line_middle].x)*(line[line_middle].y))<0){
		point[lef].result = line_middle;
		if(line_middle==line_low){
			return 0;
		}
		process(point, line, low, lef+1, line_low, line_middle);
		if(lef!=high-1&&line_middle!=line_high-1){                                    //15->50
			process(point, line, lef+1, high, line_middle+1, line_high );
		}
		
	}else{
		point[lef].result = line_middle+1;
		if(line_middle==line_low){
			return 0;
		}
		if(righ!=low){
			process(point, line, low, lef, line_low, line_middle);
		}
		if(line_middle!=line_high-1){                                                 //15->50
			process(point, line, lef, high, line_middle+1, line_high );
		}
		
	}
	return 0;
}

//quicksort algotithm
int quicksort(Use_for_quicksort *data,int low,int high){
	int partition(Use_for_quicksort *data,int low,int high);
	if ((high-low)<1){
		return 0;
	}
	
	int middle=partition(data,low,high-1);
	quicksort(data,low,middle);
	quicksort(data,middle+1,high);
	return 0;
}

int partition(Use_for_quicksort *data,int low,int high){
	int backup_low=low;
	int backup_high=high;
	Use_for_quicksort middle_data=data[low];
	for(;low<high;){
		for(;low<high;){
			if(data[high].compare>middle_data.compare){
				high=high-1;
			}else{
				data[low]=data[high];
				low=low+1;
				break;
			}
		}
		for(;low<high;){
			if(data[low].compare<middle_data.compare){
				low=low+1;
			}else{
				data[high]=data[low];
				high=high-1;
				break;
			}
		}
	}
	int middle=low;
	data[low]=middle_data;
	low=backup_low;
	high=backup_high;
	return middle;
}

int main(){
	//input
	int n;
	int m;
	fscanf(stdin,"%d %d",&n,&m);
	Line* line = new Line[100010];
	for(int i=0;i<n;++i){
		fscanf(stdin,"%lld %lld",&line[i].x,&line[i].y);
	}
	Use_for_quicksort* point = new Use_for_quicksort[1000010];
	for(int i=0;i<m;++i){
		point[i].compare = i;
		fscanf(stdin,"%lld %lld",&point[i].store_one,&point[i].store_two);
	}
	//process
	process(point, line, 0, m, 0, n);
	quicksort(point, 0, m);
	//output
	for(int i=0;i<m;++i){
		fprintf(stdout,"%d\n",point[i].result);
	}
	return 0;
}

