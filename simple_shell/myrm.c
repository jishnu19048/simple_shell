#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include<string.h>

int main(int argc, char **argv) 
{  
	char *options[] = {
		  "-v",
		  "-i"
		};
	if(argv[1]==NULL){
		puts("missing argument");
		return 0;
	}
	if(argv[1][0]!='-'){
		if(opendir(argv[1]) != NULL) { 
			puts("file doesnt exist");
			return 0;
		}
	    if(remove(argv[1])==0);
	    else printf("Error\n"); 
	    return 0;   
	   }
	else{
	   if(strcmp(argv[1],options[0])==0){
	   	if(argv[2]==NULL){
			puts("missing argument");
			return 0;
		}
		if(opendir(argv[2]) != NULL) { 
			puts("file doesnt exist");
			return 0;
		}
	   	if(remove(argv[2])==0) {
	   		printf("removed ");
	   		printf("%s\n",argv[2]);
	   	}
	    	else printf("Error\n");
	    	return 0; 
	    }
	    if(strcmp(argv[1],options[1])==0){
	    	if(argv[2]==NULL){
			puts("missing argument");
			return 0;
		}
		if(opendir(argv[2]) != NULL) { 
			puts("file doesnt exist");
			return 0;
		}
	   	printf("remove regular file ");
	   	printf("%s",argv[2]);
	   	printf(" y/N?\n");
	   	char test;
	   	scanf("%c", &test);
	   	if(test=='N') return 0;
	   	else if(test=='y'){
	   		if(remove(argv[2])==0);
	    		else printf("Error\n"); 
	    	}else{
	    		printf("invalid option\n");
	    	}
	    	return 0;
	    }
	    puts("invalid options");
	    return 0;
	}
} 
