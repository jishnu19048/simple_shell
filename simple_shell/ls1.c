#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include<string.h>
//todolist
//symbolic linking
//echo options
//exit status
//remaining options
//space delimiters
void findExt(char *t, char *s) {
    int i = 0;
    while(i < (int) strlen(s) && s[i]!= '.') {
        i ++;
    }   
    i ++;
    int j = 0;
    t[j ++] = '.';
    while(i < (int) strlen(s)) {
        t[j ++] = s[i ++];
    }
    t[j ++] = '\0';
}
void extSort(char **names, int n) {
    for(int i = 0; i < n - 1; ++ i) {
        for(int j = i + 1; j < n; ++ j) {           
            char *t1 = (char *) calloc(1000, sizeof(char));
            char *t2 = (char *) calloc(1000, sizeof(char));
            findExt(t1, names[i]);
            findExt(t2, names[j]);
            if(strcmp(t2, t1) < 0) {
                char *t = (char *) malloc(1000 * sizeof(char));
                strcpy(t, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], t);
            }
        }
    }
}
int main(int argc, char* argv[])
{	
	int sort=0;
	int showHidden=0;
	char *options[] = {
	  "-a",
	  "-s"
	};
	DIR *mydir;
    	struct dirent *myfile;
    	char buf[512];
	if(argv[1]==NULL){
		mydir=opendir(".");
		while((myfile = readdir(mydir)) != NULL)
		    {
		    	if(myfile->d_name[0]=='.') continue;
			sprintf(buf, "%s/%s", argv[1], myfile->d_name);
			printf(" %s", myfile->d_name);
		    }
		    printf("\n");
		    closedir(mydir);
		    return 0;
	}
	if(strcmp(argv[1],options[0])==0){
			showHidden=1;
	}
	if(strcmp(argv[1],options[1])==0){
		sort=1;
	}
	if(!showHidden && !sort){
		mydir=opendir(argv[1]);
		if(mydir==NULL){
			perror("");
			return 0;
		}
		while((myfile = readdir(mydir)) != NULL)
		    {
		    	if(myfile->d_name[0]=='.') continue;
			sprintf(buf, "%s/%s", argv[1], myfile->d_name);
			printf(" %s\n", myfile->d_name);
		    }
		closedir(mydir);
	}else if(showHidden){
		if(argv[2]==NULL)
			mydir=opendir(".");
		else
			mydir=opendir(argv[2]);
		if(mydir==NULL){
			perror("");
			return 0;
		}
		while((myfile = readdir(mydir)) != NULL)
		    {
			sprintf(buf, "%s/%s", argv[1], myfile->d_name);
			printf(" %s", myfile->d_name);
		    }
		printf("\n");
		closedir(mydir);
	}else if(sort){
		//printf("bruh\n");
		if(argv[2]==NULL)
			mydir=opendir(".");
		else
			mydir=opendir(argv[2]);
		char *names[1000]; int i=0;
		if(mydir==NULL){
			perror("");
			return 0;
		}
		while((myfile = readdir(mydir)) != NULL)
		    {
		    	if(myfile->d_name[0]=='.') continue;
			sprintf(buf, "%s/%s", argv[1], myfile->d_name);
			//printf(" %s\n", myfile->d_name);
			names[i]=(char*)malloc(1000*sizeof(char));
			strcpy(names[i], myfile->d_name); i++;
			
		    }
		extSort(names, i);
		for(int j = 0; j< i; ++ j) {
			//printf("bruh\n");
            		printf("%s", names[j]);
            		printf(" ");
        	}
        	printf("\n");
		closedir(mydir);
	}else{
		perror("invalid command");
	}
}
