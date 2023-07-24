#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> line;
typedef vector<line> canvas;


// Cursor functions
// Have to be inline 
inline void CsrMoveTo(int x, int y) // Moves cursor 'x' from the top, and 'y' from the left.
{
	printf("\x1b[%i;%iH", y, x);
}
inline void CsrMove(char direction, int n)
{
	switch (direction)
	{
	case 'u':
		printf("\x1b[%iA", n);
		break;
	case 'd':
		printf("\x1b[%iB", n);
		break;
	case 'r':
		printf("\x1b[%iC", n);
		break;
	case 'l':
		printf("\x1b[%iD", n);
		break;
	default:
		printf("Invalid Direction input in 'move' function. \n");
		break;
	}
}

class ASCIIobject
{
private:
	int numberOfColours = 8;
	int goldenRatio = (int)( (1 + sqrt(5)) * 5000000 );
public:
	canvas data;
	int dimension[2] = { 0,0 };
	string file = "null.txt";

	void load(string file)
	{
		file = file;
		ifstream newfile(file);

		string tmpString;
		canvas tmpCanvas;
		line tmpLine;

		if (newfile.is_open())
		{
			dimension[1] = 0;
			while (getline(newfile, tmpString))
			{
				dimension[0] = 0;
				while (dimension[0] < tmpString.size())
				{
					string s;
					s.push_back(tmpString[dimension[0]]);
					tmpLine.push_back(s);
					dimension[0] += 1;
				}
				tmpCanvas.push_back(tmpLine);
				tmpLine.clear();
				dimension[1] += 1; 
			}
			newfile.close();
		}
		data = tmpCanvas;
	}
	void place() // Places object where the cursor is at
	{
		for (line i : data)
		{
			for (string ii : i)
			{
				cout << ii;
			}
			cout << endl;
		}
	}
	void place( int x, int y) // Overloaded to place at coordinates
	{
		CsrMoveTo(x, y);
		for (line i : data)
		{
			for (string ii : i)
			{
				cout << ii;
			}
			cout << endl;
		}
	}
	//void paint(string colour)
	//{
	//	colour = getColour(colour);
	//}
	//void paint(char r, char g, char b)
	//{
	//	printf("\x1b[38;2;%i;%i;%i m",r,g,b);
	//	cout << "mmhmm" << endl;
	//}
};