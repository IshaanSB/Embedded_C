#include <iostream>
#include <thread>
#include <mutex> // 1. Include the mutex header

int safe_counter = 0;
std::mutex mtx; // 2. Create the mutex object

void safeIncrement() {
    for (int i = 0; i < 100000; ++i) {
        // 3. Use lock_guard to lock the mutex safely.
        // It locks right here, and automatically unlocks when the loop iteration ends.
        std::lock_guard<std::mutex> lock(mtx); 
        
        safe_counter++; // Safe! Only one thread can be here at a time.
    }
}

int main() {
    std::thread t1(safeIncrement);
    std::thread t2(safeIncrement);

    t1.join();
    t2.join();

    // This will ALWAYS print exactly 200000!
    std::cout << "Final counter with mutex: " << safe_counter << "\n";
    return 0;
}
