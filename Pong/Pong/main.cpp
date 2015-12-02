#include<SFML/Graphics.hpp>	//SFML Graphics library  include files
#include<iostream>		//needed to output text to the console window when debugging
#include<fstream>	//needed for input and output to files for high score saving
#include<string>
#include<Windows.h>	//needed for message boxes

//entry point of this function is main()



bool fullscreen = false;	//global variable that dictates whether or not game runs in full screen

// I apologize in advance for the lack of comments in my code. I grew up with bad coding habits :(

//This function makes sure that whenever it is called it checks whether or not the fullscreen window is in focus. If it is not, it closes the window, waits for a new blank 
void fullscreentasks(sf::RenderWindow& window, bool& isPaused, sf::Event& event){
	
	while (!window.hasFocus() && fullscreen) {
		isPaused = true;
		window.close();
		window.create(sf::VideoMode(800, 600), "Pong", sf::Style::None);

		do {
			window.pollEvent(event);

			if (event.type == sf::Event::Closed)
				exit(0);

		} while (!window.hasFocus() && fullscreen);

		if (window.hasFocus()) {
			window.close();
			window.create(sf::VideoMode(800, 600), "Pong", sf::Style::Fullscreen);
			window.setFramerateLimit(90);
			window.setKeyRepeatEnabled(false);
		}


	}

}

void fullscreentasks(sf::RenderWindow& window, sf::Event& event) {

	while (!window.hasFocus() && fullscreen) {
		window.close();
		window.create(sf::VideoMode(800, 600), "Pong", sf::Style::None);

		do {
			window.pollEvent(event);

			if (event.type == sf::Event::Closed)
				exit(0);

		} while (!window.hasFocus() && fullscreen);

		if (window.hasFocus()) {
			window.close();
			window.create(sf::VideoMode(800, 600), "Pong",  sf::Style::Fullscreen);
			window.setFramerateLimit(90);
			window.setKeyRepeatEnabled(false);
		}


	}

}




int essentialeventtasks(sf::RenderWindow& window, sf::Event& event, bool Exit) {

	if (event.type == sf::Event::KeyPressed) {

		if ((event.key.code == sf::Keyboard::Escape) && !Exit) {
			return 1;
		}

		if ((event.key.code == sf::Keyboard::Escape) && Exit) {
			window.close();
			exit(0);
			return 0;
		}

	}

	if (event.type == sf::Event::Closed) {
		window.close();
		exit(0);
		return 0;
	}

	else
		return 0;
}




