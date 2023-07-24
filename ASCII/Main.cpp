#include "Test2.h"
#include "TextEffects.h"

int main()
{
	//cout << "works?";
	//CsrMove('l', 1);
	//cout << "!" << endl;
	//Pobject pika;
	//pika.load("pika.txt");
	//pika.place(0, 2);
	//CsrMove('d', 2);
	//Pobject canvas;
	//canvas.load("canvas.txt");
	//canvas.place();
	//string colour;
	//bool bright;
	//bool background;
	//while (true)
	//{	
	//	cout << endl << "colour :";
	//	cin >> colour;
	//	cout << endl << "bright? :";
	//	cin >> bright;
	//	cout << endl << "background? :";
	//	cin >> background;
	//	getColour(colour, bright, background);
	//}
	//CsrMoveTo(0, 0);
	//int mod;
	//cin >> mod;
	//cout << endl;
	string color[8] = { "black","red","green","yellow","blue","magenta","cyan","white" };
	for (int i = 0; i < 8; i++)
	{
		cout << getColour(color[i], 1, 1) << "bruh" << "\x1b[0m" << endl;
		cout << getColour(color[i], 1, 0) << "bruh" << "\x1b[0m" << endl;
		cout << getColour(color[i], 0, 1) << "bruh" << "\x1b[0m" << endl;
		cout << getColour(color[i], 0, 0) << "bruh" << "\x1b[0m" << endl;
	}
	
	SGRCodeTest();

	cout << "\x1b[48;2;255;0;255m" << "hello" << endl;

	cout << endl << endl;

	int r, g, b;
	char const* hexColor = "#8060c2";
	sscanf(hexColor, "#%02x%02x%02x", &r, &g, &b);

	cout << r << g << b << endl;

	return 0;
}