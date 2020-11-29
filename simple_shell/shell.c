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
char* path;
void init_shell()
{
	//clear();
	char* uname= getenv("USER");
	printf("Simple Shell : Made by -Jishnu Raj Parashar\n");
	printf("\n\nUSER is: @%s", uname);
	printf("\n");
	//clear();
}
char *take_input()
{
	char *line=NULL;
	ssize_t size = 0;
	if(getline(&line, &size, stdin) == -1){
		if(feof(stdin)){
			exit(EXIT_SUCCESS);
		}else{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return line;
}
int my_pwd(char** arg){
	if(arg[1]==NULL || (arg[1]!=NULL && strcmp(arg[1],"-P")==0) || (arg[1]!=NULL && strcmp(arg[1],"..")==0)){
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		printf("dir: %s", cwd);
		printf("\n");
		return 1;
	}else if(strcmp(arg[1],"-L")==0){
		char buff[1024];
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
    		ssize_t len = readlink(cwd, buff, sizeof(buff)-1);
    		if (len != -1) {
      			buff[len] = '\0';
      			printf("dir: %s", buff);
			printf("\n");
    		}
    		return 1;	
    	}
    	perror("invalid command\n");
    	return 1;	
}
char **parse(char* str){
	int pos=0;
	char **tokens = calloc(1024,sizeof(char*));
	char *token;
	token=strtok(str," \n");
	while(token!=NULL){
		tokens[pos]=token;
		pos++;
		token=strtok(NULL," \n");
	}
	return tokens;
}

void add_to_history(char** arg){
	char *hispath =calloc(1024,sizeof(char));
	strcpy(hispath,path);
	strcat(hispath,"/history.txt");
	int fp = open(hispath,O_WRONLY | O_APPEND);
	char *c =(char *) calloc(1024, sizeof(char)); int j=0; int pos=0;
	while(arg[pos]!=NULL){
		for(int i=0;i<strlen(arg[pos]);i++){
			*(c+j)=*(arg[pos]+i);
			j++;
		}
		pos++;
		*(c+j)=' ';
		j++;
	}
  	write(fp, c, strlen(c));
 	close(fp);
}
int my_history(char **arg){
	char *hispath =calloc(1024,sizeof(char));
	strcpy(hispath,path);
	strcat(hispath,"/history.txt");
	if(arg[1]!=NULL){
		char *options[] = {
		  "-c",
		  "-s"
		};
		if (strcmp(arg[1], options[1]) == 0) {
			if(arg[2]==NULL){
				return 1;
			}
			int fp = open(hispath,O_WRONLY | O_APPEND);
			char *c =(char *) calloc(1024, sizeof(char)); int j=0; int pos=2;
			while(arg[pos]!=NULL){
				for(int i=0;i<strlen(arg[pos]);i++){
					*(c+j)=*(arg[pos]+i);
					j++;
				}
				pos++;
				*(c+j)=' ';
				j++;
			}
		  	write(fp, c, strlen(c));
		 	close(fp);
		 	return 1;
		}
		if (strcmp(arg[1], options[0]) == 0) {
			//printf(arg[2]);
			//printf("\n");
			if(arg[2]!=NULL){
				perror("invalid command");
				return 1;
			}
			int fp = open(hispath,O_TRUNC);
			close(fp);
			return 1;
		}
		perror("invalid command");
		return 1;
		
	}
	add_to_history(arg);
	int fp = open(hispath,O_RDONLY);
	char *c =(char *) calloc(1024, sizeof(char));
 	if(fp != -1)
 	{
  		read(fp, c, 1024);
 	}
 	close(fp);
 	printf("%s",c);
 	printf("\n");
 	return 1;
}
int my_cd(char **arg){
	chdir(arg[1]);
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("dir: %s", cwd);
	printf("\n");
	return 1;
}
int my_echo(char **arg){
	char *options[] = {
	  "-n",
	  "-e"
	};
	if(arg[1][0]=='-'){
		if(strcmp(arg[1],options[1])==0){
			 int j=2;
			 int c=0;
			 char a ='\\';
			while(arg[j]!=NULL){
				int i=0;
				while(i<strlen(arg[j])){
					if(arg[j][i]==a && i==0){
						if(strlen(arg[j])>=2){
							if(arg[j][i+1]=='n'){
								printf("\n");
								i+=2;
							}
							else if(arg[j][i+1]=='c'){
								c=1;
								break;
							}
							else{
								printf("%c",arg[j][i]);
								i++;
							}
						}
					}else{
						printf("%c",arg[j][i]);
						i++;
					}
				}
				if(c==1){
					break;
					}
				printf(" ");
				j++;
							
			}
			printf("\n");
			return 1;
		}
	
		if(strcmp(arg[1],options[0])==0){
			int pos=2;
			//printf(arg[1]);
			//printf("\n");
			if(arg[2]==NULL){
				return 1;
			}
			while(arg[pos]!=NULL){
				printf("%s",arg[pos]);
				printf(" ");
				pos++;
			}
			return 1;
		}
		perror("invalid command");
		return 1;
	}else{
		int pos=1;
		//printf(arg[1]);
		//printf("\n");
		if(arg[1]==NULL){
			printf("\n");
			return 1;
		}
		while(arg[pos]!=NULL){
			printf("%s",arg[pos]);
			printf(" ");
			pos++;
		}
		printf("\n");
		return 1;
	}
}
void my_exit(){
 	exit(0);
}	
int check(char	**arg){
	char *builtin_str[] = {
	  "cd",
	  "pwd",
	  "exit",
	  "echo",
	  "history"
	};
	if (arg[0] == NULL) {
	    return 1;
	  }
	  //printf(arg[1]);
	  //printf("\n");
	    if (strcmp(arg[0], builtin_str[0]) == 0) {
	    	add_to_history(arg);
	      return my_cd(arg);
	    }
	    if (strcmp(arg[0], builtin_str[1]) == 0) {
	    	add_to_history(arg);
	       return my_pwd(arg);
	    }
	    if (strcmp(arg[0], builtin_str[2]) == 0) {
	  	add_to_history(arg);
	      	my_exit();
	    }
	    if (strcmp(arg[0], builtin_str[3]) == 0) {
	  	add_to_history(arg);
	      return my_echo(arg);
	    }
	    if (strcmp(arg[0], builtin_str[4]) == 0) {
	      return my_history(arg);
	    }
	    add_to_history(arg);
	   
	  return 0;
}
int exec_arg(char** arg){
	pid_t pid, wpid;
	  int status;
	  //printf(arg[0]);
	  pid = fork();
	  if (pid == 0) {
	    if (execvp(arg[0], arg) == -1) {
	      perror("");
	    }
	    exit(EXIT_FAILURE);
	  } else if (pid < 0) {
	    perror("forking failed");
	  } else {
	    wait(NULL);
  	}

  return 1;
}
int main()
{
	int flag=0;
	init_shell();
	path=calloc(1024,sizeof(char));
	getcwd(path, 1024);
	//printf(path);
	//printf("\n");
	while(1){
		char* inputS=calloc(1024,sizeof(char));; char **par=calloc(1024,sizeof(char*));;
		char * pathr=calloc(1024,sizeof(char));
		strcpy(pathr,path);
		strcat(pathr,"/");
		printf(">");
		inputS=take_input();
		par=parse(inputS);
		flag=check(par);
		if(!flag){
			strcat(pathr,par[0]);
			par[0]=pathr;
			exec_arg(par);
		}
		free(par);
		free(inputS);
		
	}
}
