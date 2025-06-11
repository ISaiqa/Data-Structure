#include<iostream>
#include"C:\Users\abc\OneDrive\Desktop\3rd sem\Data Structure\LinkedQueue\LinkedQueue.h"
#include"Process.h"
using namespace std;
template <class T>
class ProcessQueue : public LinkedQueue<T>
{
	public:
		void createProcess();
};
template <class T>
void Pro