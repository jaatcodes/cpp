#include<iostream>
#include<queue>
// Based on FIFO principle

using namespace std;

int main(){

	queue<int> q;//iniatialize the queue

	for(int i=1;i<=5;i++){
		q.push(i);//add the element 
	}
	cout<<q.size()<<endl;//get the size of the queue
	cout<<q.front()<<endl;//get the front element of the queue
	cout<<q.back()<<endl;//get the last element of the queue

	while(!q.empty()){
		cout<<q.front()<<"<-";
		q.pop();//remove the first element of the queue
	}

	return 0;
}