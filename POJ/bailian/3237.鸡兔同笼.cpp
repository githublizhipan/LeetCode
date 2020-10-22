/*************************************************************************
	> File Name: 3237-1.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Wed Oct 21 11:39:24 2020
	> Source: 
 ************************************************************************/
#include<cstdio>
int main(){
	int nCases,nFeets;
	while(scanf("%d",&nCases)!=EOF){
		for(int i = 0;i < nCases;i++){
			scanf("%d", &nFeets);
			if(nFeets%2!=0){
				printf("0 0\n");
			}else{
				if(nFeets%4==0){
					printf("%d %d\n",nFeets/4,nFeets/2);
				}else{
					printf("%d %d\n",nFeets/4+1,nFeets/2);
				}
			}
		}
	}
	return 0;
}
