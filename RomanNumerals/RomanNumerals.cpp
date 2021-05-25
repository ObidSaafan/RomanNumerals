#include<iostream>
#include <string>

using namespace std;
//public variable for the number of books which were specified in the Assignment 


class MyOwnRoman
{
private:
	//Roman numerals is rn and val is the integer value of the Roman numerals
	string rn;
	int val;

public:
	//constructor
	MyOwnRoman()
	{
		rn = "";
		val = 0;
	}
	//copy constructor
	MyOwnRoman(string& RN)
	{
		rn = RN;
	}
	//set functions
	void setRomanNumerals(string RN) { rn = RN; }
	void setVal(int va) { val = va; }
	//get functions
	string getRomanNumerals() { return rn; }
	int getVal() { return val; }


	//converting Roman numberals into integer
	void convert(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{

			if (str[i] == 'B') { val = val + 900; }


			else if (str[i] == 'C') { val = val + 450; }


			else if (str[i] == 'E') { val = val + 200; }


			else if (str[i] == 'L') { val = val + 40; }


			else if (str[i] == 'X') { val = val + 15; }


			else if (str[i] == 'K') { val = val + 10; }


			else if (str[i] == 'I') { val = val + 1; }

		}


	}

	//converting integer into Roman numerals
	string revConvert(int va)
	{
		char rol[20];
		int nol = 0;
		string str = "";
		for (int i = 0; va > 0; i++)
		{
			if (va >= 900)
			{
				rol[i] = 'B';
				va = va - 900;
				nol++;
			}
			else if (va >= 450)
			{
				rol[i] = 'C';
				va = va - 450;
				nol++;
			}
			else if (va >= 200)
			{
				rol[i] = 'E';
				va = va - 200;
				nol++;
			}
			else if (va >= 40)
			{
				rol[i] = 'L';
				va = va - 40;
				nol++;
			}
			else if (va >= 15)
			{
				rol[i] = 'X';
				va = va - 15;
				nol++;
			}
			else if (va >= 10)
			{
				rol[i] = 'K';
				va = va - 10;
				nol++;
			}
			else if (va >= 1)
			{
				rol[i] = 'I';
				va = va - 1;
				nol++;
			}
		}
		for (int i = 0; i < nol; i++)
		{

			str = str + rol[i];
		}
		return str;

	}
	//print function
	void print()
	{
		cout << "The Roman Numerals are : " << rn << endl;
		cout << "The values of the Roman Numerals : " << val << endl;
	}



	bool operator == (MyOwnRoman mor)
	{
		if (val == mor.val)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (MyOwnRoman mor)
	{
		if (val != mor.val)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	MyOwnRoman operator + (MyOwnRoman mor)
	{
		int res;
		MyOwnRoman romres;

		res = val + mor.val;
		romres.setVal(res);
		romres.setRomanNumerals(romres.revConvert(res));
		return romres;
	}

	MyOwnRoman operator - (MyOwnRoman mor)
	{
		int res;
		MyOwnRoman romres;

		res = val - mor.val;
		romres.setVal(res);
		romres.setRomanNumerals(romres.revConvert(res));
		return romres;
	}
};





int main()

{
	MyOwnRoman rom1, rom2, subans, sumans;
	string srom1, srom2;
	char chro1[20], chro2[20];

	cout << "Please Enter the value of the first Roman numerals: " << endl;
	cin >> srom1;
	cout << "Please Enter the value of the second Roman numerals: " << endl;
	cin >> srom2;

	rom1.setRomanNumerals(srom1);
	rom2.setRomanNumerals(srom2);


	rom1.convert(srom1);
	rom2.convert(srom2);

	cout << "Roman 1 is: ";
	rom1.print();
	cout << endl;

	cout << "Roman 2 is: ";
	rom2.print();
	cout << endl;

	if (rom1 == rom2)
	{
		cout << "Roman1 = Roman2" << endl;
	}

	if (rom1 != rom2)
	{
		cout << "Roman1 != Roman2" << endl;
	}

	sumans = rom1 + rom2;
	subans = rom1 - rom2;

	cout << "The sum of Roman1 and Roman2 is: " << endl << sumans.getRomanNumerals() << endl << sumans.getVal();

	cout << endl;
	cout << "The subtraction of Roman1 and Roman2 is: " << endl << subans.getRomanNumerals() << endl << subans.getVal();

	return 0;
}









