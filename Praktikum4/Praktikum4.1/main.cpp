#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void a()
{

	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << char(i) << endl;
	}
}

void b()
{
	for (int i = 0; i <= 32; i++)
	{
		cout << i << endl;
	}
}

void c()
{
	for (int i = 'A'; i <= 'Z'; i++)
	{
		cout << char(i) << endl;
	}
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