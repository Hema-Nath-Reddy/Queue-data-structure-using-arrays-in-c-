#include<iostream>
using namespace std;
class queue{
	int front=-1;
	int rear=-1;
	int size=0;
	bool isFull(){
		if(rear==size-1){
			return true;
		}
		return false;
	}
	bool isEmpty(){
		if(front==-1&&rear==-1){
			return true;
		}
		return false;
	}
	public:
		queue(int s){
			size=s;
		}
		void enqueue(int arr[]){
			if(isFull()){
				cout<<"Queue is full."<<endl;
			}else{
				int element;
				cout<<"Enter the element: ";
				cin>>element;
				if(isEmpty()){
					front=0;
					rear=0;
				}else{
					rear++;
				}
				arr[rear]=element;
				cout<<"Enqueue successful."<<endl;
			}
		}
		void dequeue(int arr[]){
			if(isEmpty()){
				cout<<"Queue is empty."<<endl;
			}else{
				int element=arr[front];
				if(front==rear){
					front=-1;
					rear=-1;
				}else{
					front++;
				}
				cout<<element<<" has been dequeued."<<endl;
			}
		}
		void display(int arr[]){
			if(isEmpty()){
				cout<<"Queue is empty."<<endl;
			}else{
				cout<<"The queue is: "<<endl;
				for(int i=front;i<=rear;i++){
					cout<<arr[i]<<endl;
				}
			}
		}
};
int main(){
	int size;
	cout<<"Enter the size of the queue: ";
	cin>>size;
	if(size<=0){
		do{
			cout<<"The size of the stack cannot be less than or equal to zero."<<endl<<"Please enter a valid size: ";
			cin>>size;
		}while(size!=0);
	}
	int arr[size];
	queue q(size);
	int choice;
	cout<<"Only a maximum of "<<size<<" elements can be queued."<<endl;
	do{
		cout<<endl<<"1. Enqueue an element."<<endl;
		cout<<"2. Dequeue an element."<<endl;
		cout<<"3. Display the queue."<<endl;
		cout<<"4. Exit."<<endl;
		cout<<"Choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				q.enqueue(arr);
				break;
			case 2:
				q.dequeue(arr);
				break;
			case 3:
				q.display(arr);
				break;
			case 4:
				cout<<"Exited.";
				break;
			default:
				cout<<"Enter your choice from 1 to 4."<<endl;
				break;
		}
	}while(choice!=4);
	return 0;
}
