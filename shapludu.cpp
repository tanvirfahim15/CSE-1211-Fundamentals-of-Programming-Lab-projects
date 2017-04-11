#include <SFML/Graphics.hpp>
#include<stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include <time.h>
int rp = 0, gp = 0, t = 0;

sf::RenderWindow window(sf::VideoMode(900, 735), "SFML works!");
sf::Texture btex;
sf::Sprite bimg;
sf::Texture ggutitex;
sf::Sprite ggutiimg;
sf::Texture rgutitex;
sf::Sprite rgutiimg;
sf::Texture guti1tex;
sf::Sprite guti1img;
sf::Texture guti2tex;
sf::Sprite guti2img;
sf::Texture guti3tex;
sf::Sprite guti3img;
sf::Texture guti4tex;
sf::Sprite guti4img;
sf::Texture guti5tex;
sf::Sprite guti5img;
sf::Texture guti6tex;
sf::Sprite guti6img;
sf::Texture gttex;
sf::Sprite gtimg;
sf::Texture rttex;
sf::Sprite rtimg;

sf::Text yw;
sf::Text iw;

void delay(int t)
{
	int i;
	for (i = 0; i < t * 1000000; i++);
}

void an()
{

	window.draw(bimg);
	window.draw(guti6img);
	window.draw(ggutiimg);
	window.draw(rgutiimg);
	window.draw(rtimg);
	window.draw(gtimg);
	window.display();
	delay(100);
	window.clear();
	window.draw(bimg);
	window.draw(guti5img);
	window.draw(ggutiimg);
	window.draw(rgutiimg);
	window.draw(rtimg);
	window.draw(gtimg);
	window.display();
	delay(100);
	window.clear();
	window.draw(bimg);
	window.draw(guti4img);
	window.draw(ggutiimg);
	window.draw(rgutiimg);
	window.draw(rtimg);
	window.draw(gtimg);
	window.display();
	delay(100);
	window.clear();
	window.draw(bimg);
	window.draw(guti3img);
	window.draw(ggutiimg);
	window.draw(rgutiimg);
	window.draw(rtimg);
	window.draw(gtimg);
	window.display();
	delay(100);
	window.clear();
	window.draw(bimg);
	window.draw(guti2img);
	window.draw(ggutiimg);
	window.draw(rgutiimg);
	window.draw(rtimg);
	window.draw(gtimg);
	window.display();
	delay(100);
	window.clear();
	window.draw(bimg);
	window.draw(guti1img);
	window.draw(ggutiimg);
	window.draw(rgutiimg);
	window.draw(rtimg);
	window.draw(gtimg);
	window.display();
	delay(100);
}



