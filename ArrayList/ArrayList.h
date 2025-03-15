#include<iostream>
using namespace std;
class ArrayList
{
	private :
		//int *arr=new int (size);
		int *arr;
		//arr=new int(size)
		int capacity;
		int currentIndex;
	public:
		ArrayList(int capacity=5)//combined constructor local and parametrized 
		{
			this->capacity=capacity;
			this->currentIndex=0;
			arr=new int[capacity];
		}//constructor
		void insert(int dataElement);
		void insertAt(int index,int dataElement);
		void resize();
		int getCapacity();
		void display();
		void removeAt(int index);
		bool linearSearch (int dataElement);
		bool BinarySearch(int dataElement);
		int largestValue (int range);
		void swap(int index1,int index2);
		void selectionSort();
		//	int largest ();
		void bubbleSort();
		void insertionSort();
		
			
		
};
//Implementation as .cpp(code below this line can be moved to a seperate file with filename ArrayList.cpp
void ArrayList::insert(int dataElement)
{
	if(currentIndex==capacity)
	//	cout<<"Array out of bound\n";
		resize();
//	else //we have vacant slots means we can insert data
//	{
		arr[currentIndex]=dataElement;
		currentIndex++;
//	}
}//insert
void ArrayList::insertAt(int index,int dataElement)
{
	if(index<0 || index>currentIndex)
	{
		cout<<"Invalid index\n";
		return;
	} //if
	else if (currentIndex==capacity)
	{
		resize();
	}  //else if
//	else
//	{
		for(int i=currentIndex;i>index;i--)
		{
			arr[i]=arr[i-1];
		}  //for
		arr[index]=dataElement;
		currentIndex++;
 // }
}//insert at
void ArrayList::resize()
{
	int newCapacity=capacity*2;
	int *newArr=new int[newCapacity];
	for(int i=0 ; i<currentIndex ;i++)
	{
		newArr[i]=arr[i];
	} //for 
	delete[]arr;
	arr=newArr;
	capacity=newCapacity;
	
} //resize
int ArrayList::getCapacity()
{
	return capacity;
} // capacity
void ArrayList::display()
{
	for(int i=0;i<currentIndex;i++)
	{
		cout<<arr[i];
		cout<<" ";
	} //for i
} //display
void ArrayList::removeAt(int index)
{
		if(index<0 || index>currentIndex)
	{
		cout<<"Invalid index\n";
		return;
	} //if 
	
	for (int i=index;i<currentIndex-1;i++ )
	{
		arr[i]=arr[i+1];
	} // for i
	currentIndex--;
} //remove at
bool ArrayList::linearSearch(int dataElement)
{
	int i=0;
	while(i<currentIndex&& arr[i]!=dataElement)
	{
		i++;
	}  //while i
	if (i==currentIndex)
	{
		return false;
	}  //if
	else
	{
		return true;
	} //else
}  //linear search
bool ArrayList::BinarySearch(int dataElement)
{
	int b=0;
	int e=currentIndex;
	int mid;
	while(b<=e)
	{
		mid=(e+b)/2;
		if(dataElement==arr[mid])
		{
			return true;
		} //if
		else if (dataElement<arr[mid])
		{
			e=mid-1;
		} // else if
		else
		{
			b=mid+1;
			
		} //else
	} //while i
	return false;
} // binary search
int ArrayList::largestValue(int range)
{
	//int large=arr[0];
	int max=0;//index of largest value
	for(int i=1;i<=range;i++)
	{
		if(arr[i] > arr[max])
		{
			
		//	large=arr[i];
			max=i;
			
		} //if
	}  //for i
	return max;
}  // largest
void ArrayList::swap(int index1,int index2)
{
	
	int temp=arr[index1];
	arr[index1]=arr[index2];
	arr[index2]=temp;
}  //swap
/*int ArrayList::largest()
{
	int large=arr[0];
//	int max=0;//index of largest value
	for(int i=1;i<currentIndex;i++)
	{
		if(arr[i] > arr[max])
		{
			
		large=arr[i];
		//	max=i;
			
		} //if
	}  //for i
	return large;
} // largest value 
*/
void ArrayList::selectionSort()
{
	for(int j=currentIndex-1;j>0;j--)
	{
		// Finding largest
		int max=largestValue(j);
		swap(max,j);
	}
}// select sort
void ArrayList :: bubbleSort()
{
	for (int j=currentIndex-1;j>0;j-- )
	{
		bool isSorted=true;
		for(int i=0;i<j;i++)
		{
			if(arr[i]>arr[i+1])
			{
				//ap(i,i+1);
				int temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				isSorted=false;
				
			}//if
			
		}//for i
		if(isSorted)
		{
			return;
		}//if 
	}//for j
}// bubble sort
void ArrayList::insertionSort()
{
	for(int i=1;i<currentIndex;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}//while j
		arr[j+1]=key;
	}//for i
}//insertion sort