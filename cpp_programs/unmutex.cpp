#include <iostream>
#include <thread>
#include <vector>

int counter = 0; // Shared resource

void unsafeIncrement() {
    for (int i = 0; i < 100000; i++) {
        counter++; // Crucial line: Unprotected concurrent access!
         std::cout << "mutex: " << counter << "\n";
    }
}

int main() {
    std::thread t1(unsafeIncrement);
    std::thread t2(unsafeIncrement);

    t1.join();
    t2.join();

    // Spoiler: This will almost NEVER print 200000!
    std::cout << "Final counter without mutex: " << counter << "\n";
    return 0;
}
