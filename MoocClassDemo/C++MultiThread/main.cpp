#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

std::mutex mu;

using std::cout;
using std::endl;
//using std::thread;

# if 0
class Factor {
public:
	void operator()(std::string& msg) {
		//for (int i = 0; i <= 100; i++) {
			cout << "factor ():" << msg << endl;
		//}
		msg = "hello";	
	}
};

class LockFile {
public:
	LockFile() {
		f.open("log.txt");
	}
	void shared_print(std::string id, int value) {
		std::lock_guard<std::mutex> locker(m_mutex);
		f << "From" << id << ":" << value << endl;
	}
protected:
private:
	std::mutex m_mutex;
	std::ofstream f;
};


void function_1(LockFile& log) {
	for (int i = 0; i > -100; i--) {
		log.shared_print("From func_1:", i);
	}
}

int main() {
	LockFile log;
	thread t1(function_1,std::ref(log));
	for (int i = 0; i < 100; i++) {
		log.shared_print("From main:", i);
	}
	
	t1.join();

	std::cin.get();
	return (0);
}
#endif

#if 1

class LogFile {
public:
	LogFile() {
		f.open("log.txt");
	}

	void shared_print(std::string id, int value) {
		std::lock(m_mutex, m_mutex2);
		std::lock_guard<std::mutex> locker(m_mutex,std::adopt_lock);
		std::lock_guard<std::mutex> locker2(m_mutex2,std::adopt_lock);
		cout<< "From" << id << ": " << value << endl;
	}	
	void shared_print2(std::string id, int value) {
		std::lock(m_mutex, m_mutex2);
		std::lock_guard<std::mutex> locker2(m_mutex2, std::adopt_lock);
		std::lock_guard<std::mutex> locker(m_mutex, std::adopt_lock);
		cout << "From" << id << ": " << value << endl;
	}
	//std::ofstream& GetStream() {
	//	return f;
	//}
	//void processf(void fun(std::ofstream&)) {
	//	fun(f);
	//}
protected:
private:
	std::mutex m_mutex;
	std::mutex m_mutex2;
	std::ofstream f;
};

void function_1(LogFile& log) {
	for (int i = 0; i > -100; i--) {
		log.shared_print("From func1:", i);
	}
}

class Fctor {
public:
	void operator()(std::string& msg) {
		cout <<"From t1: " << msg << endl;
		msg = "t1 finished...";
	}
};

int main() {
	/*
	//Fctor fct;
	std::string s = "Main's s";
	//std::thread t1((Fctor()),s);// t1线程开始执行
	std::thread t1((Fctor()),std::ref(s));// t1线程开始执行
	cout << std::this_thread::get_id() << endl;
	//std::thread t2 = std::move(t1);
	t1.join();
	cout << "from main: " << s << endl;
	cout << std::thread::hardware_concurrency() << endl;
	*/

	LogFile log;
	std::thread t1(function_1, std::ref(log));
	for (int i = 0; i < 50; i++) {
		log.shared_print2("From main:", i);
	}
	t1.join();
	return 0;
}
#endif