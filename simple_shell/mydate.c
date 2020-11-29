#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
	char *options[] = {
	  "-u",
	  "-I"
	};
	time_t rawtime;
	struct tm * ptm; 
	if(argv[1]==NULL){
		  printf("Local time %s", ctime(&rawtime));
		  exit(EXIT_SUCCESS);	
	}else{
		
		if(strcmp(argv[1],options[0])==0){
			if(argv[2]!=NULL){
				puts("invalid command");
				exit(EXIT_FAILURE);
			}
			time_t now = time(&now);
			ptm = gmtime(&now);
			printf("UTC time: %s", asctime(ptm));
			exit(EXIT_SUCCESS);	
		}
		if(strcmp(argv[1],options[1])==0){
			if(argv[2]!=NULL){
				puts("invalid command");
				exit(EXIT_FAILURE);
			}
			char buf[256];
			memset(buf, 0, sizeof(buf));
			time (&rawtime); 
			ptm = gmtime (&rawtime);
			strftime(buf, 256, "Date in ISO format : %F", ptm); 
			puts(buf);
			exit(EXIT_SUCCESS);
		}
		puts("invalid command");
		exit(EXIT_FAILURE);		
	}
}
