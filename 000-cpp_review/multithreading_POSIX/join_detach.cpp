#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void *wait(void *t)
{
    long tid;

    tid = (long)t;

    sleep(1);
    cout << "Sleeping in thread " << endl;
    cout << "Thread with id : " << tid << "  ...exiting " << endl;
    pthread_exit(NULL);
}

int main()
{
    const int num_threads = 5;
    int rc;
    int i;
    pthread_t threads[num_threads];
    pthread_attr_t attr;
    void *status;

    // Initialize and set thread joinable
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < num_threads; i++)
    {
        cout << "main() : creating thread, " << i << endl;

        // 线程创建的时候就开始运行各自的
        rc = pthread_create(&threads[i], NULL, wait, (void *)(size_t)i);

        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    // free attribute and wait for the other threads
    pthread_attr_destroy(&attr);

    // time.sleep(3)  // 会更改打印结果
    for (i = 0; i < num_threads; i++)
    {
        // 在main函数最后调用pthread_exit(NULL)会等待所有线程运行完毕再结束
        // 通过pthread_join可以对某个线程进行join，当调用时，线程完毕前，主程序会堵塞在此
        // 其它异步的线程会继续运行。
        // cout << "Begain wait " << i << endl; // 会更改打印结果
        rc = pthread_join(threads[i], &status);
        if (rc)
        {
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }

        cout << "Main: completed thread id :" << i;
        cout << "  exiting with status :" << status << endl;
    }

    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);
}
