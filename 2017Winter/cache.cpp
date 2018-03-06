#include <iostream>
#include <list>
#include <utility>
using namespace std;
class Cache{
public:
	typedef std::pair<std::string,std::string> Pair;
	typedef std::list<std::pair<std::string,std::string>> List;
	typedef std::string Key;
	typedef std::string Value;

	explicit Cache(int max_size):max_node_nums(max_size){}
	bool set(Pair &pair){
		for(auto i = list.begin(); i != list.end(); i++){
			if(pair.first == i->first){
				list.erase(i);
				list.push_back(pair);
				return true;
			}
		}

		if(list.size() == max_node_nums){
			list.pop_front();
			list.push_back(pair);
			return false;
		} else{
			list.push_back(pair);
			return true;			
		}
	}
	Value get(const Key &key){
		Value value;
		for(auto i = list.begin(); i != list.end(); i++){
			if(i->first == key){
				value = i->second;
				Pair pair = *i;
				list.erase(i);
				list.push_back(pair);
				return value;
			}
		}
		return value;
	}
private:
	List list;
	int max_node_nums;
};
int main()
{	
	typedef std::pair<std::string,std::string> Pair;
	typedef std::string Key;
	typedef std::string Value;
	Cache cache(3);
	Pair p1("myname", "kangyijie");
	Pair p2("hisname", "wang");
	Key key("hisname");
	cache.set(p1);
	cache.set(p2);
	cout << cache.get("myname") << endl;

}