void twoplayer(sf::RenderWindow& window) {
	window.setTitle("Two-player Pong");
	bool firstrun = true;

	sf::Font font;

	if (!font.loadFromFile("C:\\Windows\\Fonts\\isocpeur.ttf")) {
		int error;
		do
		{
			if (font.loadFromFile("C:\\Windows\\Fonts\\isocpeur.ttf"))
				break;

			else if (font.loadFromFile("resources\\isocpeur.ttf"))
				break;


			else if (font.loadFromFile("isocpeur.ttf"))
				break;

			else if (font.loadFromFile("C:\\Windows\\Fonts\\impact.ttf")) {
				break;
			}


			error = MessageBox(NULL, (LPCWSTR)L"Could not load font file. You may not have the correct font installed (this game has been tested on Windows 7). To fix the problem, do one of the following:\n\n1) Copy any TrueType font (with file extension \".ttf\") from \"C:\\Windows\\Fonts\" to the same place as the game, and rename it to \"isocpeur.ttf\"\n2) Search \"Download isocpeur.ttf\" on Google and click on the first result. Once it is download, open the file. You should get a font preview. Now install the font (you need to be an administrator to do this. If you are not an admininstrator, use the other method above.). Now click retry, and the game should run", (LPCWSTR)L"Could not load font file", MB_ICONERROR | MB_RETRYCANCEL);
			//error = MessageBox(NULL, (LPCWSTR)L"You forgot to put the resources folder in the same place as the game dumbass!", (LPCWSTR)L"Could not load font file", MB_ICONERROR | MB_RETRYCANCEL);
		} while (error == IDRETRY);

		if (error == IDCANCEL)
			exit(0);
	}

	sf::Vector2i score(0, 0);
	bool isPaused = true;
	sf::Vector2f ballposition;
start:
	sf::Vector2f leftpaddleposition(5, 300);
	sf::Vector2f rightpaddleposition(795, 300);
	sf::CircleShape ball;
	sf::RectangleShape leftpaddle;
	sf::RectangleShape rightpaddle;
	ball.setOrigin(5, 5);
	leftpaddle.setOrigin(5, 40);
	rightpaddle.setOrigin(5, 40);
	sf::Vector2i slope;
	if (ballposition.x >= 800) {
		ballposition.x = 400, ballposition.y = 300;
		slope.x = -5;
		slope.y = 0;
	}

	else {
		ballposition.x = 400, ballposition.y = 300;
		slope.x = 5;
		slope.y = 0;
	}

	while (window.isOpen()) {

		sf::Event event;



		ballposition.y += slope.y;
		ballposition.x += slope.x;



		ball.setPosition(ballposition);
		ball.setFillColor(sf::Color::Red);
		ball.setOutlineColor(sf::Color::Black);
		ball.setOutlineThickness(2);
		ball.setRadius(5);

		leftpaddle.setPosition(leftpaddleposition);
		leftpaddle.setFillColor(sf::Color::Blue);
		leftpaddle.setOutlineColor(sf::Color::Black);
		leftpaddle.setOutlineThickness(1);
		leftpaddle.setSize(sf::Vector2f(10, 80));
		window.draw(leftpaddle);

		rightpaddle.setPosition(rightpaddleposition);
		rightpaddle.setFillColor(sf::Color::Red);
		rightpaddle.setOutlineColor(sf::Color::Black);
		rightpaddle.setOutlineThickness(1);
		rightpaddle.setSize(sf::Vector2f(10, 80));
		window.draw(rightpaddle);

		window.pollEvent(event);

		if (essentialeventtasks(window, event, false) == 1) {
			isPaused = true;
			int action = MessageBox(NULL, (LPCWSTR)L"Do you want to quit?", (LPCWSTR)L"Quit?", MB_ICONQUESTION | MB_YESNO);

			if (action == IDYES) {
				window.close();
				exit(0);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && leftpaddleposition.y > 40)
			leftpaddleposition.y -= 5;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && leftpaddleposition.y < 560)
			leftpaddleposition.y += 5;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rightpaddleposition.y > 40)
			rightpaddleposition.y -= 5;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rightpaddleposition.y < 560)
			rightpaddleposition.y += 5;



		if (ballposition.x <= 0) {
			score.y++;
			while (window.isOpen()) {
				fullscreentasks(window, event);
				slope.x = 0, slope.y = 0;
				sf::Text text;
				text.setFont(font);
				text.setCharacterSize(50);
				text.setPosition(60, 100);

				if ((score.x > 1) && (score.y == 0))
					text.setString("Red wins!\nBlue won " + std::to_string(score.x) + " times\nRed is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x > 1) && (score.y == 1))
					text.setString("Red wins!\nBlue won " + std::to_string(score.x) + " times\nRed won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x > 1) && (score.y > 1))
					text.setString("Red wins!\nBlue won " + std::to_string(score.x) + " times\nRed won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y == 0))
					text.setString("Red wins!\nBlue is a loser!\nRed is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y == 1))
					text.setString("Red wins!\n\nBlue is a loser!\nRed won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y > 1))
					text.setString("Red wins!\nBlue is a loser!\nRed won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");


				if ((score.x == 1) && (score.y == 1))
					text.setString("Red wins!\nBlue won once\nRed won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 1) && (score.y == 0))
					text.setString("Red wins!\nBlue won once\nRed is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 1) && (score.y > 1))
					text.setString("Red wins!\nBlue won once\nRed won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");

				window.clear();
				window.draw(text);
				window.pollEvent(event);

				if (essentialeventtasks(window, event, false) == 1) {
					window.clear();
					return;
				}

				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Space)
						goto start;

				}
				window.display();

			}
		}




		if (ballposition.x >= 800) {
			score.x++;
			while (window.isOpen()) {
				
					fullscreentasks(window, event);
				slope.x = 0, slope.y = 0;
				sf::Text text;
				text.setFont(font);
				text.setCharacterSize(50);
				text.setPosition(60, 100);

				if ((score.x > 1) && (score.y == 0 ))
					text.setString("Blue wins!\nBlue won " + std::to_string(score.x) + " times\nRed is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x > 1) && (score.y == 1))
					text.setString("Blue wins!\nBlue won " + std::to_string(score.x) + " times\nRed won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x > 1) && (score.y > 1))
					text.setString("Blue wins!\nBlue won " + std::to_string(score.x) + " times\nRed won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y == 0))
					text.setString("Blue wins!\nBlue is a loser!\nRed is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y == 1))
					text.setString("Blue wins!\n\nBlue is a loser!\nRed won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y > 1))
					text.setString("Blue wins!\nBlue is a loser!\nRed won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");


				if ((score.x == 1) && (score.y == 1))
					text.setString("Blue wins!\nBlue won once\nRed won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 1) && (score.y == 0))
					text.setString("Blue wins!\nBlue won once\nRed is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 1) && (score.y > 1))
					text.setString("Blue wins!\nBlue won once\nRed won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");

				window.clear();
				window.draw(text);
				window.pollEvent(event);

				if (fullscreen)
					fullscreentasks(window, isPaused, event);

				if (essentialeventtasks(window, event, false) == 1) {
					window.clear();
					return;
				}

				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Space)
						goto start;


				}
				window.display();

			}
		}


		if ((ballposition.y <= leftpaddleposition.y + 40 && ballposition.y >= leftpaddleposition.y - 40) && (ballposition.x <= leftpaddleposition.x + 5 && ballposition.x >= leftpaddleposition.x - 5)) {


 			slope.x = -slope.x;
			slope.y = static_cast<int>(ballposition.y - leftpaddleposition.y) / 5;

			if (slope.y == 0)
				slope.y++;

		}

		if ((ballposition.y <= rightpaddleposition.y + 40 && ballposition.y >= rightpaddleposition.y - 40) && (ballposition.x <= rightpaddleposition.x + 5 && ballposition.x >= rightpaddleposition.x - 5)) {

			slope.x = -slope.x;
			slope.y = static_cast<int>(ballposition.y - rightpaddleposition.y) / 5;
			if (slope.y == 0)
				slope.y++;
		}



		if (ballposition.y >= 600)
			slope.y = -slope.y;


		if (ballposition.y <= 0)
			slope.y = -slope.y;


		if (!window.hasFocus())
			isPaused = true;


		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space)
				isPaused = true;

		}




		while (isPaused) {




			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && firstrun) {
				window.pollEvent(event);
				
					fullscreentasks(window, isPaused, event);
				essentialeventtasks(window, event, false);
				sf::Text lefttutorial;
				lefttutorial.setFont(font);
				lefttutorial.setPosition(15, 300);
				lefttutorial.setCharacterSize(23);
				lefttutorial.setColor(sf::Color::Blue);
				lefttutorial.setString("Use \"W\" key to move up\nUse\"S\" key to move down");

				sf::Text righttutorial;
				righttutorial.setFont(font);
				righttutorial.setPosition(600, 300);
				righttutorial.setCharacterSize(23);
				righttutorial.setColor(sf::Color::Red);
				righttutorial.setString("Use Up and Down\narrow keys to move");

				sf::Text middletutorial;
				middletutorial.setFont(font);
				middletutorial.setPosition(20, 50);
				middletutorial.setCharacterSize(34);
				middletutorial.setColor(sf::Color::Black);
				middletutorial.setString("Press SPACE at any time to pause the game\n\nYou can return to the main menu from the pause menu");

				sf::Text starttext;
				starttext.setFont(font);
				starttext.setPosition(270, 300);
				starttext.setCharacterSize(32);
				starttext.setColor(sf::Color::Black);
				starttext.setStyle(sf::Text::Underlined | sf::Text::Bold);
				starttext.setString("Press SPACE to start");

				window.draw(starttext);
				window.draw(middletutorial);
				window.draw(lefttutorial);
				window.draw(righttutorial);
				window.draw(rightpaddle);
				window.draw(leftpaddle);
				window.display();
				window.clear(sf::Color::Green);
			}


			if (!firstrun) {
				sf::Text pause;
				pause.setPosition(100, 200);
				pause.setFont(font);
				pause.setColor(sf::Color::Black);
				pause.setCharacterSize(50);
				pause.setString("\n\nPress SPACE to resume game\nPress Esc to return to main menu");
				sf::Text bigpause;
				bigpause.setPosition(100, 200);
				bigpause.setFont(font);
				bigpause.setColor(sf::Color::Black);
				bigpause.setStyle(sf::Text::Bold | sf::Text::Underlined);
				bigpause.setCharacterSize(55);
				bigpause.setString("PAUSED");
				window.draw(leftpaddle);
				window.draw(rightpaddle);
				window.draw(bigpause);
				window.draw(pause);
				window.draw(ball);
				window.display();
				window.clear(sf::Color::Green);
			}
			window.pollEvent(event);

			
				fullscreentasks(window, isPaused, event);

			essentialeventtasks(window, event, false);

			if (essentialeventtasks(window, event, false) == 1) {
				window.clear();
				return;
			}


			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space)
					isPaused = false;

			}

		}

		firstrun = false;
		window.draw(ball);

		window.display();
		window.clear(sf::Color::Green);
	}
	exit(0);
}



















void playervcom(sf::RenderWindow& window) {
	window.setTitle("Player vs. Computer (beta)");
	bool firstrun = true;

	sf::Font font;

	if (!font.loadFromFile("C:\\Windows\\Fonts\\isocpeur.ttf")) {
		int error;
		do
		{
			if (font.loadFromFile("C:\\Windows\\Fonts\\isocpeur.ttf"))
				break;

			else if (font.loadFromFile("resources\\isocpeur.ttf"))
				break;


			else if (font.loadFromFile("isocpeur.ttf"))
				break;

			else if (font.loadFromFile("C:\\Windows\\Fonts\\impact.ttf")) {
				break;
			}


			error = MessageBox(NULL, (LPCWSTR)L"Could not load font file. You may not have the correct font installed (this game has been tested on Windows 7). To fix the problem, do one of the following:\n\n1) Copy any TrueType font (with file extension \".ttf\") from \"C:\\Windows\\Fonts\" to the same place as the game, and rename it to \"isocpeur.ttf\"\n2) Search \"Download isocpeur.ttf\" on Google and click on the first result. Once it is download, open the file. You should get a font preview. Now install the font (you need to be an administrator to do this. If you are not an admininstrator, use the other method above.). Now click retry, and the game should run", (LPCWSTR)L"Could not load font file", MB_ICONERROR | MB_RETRYCANCEL);
			//error = MessageBox(NULL, (LPCWSTR)L"You forgot to put the resources folder in the same place as the game dumbass!", (LPCWSTR)L"Could not load font file", MB_ICONERROR | MB_RETRYCANCEL);
		} while (error == IDRETRY);

		if (error == IDCANCEL)
			exit(0);
	}

	sf::Vector2i score(0, 0);
	bool isPaused = true;
	sf::Vector2f ballposition;
start:
	srand((unsigned)time(0));
	bool fastball = false;
	sf::Vector2f leftpaddleposition(5, 300);
	sf::Vector2f rightpaddleposition(795, 300);
	sf::CircleShape ball;
	sf::RectangleShape leftpaddle;
	sf::RectangleShape rightpaddle;
	ball.setOrigin(5, 5);
	leftpaddle.setOrigin(5, 40);
	rightpaddle.setOrigin(5, 40);
	sf::Vector2i slope;

	if (ballposition.x >= 800) {
		ballposition.x = 400, ballposition.y = 300;
		slope.x = -5;
		slope.y = 0;
	}

	else {
		ballposition.x = 400, ballposition.y = 300;
		slope.x = 5;
		slope.y = 0;
	}

	int cpuballcontact = 40;
	bool IscpuballcontactRand = false;
	sf::Clock clock;


	while (window.isOpen()) {
		sf::Event event;



		ballposition.y += slope.y;
		ballposition.x += slope.x;



		ball.setPosition(ballposition);
		ball.setFillColor(sf::Color::Red);
		ball.setOutlineColor(sf::Color::Black);
		ball.setOutlineThickness(2);
		ball.setRadius(5);

		leftpaddle.setPosition(leftpaddleposition);
		leftpaddle.setFillColor(sf::Color::Black);
		leftpaddle.setOutlineColor(sf::Color::Black);
		leftpaddle.setOutlineThickness(1);
		leftpaddle.setSize(sf::Vector2f(10, 80));
		window.draw(leftpaddle);

		rightpaddle.setPosition(rightpaddleposition);
		rightpaddle.setFillColor(sf::Color::Red);
		rightpaddle.setOutlineColor(sf::Color::Black);
		rightpaddle.setOutlineThickness(1);
		rightpaddle.setSize(sf::Vector2f(10, 80));
		window.draw(rightpaddle);

		window.pollEvent(event);

		if (essentialeventtasks(window, event, false) == 1) {
			isPaused = true;
			int action = MessageBox(NULL, (LPCWSTR)L"Do you want to quit?", (LPCWSTR)L"Quit?", MB_ICONQUESTION | MB_YESNO);

			if (action == IDYES) {
				window.close();
				exit(0);
			}
		}




		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && leftpaddleposition.y > 40)
			leftpaddleposition.y -= 5;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && leftpaddleposition.y < 560)
			leftpaddleposition.y += 5;

		
		if (slope.y > 5) {
			cpuballcontact = 0;
			IscpuballcontactRand = false;
		}

		if (slope.y < -5) {
			cpuballcontact = 80;
			IscpuballcontactRand = false;
		}
			
	

		
 
	//	if (slope.y > 5 && ballposition.y > (rightpaddleposition.y - 40) && rightpaddleposition.y < 560)
	//		rightpaddleposition.y += 5;

		if (ballposition.y > (rightpaddleposition.y + (cpuballcontact - 40)) && rightpaddleposition.y < 560) {

			if (ballposition.y > rightpaddleposition.y + 5 - 40)
			rightpaddleposition.y += 5;
		}


	//	if (slope.y < -5 && ballposition.y < (rightpaddleposition.y + 40) && rightpaddleposition.y > 40)
	//		rightpaddleposition.y -= 5;
	
		if (ballposition.y < (rightpaddleposition.y + (cpuballcontact - 40)) && rightpaddleposition.y > 40) {
		
			if (ballposition.y < rightpaddleposition.y - 5 + 40)
			rightpaddleposition.y -= 5;
		}


		



		/*else if (ballposition.y > rightpaddleposition.y + 40)
			rightpaddleposition.y += 5;

		else if (ballposition.y < rightpaddleposition.y - 40)
			rightpaddleposition.y -= 5;

			*/



		if ((ballposition.y <= leftpaddleposition.y + 40 && ballposition.y >= leftpaddleposition.y - 40) && (ballposition.x <= leftpaddleposition.x + 5 && ballposition.x >= leftpaddleposition.x - 5)) {
			slope.x = -slope.x;
			slope.y = static_cast<int>(ballposition.y - leftpaddleposition.y) / 5;

			if (slope.y == 0)
				slope.y++;

		}




		if ((ballposition.y <= rightpaddleposition.y + 40 && ballposition.y >= rightpaddleposition.y - 40) && (ballposition.x <= rightpaddleposition.x + 5 && ballposition.x >= rightpaddleposition.x - 5)) {
			
			try {
				if (clock.getElapsedTime().asMilliseconds() < 500)
					throw L"Exception thrown: Error ball loop\nPlease refer to the \"pongdiagnostic.log\" log file for details";
			}
			catch (wchar_t* e) {
				std::ofstream errorlog;
				errorlog.open("pongdiagnostic.log");
				errorlog << "Begin log file\n--------------------------------------------------------------------------------\n\n" <<
					"Exception type: Error ball loop\n\nFunction: playervcom(sf::RenderWindow & window)\nException thrown on purpose?: Yes\n\nballposition.x: " << ballposition.x << "\nballposition.y: " << ballposition.y <<
					"\nleftpaddleposition.x: " << leftpaddleposition.x << "\nleftpaddleposition.y: " << leftpaddleposition.y <<
					"\nrightpaddleposition.x: " << rightpaddleposition.x << "\nrightpaddleposition.y: " << rightpaddleposition.y <<
					"\ncpuballcontact: " << cpuballcontact << " - 40 = " << cpuballcontact - 40 << "\nIscpuballcontactRand: " << (IscpuballcontactRand ? "true" : "false") <<
					"\nslope.x: " << slope.x << "\nslope.y: " << slope.y << "\nclock.getElapsedTime().asMilliseconds() = " << clock.getElapsedTime().asMilliseconds() <<
					"\n------------------------------------------------------------------------------\nEnd log file\n\nPlease do not modify the contents of this file. Its information can be useful for diagnosing errors, \nand should be sent to me (the creator of the game)." << std::endl;
				errorlog.close();
				MessageBox(NULL, (LPCWSTR)e, (LPCWSTR)L"Exception thrown!", MB_ICONERROR);
				exit(-1);

			}
			cpuballcontact = rand() % 80;
			IscpuballcontactRand = true;
			std::cout << "cpuballcontact = " << cpuballcontact << " - 40 = " << cpuballcontact - 40 << (IscpuballcontactRand ? " (rand)" : "") << "\nclock.asmilliseconds = " << clock.getElapsedTime().asMilliseconds() << std::endl;
			clock.restart();

			slope.x = -slope.x;
			slope.y = static_cast<int>(ballposition.y - rightpaddleposition.y) / 5;
			if (slope.y == 0)
				slope.y++;
		}

		

		if (ballposition.x <= 0) {
			score.y++;
			while (window.isOpen()) {
				fullscreentasks(window, event);
				slope.x = 0, slope.y = 0;
				sf::Text text;
				text.setFont(font);
				text.setCharacterSize(50);
				text.setPosition(60, 100);

				if ((score.x > 1) && (score.y == 0))
					text.setString("You lost! :(\nYou won " + std::to_string(score.x) + " times\nCPU is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x > 1) && (score.y == 1))
					text.setString("You lost! :(\nYou won " + std::to_string(score.x) + " times\nCPU won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x > 1) && (score.y > 1))
					text.setString("You lost! :(\nYou won " + std::to_string(score.x) + " times\nCPU won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y == 0))
					text.setString("You lost! :(\nYou are a loser!\nCPU is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y == 1))
					text.setString("You lost! :(\n\nYou are a loser!\nCPU won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y > 1))
					text.setString("You lost! :(\nYou are a loser!\nCPU won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");


				if ((score.x == 1) && (score.y == 1))
					text.setString("You lost! :(\nYou won once\nCPU won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 1) && (score.y == 0))
					text.setString("You lost! :(\nYou won once\nCPU is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 1) && (score.y > 1))
					text.setString("You lost! :(\nYou won once\nCPU won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");

				window.clear();
				window.draw(text);
				window.pollEvent(event);

				if (essentialeventtasks(window, event, false) == 1) {
					window.clear();
					return;
				}

				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Space)
						goto start;

				}
				window.display();

			}
		}


		

		if (ballposition.x >= 800) {
			try {
				if (slope.y < 5 && slope.y > -5)
					throw L"Exception thrown: AI behavioural flaw\nPlease refer to the \"pongdiagnostic.log\" log file for details";
			}
			
			catch (wchar_t* e) {
				std::ofstream errorlog;
				errorlog.open("pongdiagnostic.log");
				errorlog << "Begin log file\n--------------------------------------------------------------------------------\n\n" << 
					"Exception type: AI behavioural flaw\n\nFunction: playervcom(sf::RenderWindow & window)\nException thrown on purpose?: Yes\n\nballposition.x: " << ballposition.x << "\nballposition.y: " << ballposition.y <<
					"\nleftpaddleposition.x: " << leftpaddleposition.x << "\nleftpaddleposition.y: " << leftpaddleposition.y <<
					"\nrightpaddleposition.x: " << rightpaddleposition.x << "\nrightpaddleposition.y: " << rightpaddleposition.y <<
					"\ncpuballcontact: " << cpuballcontact << " - 40 = " << cpuballcontact - 40 << "\nIscpuballcontactRand: " <<  (IscpuballcontactRand ? "true" : "false") <<
					"\nslope.x: " << slope.x << "\nslope.y: " << slope.y << "\nclock.getElapsedTime().asMilliseconds() = " << clock.getElapsedTime().asMilliseconds() <<
					"\n------------------------------------------------------------------------------\nEnd log file\n\nPlease do not modify the contents of this file. Its information can be useful for diagnosing errors, \nand should be sent to me (the creator of the game)." << std::endl;
				
				std::cerr << "\n\n" << e << "\n\nBegin log file\n--------------------------------------------------------------------------------\n\n" <<
					"\n\nException type : AI behavioural flaw\n\nFunction: playervcom(sf::RenderWindow & window)\nException thrown on purpose ? : Yes\n\nballposition.x: " << ballposition.x << "\nballposition.y: " << ballposition.y <<
					"\nleftpaddleposition.x: " << leftpaddleposition.x << "\nleftpaddleposition.y: " << leftpaddleposition.y <<
					"\nrightpaddleposition.x: " << rightpaddleposition.x << "\nrightpaddleposition.y: " << rightpaddleposition.y <<
					"\ncpuballcontact: " << cpuballcontact << " - 40 = " << cpuballcontact - 40 << "\nIscpuballcontactRand: " << (IscpuballcontactRand ? "true" : "false") <<
					"\nslope.x: " << slope.x << "\nslope.y: " << slope.y << "\nclock.getElapsedTime().asMilliseconds() = " << clock.getElapsedTime().asMilliseconds() <<
					"\n------------------------------------------------------------------------------\nEnd log file\n\nPlease do not modify the contents of this file. Its information can be useful for diagnosing errors, \nand should be sent to me (the creator of the game)." << std::endl;
				errorlog.close();
				MessageBox(NULL, (LPCWSTR)e, (LPCWSTR)L"Exception!", MB_ICONERROR);
				exit(-1);

			}
			
			std::cout << "\n\nslope = " << slope.x << ", " << slope.y << std::endl;
			score.x++;
			while (window.isOpen()) {

				fullscreentasks(window, event);
				slope.x = 0, slope.y = 0;
				sf::Text text;
				text.setFont(font);
				text.setCharacterSize(50);
				text.setPosition(60, 100);

				if ((score.x > 1) && (score.y == 0))
					text.setString("You win!\nYou won " + std::to_string(score.x) + " times\nCPU is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x > 1) && (score.y == 1))
					text.setString("You win!\nYou won " + std::to_string(score.x) + " times\nCPU won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x > 1) && (score.y > 1))
					text.setString("You win!\nYou won " + std::to_string(score.x) + " times\nCPU won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y == 0))
					text.setString("You win!\nYou are a loser!\nCPU is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y == 1))
					text.setString("You win!\n\nYou are a loser!\nCPU won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 0) && (score.y > 1))
					text.setString("You win!\nYou are a loser!\nCPU won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");


				if ((score.x == 1) && (score.y == 1))
					text.setString("You win!\nYou won once\nCPU won once\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 1) && (score.y == 0))
					text.setString("You win!\nYou won once\nCPU is a loser!\n\nPress Space to retry\nPress Esc to return to main menu");

				if ((score.x == 1) && (score.y > 1))
					text.setString("You win!\nYou won once\nCPU won " + std::to_string(score.y) + " times\n\nPress Space to retry\nPress Esc to return to main menu");

				window.clear();
				window.draw(text);
				window.pollEvent(event);

				if (fullscreen)
					fullscreentasks(window, isPaused, event);

				if (essentialeventtasks(window, event, false) == 1) {
					window.clear();
					return;
				}

				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Space)
						goto start;


				}
				window.display();

			}
		}


		


		if (ballposition.y >= 600)
			slope.y = -slope.y;


		if (ballposition.y <= 0)
			slope.y = -slope.y;


		if (!window.hasFocus())
			isPaused = true;


		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space)
				isPaused = true;

		}




		while (isPaused) {




			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && firstrun) {
				window.pollEvent(event);

				fullscreentasks(window, isPaused, event);
				essentialeventtasks(window, event, false);
				sf::Text lefttutorial;
				lefttutorial.setFont(font);
				lefttutorial.setPosition(15, 300);
				lefttutorial.setCharacterSize(23);
				lefttutorial.setColor(sf::Color::Black);
				lefttutorial.setString("Use Up and Down\narrow keys to move");

				sf::Text middletutorial;
				middletutorial.setFont(font);
				middletutorial.setPosition(20, 50);
				middletutorial.setCharacterSize(34);
				middletutorial.setColor(sf::Color::Black);
				middletutorial.setString("Press SPACE at any time to pause the game\n\nYou can return to the main menu from the pause menu");

				sf::Text starttext;
				starttext.setFont(font);
				starttext.setPosition(270, 300);
				starttext.setCharacterSize(32);
				starttext.setColor(sf::Color::Black);
				starttext.setStyle(sf::Text::Underlined | sf::Text::Bold);
				starttext.setString("Press SPACE to start");

				window.draw(starttext);
				window.draw(middletutorial);
				window.draw(lefttutorial);
				window.draw(rightpaddle);
				window.draw(leftpaddle);
				window.display();
				window.clear(sf::Color::Green);
			}


			if (!firstrun) {
				sf::Text pause;
				pause.setPosition(100, 200);
				pause.setFont(font);
				pause.setColor(sf::Color::Black);
				pause.setCharacterSize(50);
				pause.setString("\n\nPress SPACE to resume game\nPress Esc to return to main menu");
				sf::Text bigpause;
				bigpause.setPosition(100, 200);
				bigpause.setFont(font);
				bigpause.setColor(sf::Color::Black);
				bigpause.setStyle(sf::Text::Bold | sf::Text::Underlined);
				bigpause.setCharacterSize(55);
				bigpause.setString("PAUSED");
				window.draw(leftpaddle);
				window.draw(rightpaddle);
				window.draw(bigpause);
				window.draw(pause);
				window.draw(ball);
				window.display();
				window.clear(sf::Color::Green);
			}
			window.pollEvent(event);


			fullscreentasks(window, isPaused, event);

			essentialeventtasks(window, event, false);

			if (essentialeventtasks(window, event, false) == 1) {
				window.clear();
				return;
			}


			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space)
					isPaused = false;

			}

		}

		firstrun = false;
		window.draw(ball);

		window.display();
		window.clear(sf::Color::Green);
	}
	exit(0);
}





























void mainmenu(sf::RenderWindow& window, sf::Font& font) {
	while (window.isOpen()) {
		sf::Event event;
		fullscreentasks(window, event);
		window.pollEvent(event);
		essentialeventtasks(window, event, true);
		sf::Text menutext;
		menutext.setFont(font);
		menutext.setCharacterSize(55);
		menutext.setPosition(65, 100);
		if (!fullscreen)
			menutext.setString("Main menu:\n\nPress 1 for 1 player\nPress 2 for 2 player\nPress 3 for Player vs Computer\nPress 4 to enable fullscreen\nPress Esc to quit");

		if (fullscreen)
			menutext.setString("Main menu:\n\nPress 1 for 1 player\nPress 2 for 2 player\nPress 3 for Player vs Computer\nPress 4 to exit fullscreen\nPress Esc to quit");

		/*	sf::Text smallcredits;
		smallcredits.setFont(font);
		smallcredits.setCharacterSize(20);
		smallcredits.setPosition(300, 550);
		smallcredits.setStyle(sf::Text::Italic);
		smallcredits.setString("Made by Youssef Mikhail\nSpecial Thanks to the creators of SFML library"); */


		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Num1) {
			

				return;
				window.clear();
			}
		}

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Num2) {
				
				twoplayer(window);
				window.setTitle("Pong");
			}
		}

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Num3) {
				
			/*	do
				{
					int action = MessageBox(NULL, (LPCWSTR)L"Still in development. Proceed?", (LPCWSTR)L"Warning", MB_YESNO | MB_ICONWARNING);

					if (action == IDNO)
						break;
						*/
					playervcom(window);

					window.setTitle("Pong");

			//	} while (false);


			}
		}

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Num4) {
				
				if (!fullscreen) {
					MessageBox(NULL, (LPCWSTR)L"If you want to exit fullscreen mode, you can do so later from the main menu.", (LPCWSTR)L"Fullscreen mode", MB_ICONINFORMATION);


					window.close();
					fullscreen = true;
					window.create(sf::VideoMode(800, 600), "Pong", sf::Style::Fullscreen);
					window.setFramerateLimit(90);
					window.setKeyRepeatEnabled(false);
				}

				else if (fullscreen) {
					window.close();
					fullscreen = false;
					window.create(sf::VideoMode(800, 600), "Pong", sf::Style::Close);
					window.setFramerateLimit(90);
					window.setKeyRepeatEnabled(false);
				}
			}
		}


		window.clear();
		//window.draw(smallcredits);
		window.draw(menutext);
		window.display();

	}
}





















