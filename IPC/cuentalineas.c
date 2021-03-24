#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// 0 = stdin
// 1 = stdout
int count = 0;
int main(){
	char minc;
	while(read(0,&minc,1)){
		if(minc=='\n'){
			count +=1;
		}
		
		
	}
	if(minc!='\n'){
		count+=1;
	}
	printf("%d/n",count);
	return 0;
}