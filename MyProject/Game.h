#pragma once
#include "MyCar.h"
#include "Coin.h"
#include "Heart.h"
#include "Fuel.h"
#include "Stop.h"
#include "Car.h"
#include "MovingCar.h"

class Game
{
private:

	RenderWindow* window;
	Event ev;

	Vector2i mousePosWindow;
	Vector2f mousePosView;
	bool mouseHeld;

	Texture bg1;
	Texture bg2;
	map<string, Texture*> elementTextures;
	Texture myCarTexture;
	Sprite gameBackground1;
	Sprite gameBackground2;

	Texture pauseTexture;
	Texture playTexture;
	Sprite pause;
	Sprite play;

	Font font;
	Text gameOverText;
	Text newGameText;
	Text pointsText;
	Text continueGame;
	Text saveProgress;

	MyCar* myCar;
	vector<Element*> elements;
	float elTimer;
	float elTimerMax;

	RectangleShape carHpBar;
	RectangleShape carHpBarBack;
	RectangleShape carFuelBar;
	RectangleShape carFuelBarBack;
	RectangleShape infoBackground;

	fstream fs;

	float gameSpeed;
	bool isGameOver;
	bool isGameOnPause;
	bool isNewGame;

	void initVariables();
	void initWindow();
	void initBackground();
	void initTextures();
	void initCar();
	void initState();
	void initElements();

public:
	Game();
	virtual ~Game();

	void run();
	void newGame();

	void updatePollEvents();
	void updateMousePosition();
	void updateInput();
	void updateBackground();
	void updateSpeed();
	void updateCollision();
	void updateElements();
	void updateState();
	void update();

	void renderGameOver();
	void renderState();
	void render();
};