int readhighscore() {
	int num = 0;
	char fake1;
	std::string fake2;
	std::ifstream highscore;
	highscore.open("pong.dat");
	
	if (highscore.fail()) {
		MessageBox(NULL, (LPCWSTR)L"Settings and highscores will be stored in \"pong.dat\". (If you are running this game in its zip file, please make sure you extract it or your high score will not be saved)", (LPCWSTR)L"No saved data found", MB_ICONINFORMATION);
		return 0;
	}
	
	highscore.seekg(59);

	highscore >> fake1 >> num >> fake2;

	if (fake2 != "pq3j4jpq483jpaojifpq84" || fake1 != '9') {
		int action = MessageBox(NULL, (LPCWSTR)L"The file \"pong.dat\" is either invalid or has been incorrectly modified. It will now be deleted (this includes settings and high scores). If you think you can fix this problem, you can cancel the operation. However, if you proceed, everything will be deleted.", (LPCWSTR)L"Error reading file", MB_ICONERROR | MB_OKCANCEL);

		if (action == IDCANCEL)
			exit(-1);

		highscore.close();
		do {
			if (remove("pong.dat") != 0) {


				action = MessageBox(NULL, (LPCWSTR)L"Could not delete file", (LPCWSTR)L"Error", MB_ICONERROR | MB_RETRYCANCEL);

				if (action == IDCANCEL) {
					exit(-1);
				}
			}
		 } while (action == IDRETRY);

		
		
		MessageBox(NULL, (LPCWSTR)L"File deleted! (try not to get into any more trouble)", (LPCWSTR)L"File Deleted", MB_ICONINFORMATION | MB_OK);
		return 0;
	}

	//highscore >> fake1 >> num;
	return num;
}





















