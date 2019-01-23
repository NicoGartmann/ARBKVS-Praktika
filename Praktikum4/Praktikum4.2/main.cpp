#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
void a()
{
	mtx.lock();
	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << char(i) << endl;
	}
	mtx.unlock();
}

void b()
{
	mtx.lock();
	for (int i = 0; i <= 32; i++)
	{
		cout << i << endl;
	}
	mtx.unlock();
}

void c()
{
	mtx.lock();
	for (int i = 'A'; i <= 'Z'; i++)
	{
		cout << char(i) << endl;
	}
	mtx.unlock();
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