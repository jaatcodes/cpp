#include<iostream>
// simillar to doubly linked list
#include<list>
using namespace std;

/*List STL
-front() points at first element
-back() points at last element
-push_back() add at end 
-push_front() add at start
-pop_back() remove end
-pop_front() remove start
-insert() insert at middle
-erase(idx)
-remove()
*/

int main(){
		//create a list 
		list<int> l;

		//initalize list with values
		list<int> num{1,2,3,10,8,5};
		//list of different data types
		list<string>fruits{"mango","apple","banana"};
		//insert at tail
		fruits.push_back("orange");
		//insert at begining
		fruits.push_front("kivi");

		// we can also sort the list from the inbuild sort function in list stl
		fruits.sort();

		// can also reverse the ordering
		fruits.reverse();

		//remove element from front
		cout<<fruits.front()<<endl;
		fruits.pop_front();

		//remove the last element
		cout<<fruits.back()<<endl;
		fruits.pop_back();

		//iterate using iterators
		for (auto it=fruits.begin();it!=fruits.end();it++){
			cout<<(*it)<<" ->";
		}
		cout<<endl;


		fruits.push_back("mellon");
		fruits.push_back("watermellon");
		fruits.push_back("grapes");
		fruits.push_back("strawberries");
		fruits.push_back("mango");

		//remove a element from its value
		//we have 2 mango in ours list if we call remove it will remove both the occurence of mango
		fruits.remove("mango");

		
		for(auto i:fruits)
			cout<<i<<"-->";
		cout<<endl;




		//erase one or more elements from a list from a particular postion
		auto it=fruits.begin();
		// let us say we want to remove the 3rd fruit
		//we need to move the iterator by it++ and not by doing it=f.begin()+k as our data in not in a linear orders
		for(int i=1;i<3;i++)
			it++;
		fruits.erase(it);


		// we can also add aparticular element at a particulatr position
		it=fruits.begin();
		//lets say we want to add an element after the first postion
		it++;
		fruits.insert(it,"Lichi");

// iterate over the list and int the data
		for(auto i:fruits)
			cout<<i<<"-->";


	return 0;
}