#include <sstream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 735), "Fruit Ninja");
	sf::Text point;
	sf::Text pt;
	sf::Text gotxt;
	sf::Texture tgttex;
	sf::Sprite tgtimg;
	sf::Texture bactex;
	sf::Sprite bacimg;
	sf::Texture gotex;
	sf::Sprite goimg;
	sf::Texture hitmtex[6];
	sf::Sprite hitmimg[6];
	sf::Clock clk;
	sf::Clock clk2;
	sf::Time t = sf::milliseconds(3000);
	sf::Time t1 = sf::milliseconds(2000);
	int x = 450, y = 700, pnt = 0, hx[6], hy[6], i;
	int hxx, hyy;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	point.setFont(font);
	point.setCharacterSize(24);
	std::stringstream ss;  
	ss << pnt;
	point.setString(ss.str().c_str());
	point.setPosition(sf::Vector2f(450, 10));


	gotxt.setFont(font);
	gotxt.setCharacterSize(24);
	gotxt.setString("Press Space to play again");
	gotxt.setPosition(sf::Vector2f(300, 600));


	pt.setFont(font);
	pt.setCharacterSize(24);
	pt.setString("Score:");
	pt.setPosition(sf::Vector2f(380, 10));
	window.setFramerateLimit(100);
	if (!tgttex.loadFromFile("tgt.png"))
		printf("error");
	tgtimg.setTexture(tgttex);
	tgtimg.setScale(sf::Vector2f(0.1f, 0.1f));
	tgtimg.setOrigin(tgtimg.getLocalBounds().width / 2.0f, tgtimg.getLocalBounds().height / 2.0f);
	tgtimg.setPosition(sf::Vector2f(x, y));
	
	if (!bactex.loadFromFile("bac.png"))
		printf("error");
	bacimg.setTexture(bactex);
	bacimg.setScale(sf::Vector2f(0.7f, 0.8f));
	if (!gotex.loadFromFile("go.png"))
		printf("error");
	goimg.setTexture(gotex);
	goimg.setScale(sf::Vector2f(0.6f, 0.9f));

	if (!hitmtex[0].loadFromFile("hitm1.png"))
		printf("error");
	if (!hitmtex[1].loadFromFile("hitm2.png"))
		printf("error");
	if (!hitmtex[2].loadFromFile("hitm3.png"))
		printf("error");
	if (!hitmtex[3].loadFromFile("hitm4.png"))
		printf("error");
	if (!hitmtex[4].loadFromFile("hitm5.png"))
		printf("error");
	if (!hitmtex[5].loadFromFile("hitm6.png"))
		printf("error");
	for (i = 0; i < 6; i++)
	{
		hitmimg[i].setTexture(hitmtex[i]);
		hitmimg[i].setScale(sf::Vector2f(0.5f, 0.5f));
		hitmimg[i].setPosition(sf::Vector2f(hx[i], hy[i]));
		hitmimg[i].setOrigin(hitmimg[i].getLocalBounds().width / 2.0f, hitmimg[i].getLocalBounds().height / 2.0f);
	}
	
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		srand(time(NULL));
		for (i = 0; i < 6; i++)
		{

			
			hx[i] = (rand() % 300) * 2 + 100;
			hy[i] = (rand() % 100) * 4 + 100;
			hitmimg[i].setPosition(sf::Vector2f(hx[i], hy[i]));
			hxx = hx[i] - x;
			hyy = hy[i] - y;
			if (hxx < 0)hxx *= -1;
			if (hyy < 0)hyy *= -1;


			if (hxx < hitmimg[i].getLocalBounds().width / 2.0f && hyy < hitmimg[i].getLocalBounds().height / 2.0f)
			{
				hx[i] += 500;
				hy[i] += 500;
				hitmimg[i].setPosition(sf::Vector2f(hx[i], hy[i]));
				
			}
			
		}
		
		
		window.clear();
		window.draw(tgtimg);
		window.draw(point);
		window.draw(pt);
		window.display();
		
		clk.restart();
		while ( clk.getElapsedTime()<t1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&x>0)
				x-=5;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&x<900)
				x+=5;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&y>0)
				y-=5;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&y<735)
				y+=5;

			tgtimg.setPosition(sf::Vector2f(x, y));
			window.clear();
			window.draw(bacimg);
			for(i=0;i<6;i++)
			window.draw(hitmimg[i]);
			window.draw(tgtimg);
			window.draw(point);
			window.draw(pt);
			window.display();
			
			for (i = 0; i < 5; i++)
			{
				hxx = hx[i] - x;
				hyy = hy[i] - y;
				if (hxx < 0)hxx *= -1;
				if (hyy < 0)hyy *= -1;


				if (hxx < hitmimg[i].getLocalBounds().width / 2.0f && hyy < hitmimg[i].getLocalBounds().height / 2.0f)
				{
					hitmimg[i].setPosition(sf::Vector2f(1000, 1000));
					pnt += (200 - (hxx + hyy)) / 100;
					std::stringstream ss;
					ss << pnt;
					point.setString(ss.str().c_str());
				}
			}
			hxx = hx[5] - x;
			hyy = hy[5] - y;
			if (hxx < 0)hxx *= -1;
			if (hyy < 0)hyy *= -1;


			if (hxx < hitmimg[5].getLocalBounds().width / 2.0f && hyy < hitmimg[5].getLocalBounds().height / 2.0f)
			{
				
				while (window.isOpen())
				{
					sf::Event event;
					while (window.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
							window.close();
					}
					window.clear();
					window.draw(goimg);
					window.draw(point);
					window.draw(pt);
					window.draw(gotxt);
					window.display();
					
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						window.close();
					
						main();
					}
				}
			}
			
			
		}
		
		
	}

}