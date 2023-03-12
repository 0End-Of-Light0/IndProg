#pragma once
class rational
{
private:
	int a, b;
	int gcd(int a0, int b0);
public:
	rational();
	rational(int a1, int b1);
	void set(int a1, int b1);
	void show();
};

