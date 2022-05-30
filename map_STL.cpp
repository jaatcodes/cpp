#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	//it is a key value pair data stucture
	map<string,int> m;

	//INSERT
	m.insert(make_pair("Apple",120));

	pair<string,int>p;
	p.first="Banana";
	p.second=50;
	m.insert(p);

	m["Kiwi"]=200;


	//Search
	//1-we can take a key and using .find get an iterator if the oterator is not equal to the end to the map that means that we have found the element and we can print out the price by direct access m[key]
	string key;
	cin>>key;

	auto it=m.find(key);
	if(it!=m.end()){
		cout<<"Price of "<<key<<" "<<m[key]<<endl;
	}else{
		cout<<"Not Present"<<endl;
	}

	//2-as map stores unique keys only once so we can use count() with argument key and if key is present it will return an int 1 and if not present return int 0
	if(m.count(key)){
		cout<<"Price of "<<key<<" "<<m[key]<<endl;
	}else{
		cout<<"Not Present"<<endl;
	}


	//Delete
	m.erase(key);

	//Update
	m["Kiwi"]+=20;
	m["Banana"]=30;


	//Iterate over all the key value pairs
	m["Litchi"]=60;
	m["Mango"]=150;

	for(auto it=m.begin();it!=m.end();it++){
		cout<<it->first<<" and "<<it->second<<endl;
	}
	cout<<endl;
	//iterate using a for each loop
	for(auto p:m){
		cout<<p.first<<"="<<p.second<<endl;
	}

	return 0;
}