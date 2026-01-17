#include <stdio.h>
#include <thread>

void Func1() {
	printf("thread1\n");
}

void Func2() {
	printf("thread2\n");
}

void Func3() {
	printf("thread3\n");
}

int main() {
	std::thread th1(Func1);
	th1.join();
	std::thread th2(Func2);
	th2.join();
	std::thread th3(Func3);
	th3.join();

	return 0;
}