#include "opencv2\opencv.hpp"
#include <memory>
#include <cstring>
#include <iostream>



using namespace std;

/*This class for move constructor */

class BaseCam
{
public:
	BaseCam();
	~BaseCam() noexcept;
	BaseCam(const BaseCam& obj);
	BaseCam(BaseCam && newObj) noexcept;

private:
public:
	int flag = 0;
	char * data;

};

BaseCam::BaseCam(): data( new char[14])
{
	data = "Hello, World!";
}

BaseCam::~BaseCam() noexcept
{
	
}

BaseCam::BaseCam(const BaseCam & obj){

	data =  obj.data;

}

BaseCam::BaseCam(BaseCam && newObj) noexcept : data(newObj.data)
{
	newObj.data = nullptr;
}

class MyClass
{
public:
	MyClass();
	~MyClass();

public:
	vector<BaseCam> mCameras;
public:
	void Running();


};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

void MyClass::Running()
{
	

	for (unsigned int id = 0; id < 10; id++) {

		BaseCam tmp;
		tmp.flag = 10;
		

		mCameras.push_back(tmp);
		mCameras[id].data = "new data";
		

		cout << tmp.data << endl;
	}
}


int main(void) {

	MyClass mClass;
	mClass.Running();

	for (unsigned int id = 0; id < 10; id++) {
		cout << mClass.mCameras[id].data << std::endl;
		cout << "flag: " << mClass.mCameras[id].flag << std::endl;
		cout << endl;
	}

	system("pause");

	return 0;
}