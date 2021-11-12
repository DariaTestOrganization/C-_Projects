#include "Game.h"

void Game::initVariables()
{
	this->gameSpeed = 1.f;
	isGameOver = false;
	isGameOnPause = false;
	this->mouseHeld = false;
	isNewGame = true;
	
}

void Game::initWindow()
{
	this->window = new RenderWindow(VideoMode(600, 800), "Car Race", Style::Close | Style::Titlebar);
	this->window->setFramerateLimit(200);
	this->window->setVerticalSyncEnabled(false);
}



void Game::initBackground()
{
	this->bg1.loadFromFile("Texture/bg1.png");
	gameBackground1.setTexture(bg1);
	this->bg2.loadFromFile("Texture/bg2.png");
	gameBackground2.setTexture(bg2);
	gameBackground2.setPosition(0.f, -gameBackground2.getGlobalBounds().height);
}

void Game::initTextures()
{
	this->elementTextures["Coin"] = new Texture();
	this->elementTextures["Coin"]->loadFromFile("Texture/coin.png");
	this->elementTextures["Heart"] = new Texture();
	this->elementTextures["Heart"]->loadFromFile("Texture/heart.png");
	this->elementTextures["Stop"] = new Texture();
	this->elementTextures["Stop"]->loadFromFile("Texture/stop.png");
	this->elementTextures["Jerrycan"] = new Texture();
	this->elementTextures["Jerrycan"]->loadFromFile("Texture/jerrycan.png");
	this->elementTextures["Car"] = new Texture();
	this->elementTextures["Car"]->loadFromFile("Texture/car.png");

}

void Game::initCar()
{
	this->myCar = new MyCar();
	this->myCar->setPosition(this->window->getSize().x/2 - this->myCar->getBounds().width / 2, 600.f);
}

void Game::initState()
{
	this->carHpBar.setSize(Vector2f(300.f, 25.f));
	this->carHpBar.setFillColor(Color::Green);
	this->carHpBar.setPosition(Vector2f(20.f, 20.f));

	this->carHpBarBack = this->carHpBar;
	this->carHpBarBack.setFillColor(Color(25, 25, 25, 200));

	this->carFuelBar.setSize(Vector2f(300.f, 25.f));
	this->carFuelBar.setFillColor(Color::Blue);
	this->carFuelBar.setPosition(Vector2f(20.f, 55.f));

	this->carFuelBarBack = this->carFuelBar;
	this->carFuelBarBack.setFillColor(Color(25, 25, 25, 200));

	this->infoBackground.setSize(Vector2f(575.f, 300.f));
	this->infoBackground.setFillColor(Color::White);
	this->infoBackground.setPosition(this->window->getSize().x / 2 - this->infoBackground.getGlobalBounds().width / 2.f, this->window->getSize().y / 2 - this->infoBackground.getGlobalBounds().height / 2.f +20.f);
	this->infoBackground.setOutlineThickness(3.f);
	this->infoBackground.setOutlineColor(Color::Black);


	this->font.loadFromFile("Fonts/PixellettersFull.ttf");
	this->pointsText.setPosition(400.f, 20.f);
	this->pointsText.setFont(this->font);
	this->pointsText.setCharacterSize(40);
	this->pointsText.setFillColor(Color::Black);
	this->pointsText.setString("Points: ");

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(80);
	this->gameOverText.setFillColor(Color::Black);
	this->gameOverText.setString("GAME OVER!");
	this->gameOverText.setPosition(this->window->getSize().x / 2 - this->gameOverText.getGlobalBounds().width / 2.f, this->window->getSize().y / 3);

	this->pauseTexture.loadFromFile("Texture/pause.png");
	this->pause.setTexture(pauseTexture);
	this->pause.setPosition(530.f, 15.f);

	this->playTexture.loadFromFile("Texture/play.png");
	this->play.setTexture(playTexture);
	this->play.setPosition(530.f, 15.f);

	this->newGameText.setFont(this->font);
	this->newGameText.setCharacterSize(50);
	this->newGameText.setFillColor(Color::Black);
	this->newGameText.setString("To start new game Press N");
	this->newGameText.setPosition(this->window->getSize().x / 2 - this->newGameText.getGlobalBounds().width / 2.f, this->window->getSize().y / 2 - 20.f);

	this->saveProgress.setFont(this->font);
	this->saveProgress.setCharacterSize(50);
	this->saveProgress.setFillColor(Color::Black);
	this->saveProgress.setString("To save game Press S");
	this->saveProgress.setPosition(this->window->getSize().x / 2 - this->saveProgress.getGlobalBounds().width / 2.f, this->window->getSize().y / 2 + 40.f);

	this->continueGame.setFont(this->font);
	this->continueGame.setCharacterSize(50);
	this->continueGame.setFillColor(Color::Black);
	this->continueGame.setString("To start last saved game Press C");
	this->continueGame.setPosition(this->window->getSize().x / 2 - this->continueGame.getGlobalBounds().width / 2.f, this->window->getSize().y / 2+100.f);


}

