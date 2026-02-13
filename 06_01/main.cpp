#include <stdio.h>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mutex;
std::condition_variable conditionVariable;
int turn = 1;

void Func1() {
	std::unique_lock<std::mutex> lock(mutex);
	// 自分の番号になるまで待機
	conditionVariable.wait(lock, [] { return turn == 1; });
	printf("thread1\n");
	turn = 2;
	// 全体に通知する
	conditionVariable.notify_all();
}

void Func2() {
	std::unique_lock<std::mutex> lock(mutex);
	// 自分の番号になるまで待機
	conditionVariable.wait(lock, [] { return turn == 2; });
	printf("thread2\n");
	turn = 3;
	// 全体に通知する
	conditionVariable.notify_all();
}

void Func3() {
	std::unique_lock<std::mutex> lock(mutex);
	// 自分の番号になるまで待機
	conditionVariable.wait(lock, [] { return turn == 3; });
	printf("thread3\n");
}

int main() {
	// スレッドを同時に実行
	std::thread th1(Func1);
	std::thread th2(Func2);
	std::thread th3(Func3);

	// 表示
	th1.join();
	th2.join();
	th3.join();

	return 0;
}