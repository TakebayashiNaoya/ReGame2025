#include "stdafx.h"
#include "Game.h"
#include "BackGround.h"
#include "Player.h"
#include "GameCamera.h"
#include "Item.h"
#include "GameClear.h"
#include "GameOver.h"
#include "SoundManager.h"

namespace
{
	const Vector3 ITEM_POSITIONS[] =
	{
		{ 0.0f,25.0f,1100.0f },
		{ 0.0f,420.0f,2460.0f },
		{ 0.0f,740.0f,3950.0f },
		{ 0.0f,-870.0f,4100.0f },
		{ 0.0f,-380.0f,6500.0f }
	};

	const float FALL_DEATH_HEIGHT = -1500.0f;
}

Game::~Game()
{
	DeleteGO(m_backGround);
	DeleteGO(m_player);
	DeleteGO(m_gameCamera);

	SoundManager* soundManager = FindGO<SoundManager>("soundmanager");
	soundManager->SoundDeleteGO(enSoundList_InGameBGM);
}

bool Game::Start()
{
	// UIの点滅を途切れさせにくいようフレーム処理。
	switch (m_initPhase)
	{
	case enInitPhase_First:
		m_backGround = NewGO<BackGround>(0, "BackGround");
		m_initPhase = enInitPhase_Second;
		return false;

	case enInitPhase_Second:
		m_player = NewGO<Player>(0, "BattleCharacter");
		m_initPhase = enInitPhase_Third;
		return false;

	case enInitPhase_Third:
		m_gameCamera = NewGO<GameCamera>(0, "GameCamera");
		m_initPhase = enInitPhase_Fourth;
		return false;

	case enInitPhase_Fourth:
		SpawnStars();
		m_initPhase = enInitPhase_Fifth;
		return false;

	case enInitPhase_Fifth:
		InitSky();
		m_initPhase = enInitPhase_Sixth;
		return false;

	case enInitPhase_Sixth:
		SoundManager* soundManager = FindGO<SoundManager>("soundmanager");
		soundManager->SoundNewGO(enSoundList_InGameBGM);
		break;
	}

	return true;
}

void Game::Update()
{
	OnGameClear();
	OnGameOver();
}

void Game::InitSky()
{
	// 現在の空を破棄。
	DeleteGO(m_skyCube);

	m_skyCube = NewGO<SkyCube>(0, "skycube");
	m_skyCube->SetType((EnSkyCubeType)m_skyCubeType);
	m_skyCube->SetPosition(m_skyCubePos);

	// 環境光の計算のためのIBLテクスチャをセットする。
	g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 0.1f);
}

void Game::SpawnStars()
{
	for (const Vector3& pos : ITEM_POSITIONS)
	{
		Item* item = NewGO<Item>(0, "star");
		item->SetPosition(pos);
		m_starSum++;
	}
}

void Game::OnGameClear()
{
	if (m_starSum == m_itemGetCount)
	{
		DeleteGO(this);
		NewGO<GameClear>(0, "gameclear");
	}
}

void Game::OnGameOver()
{
	if (m_player->GetPosition().y < FALL_DEATH_HEIGHT)
	{
		NewGO<GameOver>(0, "gameover");
		DeleteGO(this);
	}
}
