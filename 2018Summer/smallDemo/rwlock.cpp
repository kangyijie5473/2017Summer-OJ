#include <iostream>
#include <pthread.h>
using namespace std;
class rwlock
{
public:
	rwlock();
	~rwlock();
	int readLock();
	int readUnlock();
	int writeLock();
	int writeUnlock();

private:
	pthread_mutex_t read_lock;
	pthread_mutex_t write_lock;
	int reader_count;
};
rwlock::rwlock()
{
	read_lock = PTHREAD_MUTEX_INITIALIZER;
	write_lock = PTHREAD_MUTEX_INITIALIZER;
	reader_count = 0;
}
rwlock::~rwlock()
{
	pthread_mutex_destroy(&read_lock);
	pthread_mutex_destroy(&write_lock);
}
int rwlock::readLock()
{

	pthread_mutex_lock(&read_lock);
	reader_count++;

	pthread_mutex_lock(&write_lock);
	pthread_mutex_unlock(&read_lock);
}
int rwlock::readUnlock()
{
	reader_count--;
	if (reader_count == 0)
		pthread_mutex_unlock(&write_lock);
	//pthread_mutex_unlock(&read_lock);

}
int rwlock::writeLock()
{
	pthread_mutex_lock(&write_lock);
}
int rwlock::writeUnlock()
{
	pthread_mutex_unlock(&write_lock);
}
int main(int argc, char const *argv[])
{
	
	return 0;
}