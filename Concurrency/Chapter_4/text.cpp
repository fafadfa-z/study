#include<iostream>
#include<mutex>
#include<condition_variable>
#include<queue>


typedef int data_chunk;


using namespace std;
#if 0
bool prepare_data();
bool more_data_to_prepare();
void process(data_chunk);
bool is_last_chunk(data_chunk);


std::mutex mut;                       // 声明互斥量。

std::queue<data_chunk> data_queue;

std::condition_variable data_cond;    // 条件变量


void data_preparation_thread()        //  
{
	while (more_data_to_prepare())
	{
		data_chunk const data = prepare_data();
		std::lock_guard<std::mutex> lk(mut);     // 在队列要进行操作的时候进行上锁。
		data_queue.push(data);                   // 
		data_cond.notify_one();                  // 当等待线程重新获取互斥量并检查条件时，如果它并非直接响应另一个线程的通知，这就是所谓的“伪唤醒”
	}
}
void data_processing_thread()
{
	while (true)
	{
		std::unique_lock<std::mutex> lk(mut);                  // 
		data_cond.wait(lk, [] {return !data_queue.empty(); }); // lock_guard 类型在传入wait 内部后，发生等待时，并不能将互斥锁释放，
		data_chunk data = data_queue.front();
		data_queue.pop();
		lk.unlock();                                           // 可以在局部变量还没有销毁的时候先解锁，这样的操作 lock_guard 好像是不可以的。
		process(data);
		if (is_last_chunk(data))
			break;
	}
}
#endif