#include <vector>
#include <memory>
#include "game.h"
#include "GameObject/Background.h"
#include "GameObject/Text.h"
#include "GameObject/car.h"
#include "Utility/Uti.h"

//Form move track
int roadDivTop = 0;
int roadDivMdl = 0;
int roadDivBtm = 0;

BackGround* backgroud;
Text* text;
std::vector<std::unique_ptr<CarObject>> enemyCar;
std::unique_ptr<CarObject> Player;


Game::Game(unsigned int width, unsigned int height) : State(Init), FPS(50), Width(width), Height(height), level(0), score(0)
{

}

Game::~Game()
{
	delete backgroud;
	delete text;
}

void Game::init()
{
	backgroud = new BackGround();
	text = new Text();
	Player = std::make_unique<CarObject>(0, 0, 0.0f, 0.0f, 0.0f);
	resetEnemyCars(); // 初始化或重置 enemyCar
}

void Game::resetEnemyCars() {
	enemyCar.clear();

	// 重新添加新的 CarObject 实例
	enemyCar.push_back(std::make_unique<CarObject>(0, 0, 1.0f, 0.0f, 0.0f));
	enemyCar.push_back(std::make_unique<CarObject>(0, 35, 0.294f, 0.000f, 0.510f));
	enemyCar.push_back(std::make_unique<CarObject>(0, 70, 1.000f, 0.271f, 0.000f));
}

void Game::ProcessInput(unsigned char key)
{
	switch (key)
	{
		case ' ':
			if (State == Init || State == End)
			{
				State = Start;
				FPS = 50;
				roadDivTop = 0;
				roadDivMdl = 0;
				roadDivBtm = 0;
				score = 0;
				level = 0;
				Game::resetEnemyCars();
			}
			break;
		case 'q':
			State = End;
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}


void Game::ProcessInputSpec(unsigned int key)
{
	switch (key)
	{
		case GLUT_KEY_LEFT:
			if (Player->lrIndex >= 0)
			{
				Player->lrIndex = Player->lrIndex - (FPS / 10);
				if (Player->lrIndex < 0) {
					Player->lrIndex = -1;
				}
			}
			break;
		case GLUT_KEY_RIGHT:
			if (Player->lrIndex <= 45)
			{
				Player->lrIndex = Player->lrIndex + (FPS / 10);
				if (Player->lrIndex > 45) {
					Player->lrIndex = 45;
				}
			}
			break;
		default:
			break;
	}
}

void Game::update()
{
	if (State != Start) return;
	//level Print
	if (score % 50 == 0) {
		int last = score / 50;
		if (last != level) {
			level = score / 50;
			FPS = FPS + 2;
		}
	}

	roadDivTop--;
	roadDivMdl--;
	roadDivBtm--;

	if (roadDivTop < -100)
	{
		roadDivTop = 20;
		score++;
	}
	if (roadDivMdl < -60)
	{
		roadDivMdl = 60;
		score++;
	}
	if (roadDivBtm < -20)
	{
		roadDivBtm = 100;
		score++;
	}

	for (const std::unique_ptr<CarObject>& car : enemyCar)
	{
		car->offset--;
		if (car->offset < -100)
		{
			//reborn
			car->reset(Player->lrIndex, 0);
		}
	}
	DoCollisions();

}

void Game::DoCollisions()
{
	for (std::unique_ptr<CarObject>& car : enemyCar)
	{
		// Kill check car
		if (std::abs(Player->lrIndex - car->lrIndex) < 8 && (100 + car->offset) < 13)
		{
			State = End;
			break;
		}
	}
}

void Game::drawCar()
{
	for (auto& car : enemyCar)
	{
		car->draw();
	}

	Player->drawPlayer();
}

void Game::Render()
{
	switch (State)
	{
		case Init:
			backgroud->drawBackGround();
			backgroud->drawRoadInit();
			backgroud->drawHill();
			backgroud->drawTree();
			text->RenderTextInit();
			break;
		case Start:
			glClearColor(0.000, 0.392, 0.000, 1);
			backgroud->drawRoadStart();
			backgroud->drawRoadDynamic(roadDivTop, roadDivMdl, roadDivBtm);
			text->RenderTextStart(score, FPS, level);
			drawCar();
			break;
		case End:
			backgroud->drawBackGround();
			backgroud->drawRoadInit();
			backgroud->drawHill();
			backgroud->drawTree();
			text->RenderTextInit();
			text->RenderTextEnd(score);
			break;
		default:
			break;
	}
}

void Game::reset()
{
	State = Init;
}
