# simple_shell
INTERNAL COMMANDS: cd, pwd, exit, echo, history

		'cd' Description:
			COMMAND: cd (implements cd from linux)

			SOURCE CODE: 

			USAGE: cd [DIRECTORY]

			WHAT IT DOES: changes current working directory to the specified directory
				
			CORNER CASES AND ERRORS HANDELED:
				Invalid commands, directories, etc.
				exits the command with error description.
		
		'pwd' Description:
			COMMAND: pwd (implements pwd from linux)

			SOURCE CODE: 

			USAGE: pwd [DIRECTORY]

			WHAT IT DOES: shows the path of the current working directory
				
			CORNER CASES AND ERRORS HANDELED:
				Invalid command.
				exits the command with error description.
				
		'exit' Description:
			COMMAND: exit (implements exit from linux)

			SOURCE CODE: 

			USAGE: exit

			WHAT IT DOES: exits the shell with exit status- 0
				
			CORNER CASES AND ERRORS HANDELED:
				Invalid command.
				exits the command with error description.
		
		'echo' Description:
			COMMAND: echo (implements echo from linux)

			SOURCE CODE: 

			USAGE: echo [OPTION] [STRING]  
				***Double quotes not required while specifying the string.***
				***if the user wishes to use escape sequences then its mandatory that the escape
				sequence is specified after a space***

			WHAT IT DOES: display line of text/string that are passed as an argument
			OPTIONS :
				-n ignores the new line character
				-e enables the interpretation of backslash escapes
					**backslash escapes implemented are :
						\n : inserts new line
						\c : supresses trailing new line
					
			CORNER CASES AND ERRORS HANDELED:
				Invalid command, invalid options, etc..
				exits the command with error description.
				
		'history' Description:
			COMMAND: history (implements history from linux)

			SOURCE CODE: 

			USAGE: history [OPTION] [STRING]  

			WHAT IT DOES: used to view the previously executed commands 
			OPTIONS :
				-c clears the history
				-s append the argument to the history list as a single entry
					
			CORNER CASES AND ERRORS HANDELED:
				Invalid command, invalid options, etc..
				exits the command with error description.
				
EXTERNAL COMMANDS: 
		ls1, myrm, mkdir, mycat, mydate
		(Descriptions of each command in separate file).
		
COMPILATION: 
		The c files of the external commands are in /2019048_Assignment2/Assignment2. We comnpile the binaries
		in the same location.
		First we compilation of external binaries are done, following which we compile our shell.c file.
		We now are ready to use the simple shell. We run the ./a.out in our terminal. We are shown the user
		username first. 
		We have 5 internal and 5 external commands for our use.
		**The explanations for the external binaries are in /2019048_Assignment1/Q2/Explanations.
		
	Control: Shell will open in the cuurent directory.
		Commands available to use:
			cd,pwd,echo,history,exit,ls1,myrm,mkdir,mycat,mydate
		Input is terminated using a new line escape.
	How input is parsed into argument array:
		A parsing function is used to parse the input string using space and new line delimeters.
		The arguments are returned as and char** array.
		This is passed as an argument wherever required.
	Error Handling: 
		Fork failure, invalid commands, invalid options, etc. are handeled by exiting with appropriate error 
		description.
		



