#include <random>

using namespace std;

class Random
{
public:
	int getInt(int min, int max);
	Random();
	~Random();
private:
	random_device _rd;
};