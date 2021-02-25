#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

std::mutex mu;

using std::cout;
using std::endl;
using std::thread;

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