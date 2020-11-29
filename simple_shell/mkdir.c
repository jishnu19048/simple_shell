
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
  
int main(int argc, char** argv) 
  
{ 
	char *options[] = {
		  "--help",
		  "-v"
		};
	if(argv[1]==NULL){
		puts("invalid command");
		return 0;
	}
	if(argv[2]==NULL && strcmp(argv[1],options[0])!=0 && strcmp(argv[1],options[1])!=0){
		if(argv[1][0]=='-'){
		 puts("invalid command");
		 return 0;
		 }
	    if (mkdir(argv[1], 0777) == -1) 
		printf("Error: file exists\n");
	       
	   }
	else{
	   if(strcmp(argv[1],options[1])==0){
	   	if (mkdir(argv[2], 0777) == -1) 
			printf("Error: file exists\n");
		    else{
			printf("Directory created : "); 
			printf("%s\n",argv[2]);  
		   }
		  return 0;
	    }
	    if(strcmp(argv[1],options[0])==0){
	   	printf("Usage: mkdir [OPTION]... [DIRECTORY]...\n");
	   	printf("Create the DIRECTORY(ies), if they do not already exist.\n");
	   	printf("\n");
	   	printf("Mandatory arguments to long options are mandatory for short options too.\n");
	   	printf("   -v, --verbose     print a message for each created directory\n");	
	    	return 0;
	    }
	    perror("invalid command");
	}
	return 0; 
    
} 
