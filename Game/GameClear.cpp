#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "SoundManager.h"

GameClear::~GameClear()
{
	SoundManager* soundManager = FindGO<SoundManager>("soundmanager");
	soundManager->SoundDeleteGO(enSoundList_GameClearBGM);
}

bool GameClear::Start()
{
	m_spriteRender.Init("Assets/sprite/gameclear.dds", 1920.0f, 1080.0f);

	SoundManager* soundManager = FindGO<SoundManager>("soundmanager");
	soundManager->SoundNewGO(enSoundList_GameClearBGM);

	return true;
}

void GameClear::Update()
{
	if (g_pad[0]->IsTrigger(enButtonX))
	{
		DeleteGO(this);
		NewGO<Title>(0, "title");
	}
}

void GameClear::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}
