#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore
{
private:
	mutex mtx;
	condition_variable cv;
	int count;

public:
	Semaphore(int count_ = 0)
	{
		count = count_;
	}

	void notify(int tid) {
		unique_lock<mutex> lock(mtx);
		count++;
		cout << "thread " << tid << " notify" << endl;
		//notify the waiting thread
		cv.notify_one();
	}
	void wait(int tid) {
		unique_lock<mutex> lock(mtx);
		while (count == 0) {
			//wait on the mutex until notify is called
			cv.wait(lock);
			cout << "thread " << tid << " run" << endl;
		}
		count--;
	}
};


Semaphore s;

void a()
{
	s.wait(1); 
	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << char(i) << endl;
	}
	s.notify(1);
}

void b()
{

	s.wait(2);
	for (int i = 0; i <= 32; i++)
	{
		cout << i << endl;
	}

	s.notify(2);
}

void c()
{

	s.wait(3);
	for (int i = 'A'; i <= 'Z'; i++)
	{
		cout << char(i) << endl;
	}
	s.notify(3);
}


int main()
{
	thread t1(a);
	thread t2(b);
	thread t3(c);

	t1.join();
	t2.join();
	t3.join();

	system("Pause");
	return 0;

}