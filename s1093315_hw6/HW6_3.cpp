#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isdyslexia(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

int main()
{
	vector<string>verb;
	string input;
	bool diamond_flag = 0;
	bool star_flag = 0;
	bool triangle_flag = 0;
	bool solid_flag = 0;
	bool hollow_flag = 0;

	cout << "Input:\n";
	while (getline(cin, input))
	{
		//string -> verb
		for (int first = 0; first <= input.length(); first++)
		{
			if (isalpha(input[first]))
			{
				for (int last = first; last <= input.length(); last++)
				{
					if (!isalpha(input[last]) || last == input.length())
					{
						verb.push_back(input.substr(first, last - first));
						first = last;
						break;
					}
				}
			}
		}

		//sorting verb
		for (int i = 0; i < verb.size(); i++)
			for (int j = i + 1; j < verb.size(); j++)
			{
				if (isdyslexia(verb[i], verb[j]))
				{
					swap(verb[++i], verb[j]);
				}
			}

		//output verb
		cout << "Output:\n";
		for (int i = 0; i < verb.size(); i++)
		{
			cout << verb[i] << " ";
			if (isdyslexia(verb[i], "diamond"))diamond_flag = true;
			else if (isdyslexia(verb[i], "star"))star_flag = true;
			else if (isdyslexia(verb[i], "triangle"))triangle_flag = true;
			else if (isdyslexia(verb[i], "solid"))solid_flag = true;
			else if (isdyslexia(verb[i], "hollow"))hollow_flag = true;

			while (i + 1 < verb.size())
			{
				if (isdyslexia(verb[i], verb[i + 1]))
				{
					cout << verb[++i] << " ";
				}
				else
				{
					cout << endl;
					break;
				}
			}
		}
		cout << endl;
		
		//output gragh
		cout << "Graph:";
		if (diamond_flag)cout << "-diamond";
		else if (star_flag)cout << "-star";
		else if (triangle_flag)cout << "-triangle";
		if (solid_flag)cout << "-solid";
		else if (hollow_flag) cout << "-hollow";
		cout << endl << endl;
		if (diamond_flag && solid_flag)
			cout << "         *\n"
			     << "        * *\n"
				 << "       * * *\n"
				 << "      * * * *\n"
				 << "     * * * * *\n"
				 << "    * * * * * *\n"
				 << "   * * * * * * *\n"
				 << "    * * * * * *\n"
				 << "     * * * * *\n"
				 << "      * * * *\n"
				 << "       * * *\n"
				 << "        * *\n"
				 << "         *\n";
		else if (diamond_flag && hollow_flag)
			cout << "         *\n"
			     << "        * *\n"
				 << "       *   *\n"
				 << "      *     *\n"
				 << "     *       *\n"
				 << "    *         *\n"
				 << "   *           *\n"
				 << "    *         *\n"
				 << "     *       *\n"
				 << "      *     *\n"
				 << "       *   *\n"
				 << "        * *\n"
				 << "         *\n";
		else if (star_flag && solid_flag)
			cout << "         *\n"
			     << "        * *\n"
				 << "       * * *\n"
				 << "* * * * * * * * * *\n"
				 << " * * * * * * * * *\n"
				 << "  * * * * * * * *\n"
				 << "   * * * * * * *\n"
				 << "  * * * * * * * *\n"
				 << " * * * * * * * * *\n"
				 << "* * * * * * * * * *\n"
				 << "       * * *\n"
				 << "        * *\n"
				 << "         *\n";
		else if (star_flag && hollow_flag)
			cout << "         *\n"
			     << "        * *\n"
				 << "       *   *\n"
				 << "* * * * * * * * * *\n"
				 << " *   *       *   *\n"
				 << "  * *         * *\n"
				 << "   *           *\n"
				 << "  * *         * *\n"
				 << " *   *       *   *\n"
				 << "* * * * * * * * * *\n"
				 << "       *   *\n"
				 << "        * *\n"
				 << "         *\n";
		else if (triangle_flag && solid_flag)
			cout << "         *\n"
			     << "        * *\n"
				 << "       * * *\n"
				 << "      * * * *\n"
				 << "     * * * * *\n"
				 << "    * * * * * *\n"
				 << "   * * * * * * *\n"
				 << "  * * * * * * * *\n"
				 << " * * * * * * * * *\n"
				 << "* * * * * * * * * *\n";
		else if (triangle_flag && hollow_flag)
			cout << "         *\n"
			     << "        * *\n"
				 << "       *   *\n"
				 << "      *     *\n"
				 << "     *       *\n"
				 << "    *         *\n"
				 << "   *           *\n"
				 << "  *             *\n"
				 << " *               *\n"
				 << "* * * * * * * * * *\n";

		//prepare for next input
		verb.clear();
		diamond_flag = false;
		star_flag = false;
		triangle_flag = false;
		solid_flag = false;
		hollow_flag = false;
		cout << "Input:\n";
	}
}
//tars, bgi, big, ibg, asrt, solid, solid, arst, zero, tras
//eat, tea, diamond, ate, monddia, eat, eat, solid