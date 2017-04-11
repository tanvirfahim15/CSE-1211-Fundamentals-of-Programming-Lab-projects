#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include <time.h>
#include <sstream>
sf::RenderWindow window(sf::VideoMode(900, 500), "MINIONS");
sf::Texture mnntex;
sf::Sprite mnnimg;
sf::Texture brk1tex;
sf::Sprite brk1img;
sf::Texture brk2tex;
sf::Sprite brk2img;
sf::Texture brk3tex;
sf::Sprite brk3img;
sf::Text point;
sf::Text pt;
sf::Texture bn1tex;
sf::Sprite bn1img;
sf::Texture bn2tex;
sf::Sprite bn2img;
sf::Texture bn3tex;
sf::Sprite bn3img;
sf::Texture bn4tex;
sf::Sprite bn4img;
sf::Texture bn5tex;
sf::Sprite bn5img;
sf::Texture bn6tex;
sf::Sprite bn6img;
sf::Texture bn7tex;
sf::Sprite bn7img;
sf::Texture bn8tex;
sf::Sprite bn8img;
sf::Texture bn9tex;
sf::Sprite bn9img;
sf::Texture bn10tex;
sf::Sprite bn10img;
sf::Texture bn11tex;
sf::Sprite bn11img;
sf::Texture bn12tex;
sf::Sprite bn12img;
sf::Texture bn13tex;
sf::Sprite bn13img;
sf::RectangleShape rct(sf::Vector2f(900, 10));
int i = 290, j = 500, k = 900,pnt=0,pnttmp=0,m=0,bn1=620,bn2=670,bn3=720,bn4=770,bn5=820,bn6=1000,bn7=1050,bn8=1100,bn9=1150, bn10 = 1200, bn11 = 1250, bn12 = 1300, bn13 = 1350;
void delay()
{
	int p,q;
	for (p = 0; p < 10000000; p++)
		for (q = 0; q < 100; q++);
}
void go()
{
	sf::Texture gotex;
	sf::Sprite goimg;
	goimg.setPosition(sf::Vector2f(50, 50));
	goimg.setScale(sf::Vector2f(0.4f, 0.3f));
	if (!gotex.loadFromFile("go.png"))
		printf("error");
	goimg.setTexture(gotex);
	while (true)
	{
		window.clear();
		window.draw(goimg);
		window.display();
	}
}
int main()
{
	window.setFramerateLimit(120);
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	point.setFont(font);
	point.setCharacterSize(24);
	std::stringstream ss;  // #include <sstream>
	ss <<pnt;
	point.setString(ss.str().c_str());
	point.setPosition(sf::Vector2f(450, 40));
	pt.setFont(font);
	pt.setCharacterSize(24);
	pt.setString("Score:");
	pt.setPosition(sf::Vector2f(380, 40));
	if (!bn11tex.loadFromFile("banana.png"))
		printf("error");
	bn11img.setTexture(bn11tex);
	bn11img.setScale(sf::Vector2f(0.02f, 0.02f));
	if (!bn12tex.loadFromFile("banana.png"))
		printf("error");
	bn12img.setTexture(bn12tex);
	bn12img.setScale(sf::Vector2f(0.02f, 0.02f));
	if (!bn13tex.loadFromFile("banana.png"))
		printf("error");
	bn13img.setTexture(bn13tex);
	bn13img.setScale(sf::Vector2f(0.02f, 0.02f));
	if (!bn6tex.loadFromFile("banana.png"))
		printf("error");
	bn6img.setTexture(bn6tex);
	bn6img.setScale(sf::Vector2f(0.02f, 0.02f));
	if (!bn7tex.loadFromFile("banana.png"))
		printf("error");
	bn7img.setTexture(bn7tex);
	bn7img.setScale(sf::Vector2f(0.02f, 0.02f));
	if (!bn8tex.loadFromFile("banana.png"))
		printf("error");
	bn8img.setTexture(bn8tex);
	bn8img.setScale(sf::Vector2f(0.02f, 0.02f));
	if (!bn9tex.loadFromFile("banana.png"))
		printf("error");
	bn9img.setTexture(bn9tex);
	bn9img.setScale(sf::Vector2f(0.02f, 0.02f));
	if (!bn10tex.loadFromFile("banana.png"))
		printf("error");
	bn10img.setTexture(bn10tex);
	bn10img.setScale(sf::Vector2f(0.02f, 0.02f));

	if (!bn1tex.loadFromFile("banana.png"))
		printf("error");
	bn1img.setTexture(bn1tex);
	bn1img.setScale(sf::Vector2f(0.02f, 0.02f));

	if (!bn2tex.loadFromFile("banana.png"))
		printf("error");
	bn2img.setTexture(bn2tex);
	bn2img.setScale(sf::Vector2f(0.02f, 0.02f));

	if (!bn3tex.loadFromFile("banana.png"))
		printf("error");
	bn3img.setTexture(bn3tex);
	bn3img.setScale(sf::Vector2f(0.02f, 0.02f));

	if (!bn4tex.loadFromFile("banana.png"))
		printf("error");
	bn4img.setTexture(bn4tex);
	bn4img.setScale(sf::Vector2f(0.02f, 0.02f));

	if (!bn5tex.loadFromFile("banana.png"))
		printf("error");
	bn5img.setTexture(bn5tex);
	bn5img.setScale(sf::Vector2f(0.02f, 0.02f));
	
	if(!mnntex.loadFromFile("mnn.png"))
		printf("error");
	mnnimg.setTexture(mnntex);
	mnnimg.setScale(sf::Vector2f(0.3f, 0.3f));

	if (!brk1tex.loadFromFile("brk.png"))
		printf("error");
	brk1img.setTexture(brk1tex);
	brk1img.setScale(sf::Vector2f(0.2f, 0.2f));
	
	if (!brk2tex.loadFromFile("brk.png"))
		printf("error");
	brk2img.setTexture(brk2tex);
	brk2img.setScale(sf::Vector2f(0.2f, 0.2f));

	if (!brk3tex.loadFromFile("brk.png"))
		printf("error");
	brk3img.setTexture(brk3tex);
	brk3img.setScale(sf::Vector2f(0.2f, 0.2f));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		mnnimg.setPosition(sf::Vector2f(50, i));
		
		brk1img.setPosition(sf::Vector2f(j, 300));
		brk2img.setPosition(sf::Vector2f(k, 300));
		rct.setPosition(sf::Vector2f(0, 400));

		bn1img.setPosition(sf::Vector2f(bn1, 380));
		bn2img.setPosition(sf::Vector2f(bn2, 380));
		bn3img.setPosition(sf::Vector2f(bn3, 380));
		bn4img.setPosition(sf::Vector2f(bn4, 380));
		bn5img.setPosition(sf::Vector2f(bn5, 380));

		bn6img.setPosition(sf::Vector2f(bn6, 380));
		bn7img.setPosition(sf::Vector2f(bn7, 380));
		bn8img.setPosition(sf::Vector2f(bn8, 380));
		bn9img.setPosition(sf::Vector2f(bn9, 380));
		bn10img.setPosition(sf::Vector2f(bn10, 380));

		bn11img.setPosition(sf::Vector2f(bn11, 380));
		bn12img.setPosition(sf::Vector2f(bn12, 380));
		bn13img.setPosition(sf::Vector2f(bn13, 380));

		window.clear();
		window.draw(mnnimg);
		window.draw(brk1img);
		window.draw(brk2img);
		window.draw(rct);
		window.draw(point);
		window.draw(pt);
		window.draw(bn1img);
		window.draw(bn2img);
		window.draw(bn3img);
		window.draw(bn4img);
		window.draw(bn5img);
		window.draw(bn6img);
		window.draw(bn7img);
		window.draw(bn8img);
		window.draw(bn9img);
		window.draw(bn10img);
		window.draw(bn11img);
		window.draw(bn12img);
		window.draw(bn13img);

		window.display();
		if(m==0)
		{
			delay(); m++;
		}
		j-= 5;
		k-= 5;
		bn1-=5; bn2-= 5; bn3-= 5; bn4-= 5; bn5-= 5; bn6-= 5; bn7-= 5; bn8-= 5; bn9-= 5; bn10-= 5; bn11-= 5; bn13-= 5; bn12-= 5;
		if (bn11 == 0)
			bn11 = 900;
		if (bn12 == 0)
			bn12 = 900;
		if (bn13 == 0)
			bn13 = 900;
		if (bn3 == 0)
			bn3 = 900;
		if (bn6 == 0)
			bn6 = 900;
		if (bn7 == 0)
			bn7 = 900;
		if (bn8 == 0)
			bn8 = 900;
		if (bn9 == 0)
			bn9 = 900; 
		if (bn10 == 0)
			bn10 = 900;
		if (bn4 == 0)
			bn4 = 900;
		if (bn5 == 0)
			bn5 = 900;
		if (bn2 == 0)
			bn2 = 900;
		if (bn1 == 0)
			bn1 = 900;
		if (j == 0)
			j = 900;
		if (k == 0)
			k = 900;
		if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && i > 100)
			i-= 5;
		else if (i < 290)
			i+= 5;
		if (i == 290)
		{
			
			pnt+=5;
			std::stringstream ss;  // #include <sstream>
			ss << pnt;
			point.setString(ss.str().c_str());

		}
		if (i == 100)
		{

			pnt--;
			std::stringstream ss;  // #include <sstream>
			ss << pnt;
			point.setString(ss.str().c_str());

		}
		if (i + 110 > 300 && ((j < 110 && j>50) || (k < 110 && k>50)))
			go();
		
			
	}

}