#include<iostream>
#include <unordered_map>
#include<string>
/*
It is the implementaion of an unordered map
insertion,erase and find works on O(1) on avg

in a map stl the keys are sorted and stored but in unordered map the relative ordering is not sorted
*/

using namespace std;

int main(){

	unordered_map<string,int> um;

	um.insert(make_pair("Mango",100)); 
 
	pair<string,int>p;
	p.first="Banana";
	p.second=50;
	um.insert(p);

	um["Kiwi"]=200;



	//Search
	//1-we can take a key and using .find get an iterator if the oterator is not equal to the end to the map that means that we have found the element and we can print out the price by direct access m[key]
	string key;
	cin>>key;

	auto it=um.find(key);
	if(it!=um.end()){
		cout<<"Price of "<<key<<" "<<um[key]<<endl;
	}else{
		cout<<"Not Present"<<endl;
	}

	//2-as map stores unique keys only once so we can use count() with argument key and if key is present it will return an int 1 and if not present return int 0
	if(um.count(key)){
		cout<<"Price of "<<key<<" "<<um[key]<<endl;
	}else{
		cout<<"Not Present"<<endl;
	}


	//Delete
	um.erase(key);

	//Update
	um["Kiwi"]+=20;
	um["Banana"]=30;


	//Iterate over all the key value pairs
	um["Litchi"]=60;
	um["Mango"]=150;

	for(auto it=um.begin();it!=um.end();it++){
		cout<<it->first<<" and "<<it->second<<endl;
	}
	cout<<endl;

	//iterate using a for each loop
	for(auto p:um){
		cout<<p.first<<"="<<p.second<<endl;
	}
	return 0;
}