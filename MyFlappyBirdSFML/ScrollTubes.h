#pragma once

#include "TubeDown.h"
#include "TubeUp.h"
#include "Globals.h"
#include "Bird.h"


class ScrollTubes;

struct TubesPair {
	TubesPair() {
		tdown = new TubeDown(); 
		tdown->Init();
		tup = new TubeUp();
		tup->Init();
		this->givePointsFlag = false;
	}
	~TubesPair() {
		if (tup) { delete tup; }
		if (tdown) { delete tdown; }
	}

	void Random() {
		tup->RandomHeight();
		tdown->RandomHeight();
		SetPosition(tup->GetX(), tup->GetY());
	}

	void Update(float time) {
		tdown->Update(time);
		tup->Update(time);
	}

	void SetVelocity(float vel) {
		tdown->SetVelocityX(vel);
		tup->SetVelocityX(vel);
	}
	
	void SetPosition(int x, int y) {
		tup->SetPosition(x, y);
		tdown->SetPosition(x, HEIGHT - 110);
	}

	bool Collision(const Object& obj) const {
		return tdown->Collision(obj) || tup->Collision(obj);
	}

	void Render(sf::RenderWindow * window) {
		tdown->Render(window);
		tup->Render(window);
	}
	
private:
	TubeDown* tdown;	
	TubeUp* tup;

	bool givePointsFlag;

	friend class ScrollTubes;
};

class ScrollTubes {
public:
	ScrollTubes(Bird* bird) : speed(-0.1) {
		this->bird = bird;
		const int x = WIDTH, y = 0;
		const int space = 200;
		const int N = 3;

		for (int i = 0; i < N; ++i) {
			tubes.push_back(new TubesPair());
			tubes[i]->SetPosition(x + i*tubes[i]->tup->GetWidth() + i*space, y);
		}
	}
	
	~ScrollTubes() {
		for (int i = 0; i < tubes.size(); ++i) {
			if (tubes[i] != NULL)
				delete tubes[i];
		}
		tubes.clear();
	}
	
	void StartScroll() {
		for (int i = 0; i < tubes.size(); ++i) {
			tubes[i]->SetVelocity(speed);
		}
	}
	
	void StopScroll() {
		for (int i = 0; i < tubes.size(); ++i) {
			tubes[i]->SetVelocity(0.0);
		}
	}
	
	void Update(float time) {
		for (int i = 0; i < tubes.size(); ++i) {
			tubes[i]->Update(time);
		}
		moveFirstTube();
		givePointsForBird();
	}

	void Render(sf::RenderWindow * window) {
		for (int i = 0; i < tubes.size(); i++)
		{
			tubes[i]->Render(window);
		}
	}

	bool Collision(const Object& obj) const {
		for (int i = 0; i < tubes.size(); ++i) {
			if (tubes[i]->Collision(obj))
				return true;
		}
		return false;
	}


private:
	std::vector<TubesPair*> tubes;
	Bird* bird;

	const float speed;

	void moveFirstTube() {
		int posx = tubes[0]->tup->GetX();
		int width = tubes[0]->tup->GetWidth();
		if (posx + width < 0) {
			TubesPair* tube = tubes[0];
			tubes.erase(tubes.begin());
			tube->SetPosition(WIDTH, 0);
			tube->Random();
			tube->givePointsFlag = false;
			tubes.push_back(tube);
		}
	}

	void givePointsForBird() {
		for (int i = 0; i < tubes.size(); ++i) {
			if (bird->GetX() > tubes[i]->tup->GetX() + tubes[i]->tup->GetWidth() && !tubes[i]->givePointsFlag) {
				bird->AddPoint();
				tubes[i]->givePointsFlag = true;
// display score
			}
		}
	}
};
