/// <summary>
/// ゲームの進行を管理するクラス。
/// </summary>
#pragma once

#include "Level3DRender/LevelRender.h"

class BackGround;
class Player;
class GameCamera;

class Game : public IGameObject
{
private:
	enum EnInitPhase
	{
		enInitPhase_First,
		enInitPhase_Second,
		enInitPhase_Third,
		enInitPhase_Fourth,
		enInitPhase_Fifth,
		enInitPhase_Sixth,
	};
	int m_initPhase = 0;

public:
	~Game();

	/// <summary>
	/// 取得したアイテムのカウントを増やします。
	/// </summary>
	void IncrementItemGetCount()
	{
		m_itemGetCount++;
	}

private:
	bool Start()override final;
	void Update()override final;

	/// <summary>
	/// 空を初期化。
	/// </summary>
	void InitSky();

	/// <summary>
	/// スターを生成します。
	/// </summary>
	void SpawnStars();

	/// <summary>
	/// ゲームクリアの処理です。
	/// アイテムを全て取得したらゲームクリア。
	/// </summary>
	void OnGameClear();

	/// <summary>
	/// ゲームオーバーの処理です。
	/// 一定の高さまで落下したらゲームオーバー。
	/// </summary>
	void OnGameOver();

	BackGround* m_backGround = nullptr;
	Player* m_player = nullptr;
	GameCamera* m_gameCamera = nullptr;

	int m_itemGetCount = 0;
	int m_starSum = 0;

	SkyCube* m_skyCube = nullptr;		//スカイキューブ。
	Vector3 m_skyCubePos = Vector3::Zero;
	int m_skyCubeType = enSkyCubeType_Day;
};