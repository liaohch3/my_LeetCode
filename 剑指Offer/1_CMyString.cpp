#include <iostream>
using namespace std;
 
class CMyString {
private:
	char* ptr;
	void helper(const char* p = NULL){
		if(p == NULL){
			ptr = NULL;
		}else{
			int len = 0;
			while(p[len] != 0){
				len++;
			}
			ptr = new char[len+1];
			for(int i = 0; i < len; i++)
				ptr[i] = p[i];
			ptr[len] = 0;
		}
	}
	void deleteMyself(){
		if(ptr != NULL){
			delete[] ptr;
			ptr = NULL;
		}
	}
public:
	CMyString(const char* p = NULL) {
		helper(p);
	}
	CMyString(const CMyString& str) {
		helper(str.ptr);
	}
	friend ostream& operator<<(ostream& out, CMyString& str);
	CMyString& operator=(const CMyString& str){
		if(&str == this)
			return *this;
		deleteMyself();
		helper(str.ptr);
		return *this;
	}
	int getLen()const{
		int len = 0;
		while(ptr[len] != 0){
			len++;
		}
		return len;
	}
	~CMyString() {
		deleteMyself();
	}
	void Print();
};

ostream& operator<<(ostream& out, CMyString& str){
	out << str.ptr;
	return out;
}
 
// ====================测试代码====================
void CMyString::Print()
{
    printf("%s", ptr);
}

void Test1()
{
    printf("Test1 begins:\n");

    const char* text = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// 赋值给自己
void Test2()
{
    printf("Test2 begins:\n");

    const char* text = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    const char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}