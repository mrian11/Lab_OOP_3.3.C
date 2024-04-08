///////////////////////////////////////////////////
//Charline.h
#pragma once
#include <string>
#include "Object.h"
using namespace std;
class CharLine : public Object
{
private:
	int N;
	char* s;
public:

	CharLine();
	CharLine(int N, const char* s);
	CharLine(const CharLine& r);
	~CharLine();

	int getN()const { return this->N; }
	char* getS()const { return this->s; }

	void setN(int value);
	void setS(const char* value);

	CharLine& operator =(const CharLine& r);

	operator string() const;

	friend bool operator==(const CharLine&, const CharLine&);
	friend bool operator!=(const CharLine&, const CharLine&);
	friend bool operator<=(const CharLine&, const CharLine&);
	friend bool operator>=(const CharLine&, const CharLine&);
	friend bool operator>(const CharLine&, const CharLine&);
	friend bool operator<(const CharLine&, const CharLine&);

	friend ostream& operator << (ostream&, const CharLine&);
	friend istream& operator >> (istream&, CharLine&);

	CharLine& operator ++();
	CharLine& operator --();
	CharLine operator ++(int);
	CharLine operator --(int);

	char operator[](int position)const;

	bool operator()(char targetChar);

	friend CharLine operator+(const CharLine&, const CharLine&);

	friend bool operator % (const CharLine&, const CharLine&);

};