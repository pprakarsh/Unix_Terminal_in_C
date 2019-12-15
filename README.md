# Unix_Terminal_in_C
A clone of Unix like Terminal in C 

## Features
Executes internal commands like:
  1. `changedir directoryname`: for changing directory
  2. `log`                    : starts logging the commands history in a log file
  3. `unlog`                  : stops logging the commands
  4. `search filename`        : searches for particular file, beginning from current working directory, in all directories                                     recursively
  5. `viewcmdlog`             : gives the cmd log stored in log file
  6. `viewoutlog`             : gives the output log stored in log file
  
 Executes external commands like:
  1. All commands executed by your terminal shell, if you are using bash then commands like ls, man, mv, cp, rm, rmdir,            touch, cat etc. with the optional arguments eg. `ls -l`
  2. The commands can also be piped together (Multiple piping to form a single command) like `ls | grep string | grep str          |more` (Try executing the commands on your terminal and then on this terminal interface :))
  
  Other features:
  1. Autocompletion of filename by pressing TAB
  2. Execute previously executed command by pressing the UP ARROW


## Overview
1. The repository contains files `searchfile.c`, `Terminal.c`, `search.h`, `terminal`
2. `Terminal.c` is the main file, it contains the main code for running the terminal
3. `search filename` command required extensive coding, so the code for this command has been kept in a separate file            `searchfile.c`
4. `terminal` is the executable
5. `search.h` is the header file for `searchfile.c`


## How to Use
1. `terminal` is the executable (present in the repository)
2. Add the executable in your PATH environment variable, in Unix like environment you would be able to do it by using
   `export PATH=$PATH:/home/directory1/directory2/directory_in_which_executable_present`
3. Now, you can run the terminal by typing `terminal` on your shell prompt from anywhere in your system
4. You can make changes and study the code. To link `searchfile.c` with `Terminal.c` and compile your version, execute 
  `gcc -o terminal Terminal.c searchfile.c -lreadline` in your shell. 


## More Information about the project

1. The Terminal project is based on one simple idea, there are two types of commands which will be executed:
    1. **Internal commands:** These commands are internal to program (i.e. the commands have been coded explicitly)
    2. **External commnads:** The executable files for these commands are already present in the system binary files. Using                                 system calls execute these external commands with options (eg. ls -l, mv, cp etc)
    
2. *Multiple Piping* was implemented, this part of the program was particulary difficult to code, it involved fork() system       calls in a particular way (looping with fork system call and using *unnamed pipes* for piping, the ouput of one               command is sent to next command which inturn sends its output to the next command until the piping finishes).

3. *Search function*: `search filename` lets you search for a particular file, beginning from current working directory to       all the directories recursively. Again this part of the project was difficult to code. The idea was to start from the         present directory and search for all files in the directory, if file not found then create one process for each sub-         directory in the present working directory, this procedure is repeated recursively until the file is found. 
    Shared memory has been used for interprocess communication between processes and fork() system call has been used to         create new processes.


