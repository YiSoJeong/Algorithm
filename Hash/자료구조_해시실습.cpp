#include<iostream>
#include<algorithm>
#include<vector>

#define div 65537
#define div2 17

using namespace std;

class item
{
public:
	int value;
	int key;
	item(){}
	item(int key, int value)
	{
		this->key = key;
		this->value = value;
	}
};

class hash_array
{
private:
	bool* flag;
	item* data;
public:
	hash_array(int sz)
	{
		this->flag = new bool[sz + 1];
		this->data = new item[sz + 1];
	}

	int hash_code(int key)
	{
		return key % div;
	}

	int hash_code_2(int key)
	{
		return div2 - key % div2;
	}

	void linear_probing(int key, int value)
	{
		int index = hash_code(key);
		int i = index;
		while (flag[i] == true)
		{
			if (data[i].key == key)
			{
				data[i].value = value;
				return;
			}
			i = (i + 1) % div;
			if (i == index) return;
		}
		flag[i] = true;
		item ins(key, value);
		data[i] = ins;
		return;
	}

	item* linear_search(int key, int value)
	{
		item* ret = NULL;
		int index = hash_code(key);
		int i = index;
		while (flag[i] == true)
		{
			if (data[i].key == key)
			{
				if (data[i].value == value)
				{
					ret = &data[i];
					break;
				}
			}
			i = (i + 1) % div;
			if (i == index) break;
		}
		return ret;
	}

	void double_hashing(int key, int value)
	{

		int code1 = hash_code(key);
		int code2 = hash_code_2(key);
		int i = code1;
		while (flag[i] == true)
		{
			if (data[i].key == key)
			{
				data[i].value = value;
			}
			i = (i + code2) % div;
			if (i == code1) return;
		}
		flag[i] = true;
		item ins(key, value);
		data[i] = ins;
	}

	item* double_hashing_search(int key, int value)
	{
		item* ret = NULL;
		int code1 = hash_code(key);
		int code2 = hash_code_2(key);
		int i = code1;
		while (flag[i] == true)
		{
			if (data[i].key == key)
			{
				if (data[i].value == value)
					ret = &data[i];
			}
			i = (i + code2) % div;
			if (i == code1) break;
		}
		return ret;
	}
};

