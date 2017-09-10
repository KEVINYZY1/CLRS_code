#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

void example_1();
void example_2();

void signalHandler(int signum){
    cout << "Interrupt signal (" << signum << ") received." << endl;

    // clearnup and close up stuff here
    // terminate program
    exit(signum);
}

int main(){
    // register signal SIGINT and signal handler
    // example_1();
    example_2();
}

void example_1(){
    // 接收待回调的函数指针
    // register signal SIGINT and signal handler
    signal(SIGINT, signalHandler);
    while(1) {
        cout << "Going to sleep..." << endl;
        sleep(1);
    }
}

void example_2(){
    int i=0;
    // 只有产生SIGINT信号，才会回调
    signal(SIGINT, signalHandler);
    while(++i){
        cout << "Going to sleep..." << endl;
        if(i==3){
            raise(2);
        }
        sleep(1);
    }
}
