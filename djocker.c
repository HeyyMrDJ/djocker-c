#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <unistd.h>

void printworkingdir();
void printhostname();
void printinfo();


int main(void) {
        printf("Entering Pen\n");
        unshare(CLONE_NEWNET | CLONE_NEWUTS | CLONE_NEWIPC | CLONE_NEWUSER | CLONE_NEWPID);
        printinfo();
        printf("\nchroot change\n");
        chroot("/home/ubuntu/pen2");
        printinfo();
        printf("\nSetting hostname\n");
        sethostname("TEST", 16);
        printinfo();
        printf("\nExiting Pen\n");
        return 0;

}

void printworkingdir(){
        char cwd[256];
        getcwd(cwd, sizeof(cwd));
        printf("Current working directory: %s\n", cwd);
}

void printhostname(){
        char hostname[256];
        gethostname(hostname, sizeof(hostname));
        printf("Current Hostname: %s\n", hostname);
}

void printinfo(){
        printhostname();
        printworkingdir();
}
