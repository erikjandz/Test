#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.hh"
#include <stdio.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

void new_file(){
        cout << "Geef een bestandsnaam: ";
        string naam;
        mode_t mode = 0600;
        getline(cin, naam);
        naam = naam + ".txt";
        creat(naam.c_str(), mode);
        cout << "Geef inhoud voor de file: ";
        string inhoud;
        getline(cin, inhoud);
        int lengte = inhoud.size();
        int filedesc = open(naam.c_str(), O_RDWR);
        write(filedesc, inhoud.c_str(), lengte);

}

void list(){
        int pid = fork();
        if(pid==0){
        char *args[]={"/bin/ls", "-la", NULL};
        execvp(args[0], args);
        exit(2);
        }
        else{wait(NULL);
        }
}

void find(){
        cout <<"hi" << endl;
}

void python(){
        int pid = fork();
        if(pid == 0){
                char *args[]={"/usr/bin/python", NULL};
                execvp(args[0], args);
        }
        else{wait(NULL);
        }
}


int main(){
        string input;
        while(true){
                system("cat prompt.txt");
                getline(cin, input);
                if(input == "new_file"){
                        new_file();
                }
                if(input == "ls"){
                        list();
                }
                if(input == "find"){
                        find();
                }
                if(input == "python"){
                        python();
                }
                if(input == "quit"){
                        return 0;
                }
                if(input == "error"){
                        return 1;
                }
        }
}

                                                                                                                                                                                                                            37,2-8        Top
