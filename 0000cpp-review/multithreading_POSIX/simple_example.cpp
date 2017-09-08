#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

void *print_hello(void *threadid){
    long tid;
    tid = (long)threadid;
    cout << "Hello world! Thread ID, " << tid << endl;
    pthread_exit(NULL);
}

int main(){
    const int num_threads = 5;
    pthread_t threads[num_threads];
    int rc;
    int i;

    for (i=0;i<num_threads;i++){
        cout << "main(): creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, print_hello, (void*)NULL);

        if(rc){
            cout << "Error: unable to create thread, " << rc <<endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
