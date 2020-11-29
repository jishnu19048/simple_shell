#include<stdio.h>
#include <stdio.h>
#include <string.h>
void main(int argc , char **argv)
{
                FILE *file;
               char line[10000];
               char *options[] = {
		  "-n",
		  "-E"
		};
		if(argv[1][0]!='-'){
		       file = fopen(argv[1],"r");
		       if(file==NULL){
		       	perror("Error");
		       }
		       while(fscanf(file,"%[^\n]\n",line)!=EOF)
		       {		
		                      printf("%s\n", line);
		       }
		       fclose(file);
		       return;
		  }
		 if(strcmp(argv[1],options[0])==0){
			file = fopen(argv[2],"r"); int cnt=1;
			if(file==NULL){
		       	perror("Error");
		       }
		       while(fscanf(file,"%[^\n]\n",line)!=EOF)
		       {		
		       		printf("%d",cnt);
		       		printf(")");
		       		cnt++;
		                      printf("%s\n", line);
		       }
		       fclose(file);
		       return;
		}
		if(strcmp(argv[1],options[1])==0){
			file = fopen(argv[2],"r");
			if(file==NULL){
		       	perror("Error");
		       }
		       while(fscanf(file,"%[^\n]\n",line)!=EOF)
		      {
		      			char c='$';
		      			strncat(line,&c,1);
		                      printf("%s\n", line);
		       }
		       fclose(file);
		       return;
		}
		puts("invalid command");
		return;
}