void Game::initElements()
{
	this->elTimerMax = 80.f;
	this->elTimer = this->elTimerMax;
}


Game::Game()
{
	this->initWindow();
	this->initBackground();
	this->initVariables();
	this->initCar();
	this->initTextures();
	this->initElements();
	this->initState();
}

Game::~Game()
{
	delete window;
	delete myCar;

	for (auto& i : this->elementTextures)
	{
		delete i.second;
	}
	for (auto* i : this->elements)
	{
		delete i;
	}
	
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->updatePollEvents();
		if(!isGameOver && !isGameOnPause && !isNewGame)
			this->update();
		
		this->render();
	}
	

}

void Game::newGame()
{
	gameSpeed = 1.f;
	myCar->setFuel(myCar->getFuelMax());
	myCar->setHp(myCar->getHpMax());
	myCar->setCoins(0);
	elements.clear();
	this->myCar->setPosition(this->window->getSize().x / 2 - this->myCar->getBounds().width / 2, 600.f);
	
}

void Game::updatePollEvents()
{
	
	while (this->window->pollEvent(ev)) {

		
		if (ev.Event::type == Event::Closed)
			this->window->close();
		if (ev.Event::KeyPressed && ev.Event::key.code == Keyboard::Escape)
			this->window->close();

		if (ev.Event::KeyPressed && ev.Event::key.code == Keyboard::N) {
			if(isGameOver)
				this->isGameOver = false;
			if (isNewGame)
				this->isNewGame = false;
			if (isGameOnPause)
				this->isGameOnPause = false;
			newGame();
		}
			
		if (ev.Event::KeyPressed && ev.Event::key.code == Keyboard::S) {
			fs.open("gameProgress.txt", ios::out);
			if (fs.is_open()) {
				fs << gameSpeed << " ";
				fs << myCar->getHp() << " ";
				fs << myCar->getFuel() << " ";
				fs << myCar->getCoins() << endl;
				fs.close();
			}
		}

		if (ev.Event::KeyPressed && ev.Event::key.code == Keyboard::C) {
			fs.open("gameProgress.txt", ios::in);
			string buff;
			if (fs.is_open()) {
				if (fs.peek() == EOF) {
					newGame();
					break;
				}	
				getline(fs, buff);
				stringstream ss(buff);
				ss >> gameSpeed;
				myCar->setSavedParametrs(ss);
				fs.close();
			}
			if (isGameOnPause)
				this->isGameOnPause = false;
			if (isGameOver)
				this->isGameOver = false;
			if (isNewGame)
				this->isNewGame = false;
		}

		if (ev.type == ev.MouseButtonPressed && ev.mouseButton.button == Mouse::Left) {
			
			if (this->pause.getGlobalBounds().contains(this->mousePosView)) {
				isGameOnPause = true;
			}else if(this->play.getGlobalBounds().contains(this->mousePosView)){
				
				isGameOnPause = false;
				
			}
			
		}

	}
}

void Game::updateMousePosition()
{
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);

}

void Game::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
		this->myCar->move(-0.5f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		this->myCar->move(0.5f, 0.f);
}

void Game::updateBackground()
{
	if (gameBackground1.getGlobalBounds().top >= this->window->getSize().y)
		gameBackground1.setPosition(0.f, gameBackground2.getGlobalBounds().top -gameBackground1.getGlobalBounds().height);
	if (gameBackground2.getGlobalBounds().top >= this->window->getSize().y)
		gameBackground2.setPosition(0.f, gameBackground1.getGlobalBounds().top -gameBackground2.getGlobalBounds().height);

	gameBackground1.move(0.f, gameSpeed);
	gameBackground2.move(0.f, gameSpeed);

}

void Game::updateSpeed()
{
	gameSpeed += 0.0005f;
}

void Game::updateCollision()
{
	if (this->myCar->getBounds().left < this->window->getSize().x/2 - 80.f)
		this->myCar->setPosition(this->window->getSize().x/2 - 80.f, 600.f);
	if (this->myCar->getBounds().left > this->window->getSize().x / 2 - this->myCar->getBounds().width + 80.f)
		this->myCar->setPosition(this->window->getSize().x / 2 - this->myCar->getBounds().width + 80.f, 600.f);

}

