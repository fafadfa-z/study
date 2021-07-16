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


std::mutex mut;                       // ������������

std::queue<data_chunk> data_queue;

std::condition_variable data_cond;    // ��������


void data_preparation_thread()        //  
{
	while (more_data_to_prepare())
	{
		data_chunk const data = prepare_data();
		std::lock_guard<std::mutex> lk(mut);     // �ڶ���Ҫ���в�����ʱ�����������
		data_queue.push(data);                   // 
		data_cond.notify_one();                  // ���ȴ��߳����»�ȡ���������������ʱ�����������ֱ����Ӧ��һ���̵߳�֪ͨ���������ν�ġ�α���ѡ�
	}
}
void data_processing_thread()
{
	while (true)
	{
		std::unique_lock<std::mutex> lk(mut);                  // 
		data_cond.wait(lk, [] {return !data_queue.empty(); }); // lock_guard �����ڴ���wait �ڲ��󣬷����ȴ�ʱ�������ܽ��������ͷţ�
		data_chunk data = data_queue.front();
		data_queue.pop();
		lk.unlock();                                           // �����ھֲ�������û�����ٵ�ʱ���Ƚ����������Ĳ��� lock_guard �����ǲ����Եġ�
		process(data);
		if (is_last_chunk(data))
			break;
	}
}
#endif