#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

struct Road{
	int from;
	int to;
	int price;
};

int main(){
	//����
	int n,m;
	fscanf(stdin,"%d %d",&n,&m);
	Road*road=(Road*)malloc(1000100*sizeof(Road));
	for(int i=0;i<m;i++){
		fscanf(stdin,"%d %d %d",&(road[i].from),&(road[i].to),&(road[i].price));
	}
	//�ҳ�����û�б�ָ��ĵ�,Ҳ���ǿ�����Ϊ���ĵ�
	int *find_origin=(int*)malloc(100100*sizeof(int));
	for(int i=0;i<100100;i++){
		find_origin[i]=0;
	}
	for(int i=0;i<m;i++){
		int temporary=road[i].to;
		find_origin[temporary]=temporary;
	}
	int *origin=(int *)malloc(100100*sizeof(int));
	int origin_number;//���ĸ���(����0)
	for(int i=1,j=0;i<=n;i++){
		if(0==find_origin[i]){
			origin[j++]=i;
			origin_number=j;
		}
	}
	//�ж�ǰ��׼��
	int*road_line=(int *)malloc(100100*sizeof(int ));
	int road_line_price=0;
	int road_line_village_number;//����0
	int*backup=(int *)malloc(100100*sizeof(int ));
	int backup_price=0;
	int backup_village_number;//����0
	//�ж�
	for(int i=0;i<origin_number;i++){//һ��ѭ��,һ�����,һ��·��
		backup[0]=origin[i];
		int sign=10;
		backup_price=0;
		for(int j=0;sign==10;j++){//һ��ѭ��,һ����ׯ
			sign=9;
			backup_village_number=j+1;
			int max_price_once=0;
			for(int k=0;k<m;k++){
				if(road[k].from==backup[j]){
					if(road[k].price>max_price_once){
						backup[j+1]=road[k].to;
						backup_price=backup_price+(road[k].price-max_price_once);
						max_price_once=road[k].price;
					}
					if(road[k].price==max_price_once){
						if(road[k].to<backup[j+1]){
							backup[j+1]=road[k].to;
						}
					}
					sign=10;
				}
			}
		}
		if(backup_price>road_line_price){
			for(int i=0;i<backup_village_number;i++){
				road_line[i]=backup[i];
			}
			road_line_village_number=backup_village_number;
			road_line_price=backup_price;
		}
		if(backup_price==road_line_price){
			if(backup[0]<road_line[0]){
				for(int i=0;i<backup_village_number;i++){
					road_line[i]=backup[i];
				}
				road_line_village_number=backup_village_number;
				road_line_price=backup_price;
			}
		}
	}
	//���
	for(int i=0;i<road_line_village_number;i++){
		fprintf(stdout,"%d\t",road_line[i]);
	}
	return 0;
}

