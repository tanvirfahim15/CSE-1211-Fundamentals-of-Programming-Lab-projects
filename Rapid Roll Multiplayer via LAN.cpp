#include <sstream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <SFML/Network.hpp>
#include <string>
#include<iostream>

#pragma warning (disable : 4996)
using namespace std;
sf::CircleShape circle(10);
sf::CircleShape ocircle(10);
sf::RectangleShape rec1(sf::Vector2f(200, 20));
sf::RectangleShape rec2(sf::Vector2f(200, 20));
sf::RectangleShape rec3(sf::Vector2f(200, 20));
sf::RectangleShape rec4(sf::Vector2f(200, 20));
sf::RectangleShape rec5(sf::Vector2f(800, 10));
sf::Texture hrttex;
sf::Sprite hrtimg[6];
sf::Texture bctex;
sf::Sprite bcimg;
sf::Text point;
sf::Text pt;
sf::Text opoint;
sf::Text opt;
sf::Text go;


sf::TcpSocket socket;
char connectiontype, mode, buffer[2000];
std::size_t recieved;
sf::TcpListener listener;



int i, cx = 300, cy = 190, ocx = 300,ocy = 190, pnt = 0,opnt=0, rec1x = 0, rec2x = 200, rec3x = 400, rec4x = 600, rec1y = 0, rec2y = 200, rec3y = 400, rec4y = 600, life = 3,olife=3,gov=1;
int main()
{


	socket.connect("192.168.0.104", 2000);


	
	if (!hrttex.loadFromFile("hrt.png"))
		printf("error");
	if (!bctex.loadFromFile("bc.png"))
		printf("error");
	bcimg.setTexture(bctex);
	bcimg.setScale(sf::Vector2f(10.0f, 10.0f));
	for(i=0;i<3;i++)
	{
		hrtimg[i].setTexture(hrttex);
		hrtimg[i].setScale(sf::Vector2f(0.02f, 0.02f));
		hrtimg[i].setPosition(sf::Vector2f(i*50+20, 650));
	}
	for (i = 3; i<6; i++)
	{
		hrtimg[i].setTexture(hrttex);
		hrtimg[i].setScale(sf::Vector2f(0.02f, 0.02f));
		hrtimg[i].setPosition(sf::Vector2f(i * 50 + 460, 650));
	}

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}


	opoint.setFont(font);
	opoint.setCharacterSize(24);
	opoint.setPosition(sf::Vector2f(700, 620));
	opt.setFont(font);
	opt.setCharacterSize(24);
	opt.setString("Opponent's Score:");
	opt.setPosition(sf::Vector2f(480, 620));



	point.setFont(font);
	point.setCharacterSize(24);
	point.setPosition(sf::Vector2f(100, 620));
	pt.setFont(font);
	pt.setCharacterSize(24);
	pt.setString("Score:");
	pt.setPosition(sf::Vector2f(30, 620));
	go.setFont(font);
	go.setCharacterSize(50);
	go.setString("GAME OVER");
	go.setPosition(sf::Vector2f(250, 280));

	sf::RenderWindow window(sf::VideoMode(800, 700), "Rapid Roll");
	window.setFramerateLimit(200);
	
	circle.setOrigin(circle.getLocalBounds().width / 2.0f, circle.getLocalBounds().height / 2.0f);
	ocircle.setOrigin(ocircle.getLocalBounds().width / 2.0f, ocircle.getLocalBounds().height / 2.0f);
	rec1.setPosition(sf::Vector2f(0, 0));
	rec2.setPosition(sf::Vector2f(200, 200));
	rec3.setPosition(sf::Vector2f(400, 400));
	rec4.setPosition(sf::Vector2f(600, 600));
	rec5.setFillColor(sf::Color(0, 80, 90));
	rec2.setFillColor(sf::Color(0, 80, 90));
	rec3.setFillColor(sf::Color(0, 80, 90));
	rec4.setFillColor(sf::Color(0, 80, 90));
	circle.setFillColor(sf::Color(0, 0, 0));
	ocircle.setFillColor(sf::Color(255, 0, 0));
	
	while (window.isOpen())
	{


		


		rec1.setPosition(sf::Vector2f(rec1x, rec1y));
		rec2.setPosition(sf::Vector2f(rec2x, rec2y));
		rec3.setPosition(sf::Vector2f(rec3x, rec3y));
		rec4.setPosition(sf::Vector2f(rec4x, rec4y));
		rec5.setPosition(sf::Vector2f(0, 600));
		srand(time(NULL));


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (gov > 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && cx > 10)
			{
				cx -= 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && cx < 790)
			{
				cx += 3;
			}
			circle.setPosition(sf::Vector2f(cx, cy));
			ocircle.setPosition(sf::Vector2f(ocx, ocy));
			window.clear();
			window.draw(bcimg);
			window.draw(circle);
			window.draw(ocircle);
			for (i = 0; i < life; i++)
				window.draw(hrtimg[i]);
			for (i = 3; i < olife + 3; i++)
				window.draw(hrtimg[i]);


			window.draw(rec2);
			window.draw(rec3);
			window.draw(rec4);
			window.draw(rec5);
			window.draw(point);
			window.draw(pt);
			window.draw(opoint);
			window.draw(opt);
			window.display();


			if (((cy == rec1y - 10 && cx + 5 > rec1x&&cx - 5 < rec1x + 200) || (cy == rec2y - 10 && cx + 5 > rec2x&&cx - 5 < rec2x + 200) || (cy == rec3y - 10 && cx + 5 > rec3x&&cx - 5 < rec3x + 200) || (cy == rec4y - 10 && cx + 5 > rec4x&&cx - 5 < rec4x + 200)))
			{
				cy--;
			}
			else
			{
				cy++;
				pnt++;


			}


			rec1y--; rec2y--; rec3y--; rec4y--;
			if (rec1y == 0)
			{
				rec1y = 600;
				rec1x = (rand() % 4) * 200;
			}
			if (rec2y == 0)
			{
				rec2y = 600;
				rec2x = (rand() % 4) * 200;
			}
			if (rec3y == 0)
			{
				rec3y = 600;
				rec3x = (rand() % 4) * 200;
			}
			if (rec4y == 0)
			{
				rec4y = 600;
				rec4x = (rand() % 4) * 200;
			}

			if (cy == 10 || cy == 590)
			{
				if (life)
				{
					life--;
					cy = 300;
				}
				else
				{
					gov--;

				}
			}
		}

		else if (gov<1)
		{
			window.clear();
			window.draw(go);
			window.draw(point);
			window.draw(pt);
			window.draw(opoint);
			window.draw(opt);
			for (i = 0; i < life; i++)
				window.draw(hrtimg[i]);
			for (i = 3; i < olife + 3; i++)
				window.draw(hrtimg[i]);
			window.display();
		}
		std::stringstream pon;
		pon << pnt;
		point.setString(pon.str().c_str());

		sf::Packet p;
		p << life;
		p << cx;
		p << cy;
		p << pnt;
		socket.send(p);
		socket.receive(p);
		

		p >> opnt;
		p >> ocx;
		p >> ocy;
		p >> rec2x;
		p >> rec2y;
		p >> rec3x;
		p >> rec3y;
		p >> rec4x;
		p >> rec4y;
		p >> olife;




		std::stringstream opon;
		opon << opnt;
		opoint.setString(opon.str().c_str());

		
		/*std::stringstream cxx;
		cxx << cx;
		socket.send(cxx.str().c_str(), cxx.str().length() + 1);

		std::stringstream cyy;
		cyy << cy;
		socket.send(cyy.str().c_str(), cyy.str().length() + 1);

		std::stringstream rec1xx;
		rec1xx << rec1x;
		socket.send(rec1xx.str().c_str(), rec1xx.str().length() + 1);

		std::stringstream rec1yy;
		rec1yy << rec1y;
		socket.send(rec1yy.str().c_str(), rec1yy.str().length() + 1);
		
		std::stringstream rec2xx;
		rec2xx << rec2x;
		socket.send(rec2xx.str().c_str(), rec2xx.str().length() + 1);

		std::stringstream rec2yy;
		rec2yy << rec2y;
		socket.send(rec2yy.str().c_str(), rec2yy.str().length() + 1);


		std::stringstream rec3xx;
		rec3xx << rec3x;
		socket.send(rec3xx.str().c_str(), rec3xx.str().length() + 1);

		std::stringstream rec3yy;
		rec3yy << rec3y;
		socket.send(rec3yy.str().c_str(), rec3yy.str().length() + 1);

		std::stringstream rec4xx;
		rec4xx << rec4x;
		socket.send(rec4xx.str().c_str(), rec4xx.str().length() + 1);

		std::stringstream rec4yy;
		rec4yy << rec4y;
		socket.send(rec4yy.str().c_str(), rec4yy.str().length() + 1);

		




		FILE *pc1 = fopen("pc1sc.txt", "w");
		fprintf(pc1, "%s\n", pon.str().c_str());
		fprintf(pc1, "%d\n", cx);
		fprintf(pc1, "%d\n", cy);
		fprintf(pc1, "%d\n", rec1x);
		fprintf(pc1, "%d\n", rec1y);
		fprintf(pc1, "%d\n", rec2x);
		fprintf(pc1, "%d\n", rec2y);
		fprintf(pc1, "%d\n", rec3x);
		fprintf(pc1, "%d\n", rec3y);
		fprintf(pc1, "%d\n", rec4x);
		fprintf(pc1, "%d\n", rec4y);
		fprintf(pc1, "%d\n", life);
		fclose(pc1);*/

		std::stringstream lifee;
		lifee << life;
		socket.send(lifee.str().c_str(), lifee.str().length() + 1);

		socket.receive(buffer, sizeof(buffer), recieved);
		std::stringstream olf;
		olf << buffer;
		olf >> olife;
	
	}

}
