#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "factory.h"
#include "rbTree.h"
using namespace std;

class file
{
public:
	void printFile(string filename) const
	{
		try
		{
			ifstream in(filename);
			string n;
			while (getline(in, n)) {
				cout << n << endl;
			}
		}
		catch (...)
		{
			cout << "ERROR" << endl;
		}

	}
	static int cmp(const char* a, const char* b)
	{
		for (int i = 0; i < 20; i++)
		{
			if (a[i] < b[i])
			{
				return -1;
			}
			if (a[i] > b[i])
			{
				return 1;
			}

		}
		return 0;
	}
	static void textToBin(string in, string out) {

		fstream inn(in);
		ofstream o(out, ios_base::binary);
		factory tt;

		char k;
		while (inn >> tt.vol)
		{
			inn.get(k);
			for (int i = 0; i < 20; i++) {
				inn.get(tt.name[i]);
			}
			
			for (int i = 0; i < 20; i++) {
				inn.get(tt.product[i]);
			}
			//inn.get(k);
			//inn.get(k);
			cout << tt << endl;
			o.write(reinterpret_cast<const char*>(&tt), sizeof(tt));
		}
		o.close();
		inn.close();

	}

	static void printBin(string  i) {
		ifstream in(i, ios_base::binary);
		factory tt;
		while (!in.eof())
		{
			in.read(reinterpret_cast<char*>(&tt), sizeof(tt));
			if (!in.eof()) {
				for (int i = 0; i < 20; i++) {
					cout<<(tt.name[i]);
				}
				for (int i = 0; i < 20; i++) {
					cout << (tt.product[i]);
				}
				cout << tt.vol << endl;
			}
		}
		in.close();
	}

	static void getDataBin(string& in, int n, factory& t) {
		ifstream f(in, ios::binary);
		factory qqq;
		if (f.is_open()) {
			f.seekg(n * sizeof(qqq), ios::beg);
			f.read((char*)&t, sizeof(qqq));
		}
		f.close();
	}


	static int getCountLineBin(string inn) {
		ifstream in(inn, ios_base::binary);
		factory tt;
		int q = 0;
		while (!in.eof()){
			in.seekg(q * (int)sizeof(tt), ios::beg);
			in.read((char*)&tt, sizeof(tt));
			q++;
		}
		in.close();
		return q - 1;
	}

	static void delDataBin(string& fi, int numinHash) {
		fstream file(fi, ios::binary | ios::out | ios::in);
		factory deleted;

		file.seekg((numinHash) * sizeof(deleted), ios::beg);
		file.write((char*)&deleted, sizeof(factory));
		file.close();
	}

	static void writeTonPlace(string& f, factory& t) {
		fstream file(f, ios::binary | ios::out | ios::in);
		int ge = getCountLineBin(f);
		if (file.is_open()) {
			file.seekg((ge) * sizeof(factory), ios::beg); ///!!!!!!!!!!! TUT MB PROBLEMA S +-1
			file.write((char*)&t, sizeof(factory));
		}
		file.close();
	}

	static void find_factory(string& in, char* key, factory& t)
	{
		ifstream inn(in, ios_base::binary);
		while (inn.read((char*)&t, sizeof(factory)))
		{
			if(file::cmp(key,t.name)==0)
			{
				return;
			}
		}
	}

	static void print_on_n(int n, string file)
	{
		factory tt;
		getDataBin(file, n, tt);
		for (int i = 0; i < 20; i++) {
			cout << (tt.name[i]);
		}
		for (int i = 0; i < 20; i++) {
			cout << (tt.product[i]);
		}
		cout << tt.vol << endl;

	}
};





