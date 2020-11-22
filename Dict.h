#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T, class U>
class Dict {
	public:
		U get(T key){
			for(int i = 0; i < keys.size(); i++){
				if(keys[i] == key){
					return values[i];
				}
			}
			U u;
			return u;
		}

		bool has_key(T key){
			for(int i = 0; i < keys.size(); i++){
				if(keys[i] == key){
					return true;
				}
			}
			return false;
		}

		void add(T key, U val){
			keys.push_back(key);
			values.push_back(val);
		}

	private:
		vector<T > keys;
		vector<U > values;
};

/*
   struct Move {
   string add_rem;
   int x;
   int y;
   bool operator==(const Move& other) const {
   return (add_rem == other.add_rem) &&
   (x == other.x) && (y == other.y);
   }
   };

   int main(){
   vector<int> dv = {0, 1};
   Move dm = {"ADD", 0, 0};
   dict<vector<int>, double> my_dict1;
   my_dict1.add(dv, 10);
   dict<Move, vector<int> > my_dict2;
   my_dict2.add(dm, dv);

   return 0;
   }
 */
