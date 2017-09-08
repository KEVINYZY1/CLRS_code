
#include <iostream>
#include <string>
#include <cstdlib>
#include <pthread.h>
using namespace std;

struct thread_data {
    int thread_id;
    string message;
};

void *print_hello(void *threadarg){
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;

    cout << "Thread ID: " << my_data->thread_id
        << " Message: " << my_data->message << endl;
    pthread_exit(NULL);
}

int main(){
    const int num_threads = 5;
    pthread_t threads[num_threads];
    struct thread_data td[num_threads];
    int rc;
    int i;

    for (i=0;i<num_threads;i++){
        cout << "main(): creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].message = "This is message";
        rc = pthread_create(&threads[i], NULL, print_hello, (void*)&td[i]);

        if(rc){
            cout << "Error: unable to create thread, " << rc <<endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
