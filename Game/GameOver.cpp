#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"
#include "SoundManager.h"

GameOver::~GameOver()
{
	SoundManager* soundManager = FindGO<SoundManager>("soundmanager");
	soundManager->SoundDeleteGO(enSoundList_GameOverBGM);
}

bool GameOver::Start()
{
	m_spriteRender.Init("Assets/sprite/gameover.dds", 1920.0f, 1080.0f);

	SoundManager* soundManager = FindGO<SoundManager>("soundmanager");
	soundManager->SoundNewGO(enSoundList_GameOverBGM);

	return true;
}

void GameOver::Update()
{
	if (g_pad[0]->IsTrigger(enButtonX))
	{
		DeleteGO(this);
		NewGO<Title>(0, "title");
	}
}

void GameOver::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}
