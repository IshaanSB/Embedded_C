#include <iostream>
#include <thread>
#include <chrono>

// A simple function that a thread will execute
void printNumbersodd(std::string threadName) {
    for (int i = 1; i <= 500000000000; ++i) {
   if(!(i%2)){
        std::cout << threadName << " odd counting: " << i << "\n";
        // Simulate some work by making the thread sleep for 500 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(500));}
    }
}



void printevennumber(std::string threadName) {
    for (int i = 1; i <= 50000000000000; ++i) {
	if(i%2==0){
        std::cout << threadName << " even counting: " << i << "\n";
        // Simulate some work by making the thread sleep for 500 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(500));}
    }
}

int main() {
    std::cout << "Main thread: Starting Worker 1 and Worker 2...\n";

    // 1. Create two threads and pass the function and its arguments
    std::thread t1(printevennumber, "Worker A");
    std::thread t2(printNumbersodd, "Worker B");

    // 2. The main thread keeps running concurrently alongside t1 and t2
    std::cout << "Main thread: Doing its own independent work...\n";

    // 3. Join the threads back to the main thread.
    // This forces the main thread to wait until t1 and t2 finish before exiting.
    t1.join();
    t2.join();

    std::cout << "Main thread: All worker threads have completed. Exiting.\n";
    return 0;
}
