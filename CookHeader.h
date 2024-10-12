#define  _CRT_SECURE_NO_WARNINGS

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

#define Array vector

#define print(data) \
			cout << data << " "
#define println(data) \
			cout << data << endl
#define printArray(ary) \
			cout << "[ "; \
			for(int i = 0; i< (int)ary.size(); i++) \
				cout << ary[i] << " "; \
			cout << "]" << endl
#define printArray_(ary) \
			cout << "[ "; \
			for(int i = 0; i< (int)ary.size(); i++) \
				cout << ary[i] << " "; \
			cout << "]"
#define printArray2(ary2) \
			cout << "[ "; \
			for(int i = 0; i< (int)ary2.size(); i++) { \
				cout << "{ "; \
				for(int k = 0; k<(int)ary2[i].size(); k++) { \
					cout << ary2[i][k] << " "; \
				} \
				cout << "} "; \
			} \
			cout << "]" << endl

#define input(data, msg) \
			cout << msg; \
			cin >> data
#define del(ary, position) \
			ary.erase(ary.begin()+position)
#define len(ary) \
			(int) ary.size()

#define randomInit(start, end)  \
	random_device rd; \
	mt19937 gen(rd()); \
	uniform_int_distribution<int> cookRandom(start, end)

#define sortArray(ary) sort(ary.begin(), ary.end())
#define reverseArray(ary) reverse(ary.begin(), ary.end())
#define copyArray(source, target) target.assign(source.begin(), source.end())
#define insertArray(ary, position, data) ary.insert(ary.begin() + position, data)
#define isInArray(ary, data) find(ary.begin(), ary.end(), data) != ary.end() 
#define setArray(ary) ary.erase(unique(ary.begin(), ary.end()),ary.end())
#define removeChar(strr, chr) strr.erase(remove(strr.begin(), strr.end(), chr), strr.end())

Array <Array <int>> emptyArray2(int row, int col) {
	Array <Array <int>> ary2;
	Array <int> tmp;
	for (int i = 0; i < row; i++) {
		tmp.clear();
		for (int k = 0; k < col; k++)
			tmp.push_back(0);
		ary2.push_back(tmp);
	}
	return ary2;
}