void Game::updateElements()
{
	this->elTimer += 0.2f*gameSpeed;
	if (this->elTimer>=this->elTimerMax)
	{
		int pos = rand()%3+1;
		switch (rand()%4) {
		case 0:
			this->elements.push_back(new Coin(this->elementTextures["Coin"], pos));
			break;
		case 1:
			this->elements.push_back(new Heart(this->elementTextures["Heart"], pos));
			break;
		case 2:
			this->elements.push_back(new Stop(this->elementTextures["Stop"], pos));
			break;
		case 3:
			this->elements.push_back(new Fuel(this->elementTextures["Jerrycan"], pos));
			break;
		}

		
		if (pos == 1) {
			switch (rand() % 4)
			{
			case 0:
				this->elements.push_back(new Car(this->elementTextures["Car"], 2));
				break;
			case 1:
				this->elements.push_back(new Car(this->elementTextures["Car"], 3));
				break;
			case 2:
				this->elements.push_back(new Car(this->elementTextures["Car"], 2));
				this->elements.push_back(new Car(this->elementTextures["Car"], 3));
				break;
			case 3:
				this->elements.push_back(new MovingCar(this->elementTextures["Car"], 2));
				break;
			default:
				break;
			}
		}
		else if (pos == 2) {
			switch (rand()%2)
			{
			case 0:
				this->elements.push_back(new Car(this->elementTextures["Car"], 1));
				break;
			case 1:
				this->elements.push_back(new Car(this->elementTextures["Car"], 3));
				break;
			default:
				break;
			}
			
		}
		else if (pos == 3) {
			switch (rand() % 4)
			{
			case 0:
				this->elements.push_back(new Car(this->elementTextures["Car"], 1));
				break;
			case 1:
				this->elements.push_back(new Car(this->elementTextures["Car"], 2));
				break;
			case 2:
				this->elements.push_back(new Car(this->elementTextures["Car"], 1));
				this->elements.push_back(new Car(this->elementTextures["Car"], 2));
				break;
			case 3:
				this->elements.push_back(new MovingCar(this->elementTextures["Car"], 1));
				break;
			default:
				break;
			}
		}

		this->elTimer = 0.f;
	}

	unsigned counter = 0;
	for (auto* i : this->elements) {
		i->setMovementSpeed(gameSpeed);
		i->update();

		
		if (i->getBounds().top > this->window->getSize().y) {

			delete this->elements.at(counter);

			this->elements.erase(this->elements.begin() + counter);

		}
		else if (i->getBounds().intersects(this->myCar->getBounds())) {

			i->effect(*myCar);

			delete this->elements.at(counter);

			this->elements.erase(this->elements.begin() + counter);
			

		}
		
		++counter;
	}

}

void Game::updateState()
{
	stringstream ss;
	ss << "Coins: " << this->myCar->getCoins();
	this->pointsText.setString(ss.str());


	float hpPercent = static_cast<float>(this->myCar->getHp()) / this->myCar->getHpMax();
	this->carHpBar.setSize(Vector2f(300.f * hpPercent, this->carHpBar.getSize().y));
	float fuelPercent = static_cast<float>(this->myCar->getFuel()) / this->myCar->getFuelMax();
	this->carFuelBar.setSize(Vector2f(300.f * fuelPercent, this->carFuelBar.getSize().y));
	
	if (myCar->getHp() == 0 || myCar->getFuel() == 0)
		isGameOver = true;

	
	
}


void Game::update()
{
	this->updateInput();
	this->updateMousePosition();
	this->updateSpeed();
	this->updateBackground();
	this->myCar->update();
	this->updateCollision();
	this->updateElements();
	this->updateState();

}


void Game::renderGameOver()
{

	if (isGameOver) {
		this->window->draw(this->infoBackground);
		this->gameOverText.setString("GAME OVER!");
		this->gameOverText.setPosition(this->window->getSize().x / 2 - this->gameOverText.getGlobalBounds().width / 2.f, this->window->getSize().y / 3);

		this->window->draw(this->gameOverText);
		this->window->draw(this->newGameText);
		this->window->draw(this->continueGame);
		
	}
	if (isNewGame) {
		this->window->draw(this->infoBackground);
		this->gameOverText.setString("NEW GAME");
		
		this->window->draw(this->gameOverText);
		this->window->draw(this->newGameText);
		this->window->draw(this->continueGame);
	}

}

void Game::renderState()
{
	this->window->draw(this->pointsText);
	this->window->draw(this->carHpBarBack);
	this->window->draw(this->carHpBar);
	this->window->draw(this->carFuelBarBack);
	this->window->draw(this->carFuelBar);

	
	if (isGameOnPause) {
		this->window->draw(this->infoBackground);
		this->pause.setPosition(0.f, 0.f);
		this->play.setPosition(530.f, 15.f);
		this->window->draw(this->play);
		this->gameOverText.setString("PAUSE");
		this->gameOverText.setPosition(this->window->getSize().x / 2 - this->gameOverText.getGlobalBounds().width / 2.f, this->window->getSize().y / 3);
		this->window->draw(this->gameOverText);
		this->window->draw(this->newGameText);
		this->window->draw(this->saveProgress);
		this->window->draw(this->continueGame);
	}
	else {
		this->play.setPosition(0.f, 0.f);
		this->pause.setPosition(530.f, 15.f);
		this->window->draw(this->pause);
	}
	
}

void Game::render()
{
	this->window->clear();
	this->window->draw(this->gameBackground1);
	this->window->draw(this->gameBackground2);

	

	this->myCar->render(this->window);
	for (auto element : elements)
	{
		element->render(this->window);
	}
	this->renderState();

	
	

	
	this->renderGameOver();

	this->window->display();
}


