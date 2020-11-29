#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<fcntl.h> 
#include<errno.h> 
char **parse(char* str){
	int pos=0;
	char **tokens = malloc(100*sizeof(char*));
	char *token;
	token=strtok(str," \n");
	while(token!=NULL){
		tokens[pos]=token;
		pos++;
		token=strtok(NULL," \n");
	}
	return tokens;
}
int main(){
	pid_t pid;
	int status;
	//printf(arg[0]);
	pid = fork();
	if (pid == 0) {
		puts("For Section A:\n");
		int fp,size;
		fp=open("csv_data.txt",O_RDONLY);
		if(fp==-1){
			perror("file doesnt exist");
			return 0;
		}
		char data[100000];
		size = read(fp, data, sizeof(data));
		data[size]='\0';
		close(fp);
		int i=0;
		while(i<strlen(data)){
			char *line= (char*)malloc(100*sizeof(char));
			int j=0;
			while(j<strlen(data) && data[i]!='\n' && data[i] != 0x0 ){
				line[j++]=data[i++];
			}
			line[j]='\0';
			char **parsed=parse(line);
			int k=0;
			char *id=parsed[0];
			char *section=parsed[1];
			float average_marks=0;
			for(int k=2;k<6;k++){
				float f=atof(parsed[k]);
				average_marks+=f;
			}
			average_marks/=4.0;
			if(section[0]=='A'){
				printf("ID of student: %s", id);
				printf(" Average marks: %f\n", average_marks);
			}
			i++;
		}
		printf("\n");
		exit(EXIT_SUCCESS);
	} else if (pid < 0) {
		perror("forking failed!!!\n");
	} else {
		wait(NULL);
		puts("For Section B:\n");
		int fp,size;
		fp=open("csv_data.txt",O_RDONLY);
		if(fp==-1){
			perror("file doesnt exist");
			return 0;
		}
		char data[100000];
		size = read(fp, data, sizeof(data));
		data[size]='\0';
		close(fp);
		int i=0;
		while(i<strlen(data)){
			char *line= (char*)malloc(100*sizeof(char));
			int j=0;
			while(j<strlen(data) && data[i]!='\n' && data[i] != 0x0 ){
				line[j++]=data[i++];
			}
			line[j]='\0';
			char **parsed=parse(line);
			int k=0;
			char *id=parsed[0];
			char *section=parsed[1];
			float average_marks=0;
			for(int k=2;k<6;k++){
				//printf("%s\n",parsed[k]);
				float f=atof(parsed[k]);
				average_marks+=f;

			}
			//printf("%f\n",average_marks);
			average_marks/=4.0;
			
			if(section[0]=='B'){
				printf("ID of student: %s", id);
				printf(" Average marks: %f\n", average_marks);
			}
			i++;
		}
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	return 0;
}
