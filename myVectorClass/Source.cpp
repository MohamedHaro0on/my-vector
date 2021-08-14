#include<string>
#include"myVector.cpp"


using std::string;


class student {  
public :
	string firstName, lastName;
	size_t age;

	student(string fname = " ", string lname= " ", size_t a = 0) : firstName(fname), lastName(lname), age(a) {

	};
	~student() {
		cout << "destroy" << endl;
	}
};
void printStudent (myVector<student> &list){
	for (size_t i = 0 ; i < list.getSize() ; i ++ ){
		cout << list[i].firstName << " " << list[i].lastName << " " << list[i].age << endl;
	}
}
 
int main() {
	myVector <student> studentVect(10);
	studentVect.emplaceBack("firstName", "lastName", 10);
	studentVect.emplaceBack("firstName", "lastName", 10);
	studentVect.emplaceBack("firstName", "lastName", 10);
	studentVect.emplaceBack("firstName", "lastName", 10);
	studentVect.emplaceBack("firstName", "lastName", 10);
	studentVect.emplaceBack("firstName", "lastName", 10);
	printStudent(studentVect);

	myVector <int> intVect;
	intVect.push_back(10);
	intVect.push_back(10);
	intVect.push_back(10);
	cout << intVect.getSize() << "   " << intVect.getMaxSize() << endl;
	intVect.push_back(10);
	intVect.push_back(10);
	intVect.print();

	myVector <string> stringVect(10);
	stringVect.push_back("Mohamed");
	stringVect.push_back("Mohamed");
	stringVect.push_back("Mohamed");
	stringVect.push_back("Mohamed");
	stringVect.push_back("Mohamed");
	stringVect.push_back("Mohamed");
	stringVect.push_back("Mohamed");

	return 0;
}