int main()
{
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	iw.setFont(font);
	iw.setCharacterSize(24);
	 
	yw.setFont(font);
	yw.setCharacterSize(24);
	

	yw.setString("You Won");
	iw.setString("I Won");
	if (!btex.loadFromFile("bg.png"))
		printf("error");
	bimg.setTexture(btex);


	if (!ggutitex.loadFromFile("gguti.png"))
		printf("error");
	ggutiimg.setTexture(ggutitex);
	ggutiimg.setPosition(sf::Vector2f(820, 20));
	ggutiimg.setScale(sf::Vector2f(0.5f, 0.5f));



	if (!rgutitex.loadFromFile("rguti.png"))
		printf("error");
	rgutiimg.setTexture(rgutitex);
	rgutiimg.setPosition(sf::Vector2f(750, 20));
	rgutiimg.setScale(sf::Vector2f(0.5f, 0.5f));



	if (!guti1tex.loadFromFile("1.png"))
		printf("error");
	guti1img.setTexture(guti1tex);
	guti1img.setPosition(sf::Vector2f(750, 200));
	guti1img.setScale(sf::Vector2f(0.5f, 0.5f));


	if (!guti2tex.loadFromFile("2.png"))
		printf("error");
	guti2img.setTexture(guti2tex);
	guti2img.setPosition(sf::Vector2f(750, 200));
	guti2img.setScale(sf::Vector2f(0.5f, 0.5f));



	if (!guti3tex.loadFromFile("3.png"))
		printf("error");
	guti3img.setTexture(guti3tex);
	guti3img.setPosition(sf::Vector2f(750, 200));
	guti3img.setScale(sf::Vector2f(0.5f, 0.5f));


	if (!guti4tex.loadFromFile("4.png"))
		printf("error");
	guti4img.setTexture(guti4tex);
	guti4img.setPosition(sf::Vector2f(750, 200));
	guti4img.setScale(sf::Vector2f(0.5f, 0.5f));


	if (!guti5tex.loadFromFile("5.png"))
		printf("error");
	guti5img.setTexture(guti5tex);
	guti5img.setPosition(sf::Vector2f(750, 200));
	guti5img.setScale(sf::Vector2f(0.5f, 0.5f));

	if (!guti6tex.loadFromFile("6.png"))
		printf("error");
	guti6img.setTexture(guti6tex);
	guti6img.setPosition(sf::Vector2f(750, 200));
	guti6img.setScale(sf::Vector2f(0.5f, 0.5f));


	if (!gttex.loadFromFile("gt.png"))
		printf("error");
	gtimg.setTexture(gttex);
	gtimg.setPosition(sf::Vector2f(750, 400));
	gtimg.setScale(sf::Vector2f(0.5f, 0.5f));

	if (!rttex.loadFromFile("rt.png"))
		printf("error");
	rtimg.setTexture(rttex);
	rtimg.setPosition(sf::Vector2f(750, 400));
	rtimg.setScale(sf::Vector2f(0.5f, 0.5f));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		srand(time(NULL));



		gtimg.setPosition(sf::Vector2f(750, 400));
		window.clear();
		if (t == 1)
			window.draw(guti1img);
		else if (t == 2)
			window.draw(guti2img);
		else if (t == 3)
			window.draw(guti3img);
		else if (t == 4)
			window.draw(guti4img);
		else if (t == 5)
			window.draw(guti5img);
		else if (t == 6)
			window.draw(guti6img);
		window.draw(bimg);
		window.draw(ggutiimg);
		window.draw(rgutiimg);
		window.draw(rtimg);
		window.draw(gtimg);
		window.display();
		while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)));

		t = (rand() % 6) + 1;
		gp += (t);
		if (gp > 100)
			gp -= t;
		an();
		if (((gp - 1) / 10) % 2 == 0)
			ggutiimg.setPosition(sf::Vector2f(15 + 70 * ((gp - 1) % 10), 655 - 70 * ((gp - 1) / 10)));
		else
			ggutiimg.setPosition(sf::Vector2f(15 + 70 * (9 - ((gp - 1) % 10)), 655 - 70 * ((gp - 1) / 10)));
		window.clear();
		if (t == 1)
			window.draw(guti1img);
		else if (t == 2)
			window.draw(guti2img);
		else if (t == 3)
			window.draw(guti3img);
		else if (t == 4)
			window.draw(guti4img);
		else if (t == 5)
			window.draw(guti5img);
		else if (t == 6)
			window.draw(guti6img);
		window.draw(bimg);
		window.draw(ggutiimg);
		window.draw(rgutiimg);
		window.draw(rtimg);
		window.draw(gtimg);
		window.display();

		if (gp == 8)
		{
			delay(5000);
			gp = 26;
		}

		if (gp == 43)
		{
			delay(5000);
			gp = 77;
		}
		if (gp == 46)
		{
			delay(5000);
			gp = 5;
		}
		if (gp == 48)
		{
			delay(5000);
			gp = 9;
		}
		if (gp == 50)
		{
			delay(5000);
			gp = 91;
		}
		if (gp == 52)
		{
			delay(5000);
			gp = 11;
		}
		if (gp == 62)
		{
			delay(5000);
			gp = 96;
		}
		if (gp == 66)
		{
			delay(5000);
			gp = 87;
		}
		if (gp == 68)
		{
			delay(5000);
			gp = 3;
		}
		if (gp == 69)
		{
			delay(5000);
			gp = 33;
		}
		if (gp == 89)
		{
			delay(5000);
			gp = 51;
		}
		if (gp == 93)
		{
			delay(5000);
			gp = 37;
		}
		if (gp == 98)
		{
			delay(5000);
			gp = 13;
		}
		if (((gp - 1) / 10) % 2 == 0)
			ggutiimg.setPosition(sf::Vector2f(15 + 70 * ((gp - 1) % 10), 655 - 70 * ((gp - 1) / 10)));
		else
			ggutiimg.setPosition(sf::Vector2f(15 + 70 * (9 - ((gp - 1) % 10)), 655 - 70 * ((gp - 1) / 10)));
		window.clear();

		if (t == 1)
			window.draw(guti1img);
		else if (t == 2)
			window.draw(guti2img);
		else if (t == 3)
			window.draw(guti3img);
		else if (t == 4)
			window.draw(guti4img);
		else if (t == 5)
			window.draw(guti5img);
		else if (t == 6)
			window.draw(guti6img);
		window.draw(bimg);
		window.draw(ggutiimg);
		window.draw(rgutiimg);
		window.draw(rtimg);
		window.draw(gtimg);
		window.display();



		delay(5000);

		if (gp == 100)
		{
			while (true)
			{

				window.clear();
				window.draw(yw);
				window.display();
			}
		}




		window.clear();

		gtimg.setPosition(sf::Vector2f(7050, 400));
		if (t == 1)
			window.draw(guti1img);
		else if (t == 2)
			window.draw(guti2img);
		else if (t == 3)
			window.draw(guti3img);
		else if (t == 4)
			window.draw(guti4img);
		else if (t == 5)
			window.draw(guti5img);
		else if (t == 6)
			window.draw(guti6img);
		window.draw(bimg);
		window.draw(ggutiimg);
		window.draw(rgutiimg);
		window.draw(rtimg);
		window.draw(gtimg);
		window.display();






























		delay(5000);

		t = (rand() % 6) + 1;
		rp += (t);
		if (rp > 100)
			rp -= t;
		an();
		if (((rp - 1) / 10) % 2 == 0)
			rgutiimg.setPosition(sf::Vector2f(15 + 70 * ((rp - 1) % 10), 655 - 70 * ((rp - 1) / 10)));
		else
			rgutiimg.setPosition(sf::Vector2f(15 + 70 * (9 - ((rp - 1) % 10)), 655 - 70 * ((rp - 1) / 10)));
		window.clear();
		if (t == 1)
			window.draw(guti1img);
		else if (t == 2)
			window.draw(guti2img);
		else if (t == 3)
			window.draw(guti3img);
		else if (t == 4)
			window.draw(guti4img);
		else if (t == 5)
			window.draw(guti5img);
		else if (t == 6)
			window.draw(guti6img);
		window.draw(bimg);
		window.draw(ggutiimg);
		window.draw(rgutiimg);
		window.draw(rtimg);
		window.draw(gtimg);
		window.display();

		if (rp == 8)
		{
			delay(5000);
			rp = 26;
		}

		if (rp == 43)
		{
			delay(5000);
			rp = 77;
		}
		if (rp == 46)
		{
			delay(5000);
			rp = 5;
		}
		if (rp == 48)
		{
			delay(5000);
			rp = 9;
		}
		if (rp == 50)
		{
			delay(5000);
			rp = 91;
		}
		if (rp == 52)
		{
			delay(5000);
			rp = 11;
		}
		if (rp == 62)
		{
			delay(5000);
			rp = 96;
		}
		if (rp == 66)
		{
			delay(5000);
			rp = 87;
		}
		if (rp == 68)
		{
			delay(5000);
			rp = 3;
		}
		if (rp == 69)
		{
			delay(5000);
			rp = 33;
		}
		if (rp == 89)
		{
			delay(5000);
			rp = 51;
		}
		if (rp == 93)
		{
			delay(5000);
			rp = 37;
		}
		if (rp == 98)
		{
			delay(5000);
			rp = 13;
		}
		if (((rp - 1) / 10) % 2 == 0)
			rgutiimg.setPosition(sf::Vector2f(15 + 70 * ((rp - 1) % 10), 655 - 70 * ((rp - 1) / 10)));
		else
			rgutiimg.setPosition(sf::Vector2f(15 + 70 * (9 - ((rp - 1) % 10)), 655 - 70 * ((rp - 1) / 10)));
		window.clear();

		if (t == 1)
			window.draw(guti1img);
		else if (t == 2)
			window.draw(guti2img);
		else if (t == 3)
			window.draw(guti3img);
		else if (t == 4)
			window.draw(guti4img);
		else if (t == 5)
			window.draw(guti5img);
		else if (t == 6)
			window.draw(guti6img);
		window.draw(bimg);
		window.draw(ggutiimg);
		window.draw(rgutiimg);
		window.draw(rtimg);
		window.draw(gtimg);
		window.display();




		if (rp == 100)
		{
			while (true)
			{
				delay(5000);
				window.clear();
				window.draw(iw);
				window.display();
			}


		}




	}

	return 0;
}

