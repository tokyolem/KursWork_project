#pragma once
#include <vector>
#include <algorithm>
#include <QString>

using namespace std;

class Page
{
public:
	virtual void update_window() = 0;
	static int get_min_nonexist(vector<int> vect);
};