int writehighscore(int num) {
	//std::string fake1 = "28934h02h4f02f2790f273yfr97y3290fm02n389yfrnm029ryfmn023rfn02893yrfnm02839rfynpoifjqpiojfqiojewfqijowefqpweifojqpwioefj ";
	std::ofstream highscore;
	//char fake2[10] = { 'v','8','4','j','s','0','f','0','f','h','9' };
	highscore.open("pong.dat");

	if (highscore.fail())
		return -1;



		//highscore << fake1 << fake2[0] << fake2[1] << fake2[2] << fake2[3] << fake2[4] << fake2[5] << fake2[6] << fake2[7] << fake2[8] << fake2[9] << fake2[10] <<  num;
	
	highscore << "p2rf8j2p893jfp2893fjp82jf2p8j82jpjpe8jdapoijsdfp98jqf89pj349" << num << "pq3j4jpq483jpaojifpq84";
		
	return num;
}








































int main() {
//	MessageBox(NULL, (LPCWSTR)L"This is not a stable version of Pong", (LPCWSTR)L"BTW...", MB_ICONINFORMATION);
	std::cout << "If you see this console window, then you are currently running a DEBUG build. This version of the game is for testing purposes only, and if you see this, you should get the RELEASE build of Pong, not the debug build\n\n" << std::endl;
	sf::RenderWindow window;

	if (!fullscreen)
	window.create(sf::VideoMode(800, 600), "Pong", (fullscreen ? sf::Style::Fullscreen : sf::Style::Close));


	

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(90);	//This sets the frame rate limit to 90 in order to prevent strain on the video card and to control the speed of the game.
	

	

	

		sf::Font font;

		if (!font.loadFromFile("C:\\Windows\\Fonts\\isocpeur.ttf")) {
			int error;
			do
			{

				if (font.loadFromFile("C:\\Windows\\Fonts\\isocpeur.ttf")) 
					break;

				else if (font.loadFromFile("resources\\isocpeur.ttf"))
					break;
		

				else if (font.loadFromFile("isocpeur.ttf"))
					break;

				else if (font.loadFromFile("C:\\Windows\\Fonts\\impact.ttf")) {
					MessageBox(NULL, (LPCWSTR)L"Isocpeur font not installed on this computer. Using Impact font.\n\nNote: It is recommended that you either copy the font found in this game's zip file, or install it because the Impact font is ugly and looking at it makes me want to puke.", (LPCWSTR)L"Warning", MB_ICONWARNING);
					break;
				}

				error = MessageBox(NULL, (LPCWSTR)L"Could not load font file. You may not have the correct fonts installed. To fix the problem, do one of the following:\n\nRECOMMENDED METHOD\n--------------------\nGo to the resources folder found in this game's zip folder and click on the isocpeur font. You should get a font preview. If you are an administrator, click Install. If you are not an administrator, you can simply copy the resources folder to the same location as the game\n\nALTERNATE METHOD\n------------------\nIf you lost/deleted this game's zip file or cannot redownload it for some reason, copy any TrueType font (with file extension \".ttf\") from \"C:\\Windows\\Fonts\" to the same place as the game, and rename it to \"isocpeur.ttf\" (or just \"isocpeur\" if you do not see a file extension at all).\nWARNING: It is recommended that you use the method above instead of the alternate method, since using a different font file than the one intended for this game will cause the words to either appear to big or too small.", (LPCWSTR)L"Could not load font file", MB_ICONERROR | MB_RETRYCANCEL);
				//error = MessageBox(NULL, (LPCWSTR)L"You forgot to put the resources folder in the same place as the game dumbass!", (LPCWSTR)L"Could not load font file", MB_ICONERROR | MB_RETRYCANCEL);
			} while (error == IDRETRY);

			if (error == IDCANCEL)
				return EXIT_FAILURE;
		}
		menu:
		mainmenu(window, font);
		bool firstrun = true;
		bool isPaused = true;
		int highscore = readhighscore();
	start:
		int consecutive = 0;
		sf::Vector2f ballposition(400, 300);
		sf::Vector2f paddleposition(5, 300);
		sf::CircleShape ball;
		sf::RectangleShape paddle;
		ball.setOrigin(5, 5);
		paddle.setOrigin(5, 40);
		sf::Vector2i slope;
		sf::Vector2i slopeold;
		slope.x = 5;
		slope.y = 3;
		slopeold.y = slope.y;
		int score = 0;
	while (window.isOpen()) {
		sf::Event event;

		ballposition.y += slope.y;
		ballposition.x += slope.x;
		

		



		ball.setPosition(ballposition);
		ball.setFillColor(sf::Color::Red);
		ball.setOutlineColor(sf::Color::Black);
		ball.setOutlineThickness(2);
		ball.setRadius(5);
		window.draw(ball);

		paddle.setPosition(paddleposition);
		paddle.setFillColor(sf::Color::Black);
		paddle.setSize(sf::Vector2f(10, 80));
		window.draw(paddle);

		window.pollEvent(event);
		


		if (essentialeventtasks(window, event, false) == 1) {
			isPaused = true;
			int action = MessageBox(NULL, (LPCWSTR)L"Do you want to quit?", (LPCWSTR)L"Quit?", MB_ICONQUESTION | MB_YESNO);
			
			if (action == IDYES) {
				window.close();
				return 0;
			}
		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddleposition.y > 40)
			paddleposition.y -= 5;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && paddleposition.y < 560)
			paddleposition.y += 5;


		
		if (!window.hasFocus())
			isPaused = true;

		
		fullscreentasks(window, isPaused, event);

	
		 if (ballposition.x <= 0) {

			/* if (score == 0) {
			MessageBox(NULL, (LPCWSTR)L"U GOT 0 SO UR NOT WORTHY TO LIVE ON THIS EARTH NOW UR COMPUTER IS SCREWED!!!!", (LPCWSTR)L"Oh no...", MB_ICONERROR | MB_OK);

			while (true) {
				system("start");
			}

			}

			*/

			bool IsHighscore = false;

			if (score > highscore) {
				IsHighscore = true;
				highscore = score;
				writehighscore(highscore);
			}
				while (window.isOpen()) {
					
					fullscreentasks(window, event);
					slope.x = 0, slope.y = 0;
					sf::Text text;
					text.setFont(font);
					text.setCharacterSize(50);
					text.setPosition(60, 100);
				
					if (IsHighscore) 
						text.setString("NEW HIGH SCORE! :)\nYou scored " + std::to_string(score) + "\n\nYour new high score is " + std::to_string(score) + "\n\nPress Space to retry\nPress Esc to return to main menu");
				
					if (!IsHighscore) {
						if (score >= 1 && score <= highscore)
							text.setString("GAME OVER :(\nYou scored " + std::to_string(score) + "\n\nYour high score is " + std::to_string(highscore) + "\n\nPress Space to retry\nPress Esc to return to main menu");

						if (score == 0 && highscore > 0) 
							text.setString("GAME OVER :(\nYou really suck at this!\n\nYour high score is " + std::to_string(highscore) + "\n\nPress Space to retry\nPress Esc to return to main menu");
					
						if ((score == highscore || score == highscore - 1) && !IsHighscore)
							text.setString("SOOOO CLOSE! :(\nYou scored " + std::to_string(score) + "\n\nYour high score is " + std::to_string(highscore) + "\n\nPress Space to retry\nPress Esc to return to main menu");

						if (score == 0 && highscore == 0) {
							text.setString("GAME OVER :(\nYou really suck at this!\n\nNo wonder you have no high score...\n\nPress Space to retry\nPress Esc to return to main menu");
						}


					}

					window.clear();	
					window.draw(text);
					window.pollEvent(event);


					if (essentialeventtasks(window, event, false) == 1) {
						goto menu;

					}
					if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Space) {
							goto start;
						}
							
					}
					window.display();

				}

				

		}


		 if ((ballposition.y <= paddleposition.y + 40 && ballposition.y >= paddleposition.y - 40) && (ballposition.x <= paddleposition.x + 5 && ballposition.x >= paddleposition.x - 5)) {
			 slope.x = -slope.x;


			 slope.y = static_cast<int>(ballposition.y - paddleposition.y) / 5;



			 score++;





			 if (slope.y == 0)
				 slope.y++;

			 if (slopeold.y == slope.y)
				 consecutive++;
			 if (slopeold.y != slope.y) {
				 slopeold.y = slope.y;
				 consecutive = 0;
			 }
			 if (consecutive == 5) {
				 consecutive = 0;
				 slope.y = 10;
				 slopeold.y = slope.y;
			 }


			 slopeold.y = slope.y;


		 }




		if (ballposition.y >= 600) 
			slope.y = -slope.y;

		if (ballposition.y <= 0)
			slope.y = -slope.y;

		if (ballposition.x >= 800) 
			slope.x = -slope.x;


		sf::Text scoretext;
		scoretext.setFont(font);
		scoretext.setCharacterSize(40);
		scoretext.setPosition(740, 550);
		scoretext.setColor(sf::Color::Black);
		scoretext.setString(std::to_string(score));
		window.draw(scoretext);


	if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space) 
				isPaused = true;
			
		}


		
		while (isPaused) {
		
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && firstrun) {
				
				fullscreentasks(window, isPaused, event);
				window.pollEvent(event);
				essentialeventtasks(window, event, false);
				sf::Text lefttutorial;
				lefttutorial.setFont(font);
				lefttutorial.setPosition(15, 300);
				lefttutorial.setCharacterSize(25);
				lefttutorial.setColor(sf::Color::Black);
				lefttutorial.setString("Use Up and Down\narrow keys to move");

				sf::Text starttext;
				starttext.setFont(font);
				starttext.setPosition(250, 300);
				starttext.setCharacterSize(35);
				starttext.setColor(sf::Color::Black);
				starttext.setStyle(sf::Text::Bold | sf::Text::Underlined);
				starttext.setString("Press SPACE to start");

				sf::Text middletutorial;
				middletutorial.setFont(font);
				middletutorial.setPosition(20, 50);
				middletutorial.setCharacterSize(34);
				middletutorial.setColor(sf::Color::Black);
				middletutorial.setString("Press SPACE at any time to pause the game\n\nYou can return to the main menu from the pause menu");

				window.draw(starttext);
				window.draw(middletutorial);
				window.draw(lefttutorial);
				window.draw(paddle);
				window.display();
				window.clear(sf::Color::Green);
			}

			if (!firstrun) {
				sf::Text pause;
				pause.setPosition(100, 200);
				pause.setFont(font);
				pause.setColor(sf::Color::Black);
				pause.setCharacterSize(50);
				pause.setString("\n\nPress SPACE to resume game\nPress Esc to return to main menu");
				sf::Text bigpause;
				bigpause.setPosition(100, 200);
				bigpause.setFont(font);
				bigpause.setColor(sf::Color::Black);
				bigpause.setStyle(sf::Text::Bold | sf::Text::Underlined);
				bigpause.setCharacterSize(55);
				bigpause.setString("PAUSED");
				window.draw(bigpause);
				window.draw(pause);
				window.draw(ball);
				window.draw(paddle);
				window.draw(scoretext);
				window.display();
				window.clear(sf::Color::Green);
			}
				window.pollEvent(event);
			
			
				fullscreentasks(window, isPaused, event);

			if (essentialeventtasks(window, event, false) == 1) {
				
					goto menu;
				
			}
			
	
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space)
					isPaused = false;

			}

		}

		firstrun = false;
		window.display();
	

		window.clear(sf::Color::Green);

		}
	return 0;

}
