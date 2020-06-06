#pragma once
#include<string>
using namespace std; 
class Transa
{
private:  
	string id; 

public: 
	Transa(string id_) {
		if (id_.size() == 15) { // validar desde afuera para no crear el objeto por gusto 
			this->id = id_;
		}
		
	}

	inline string getId() { return this->id;  }
};

