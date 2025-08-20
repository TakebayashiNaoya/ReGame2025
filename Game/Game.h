/// <summary>
/// �Q�[���̐i�s���Ǘ�����N���X�B
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
	/// �擾�����A�C�e���̃J�E���g�𑝂₵�܂��B
	/// </summary>
	void IncrementItemGetCount()
	{
		m_itemGetCount++;
	}

private:
	bool Start()override final;
	void Update()override final;

	/// <summary>
	/// ����������B
	/// </summary>
	void InitSky();

	/// <summary>
	/// �X�^�[�𐶐����܂��B
	/// </summary>
	void SpawnStars();

	/// <summary>
	/// �Q�[���N���A�̏����ł��B
	/// �A�C�e����S�Ď擾������Q�[���N���A�B
	/// </summary>
	void OnGameClear();

	/// <summary>
	/// �Q�[���I�[�o�[�̏����ł��B
	/// ���̍����܂ŗ���������Q�[���I�[�o�[�B
	/// </summary>
	void OnGameOver();

	BackGround* m_backGround = nullptr;
	Player* m_player = nullptr;
	GameCamera* m_gameCamera = nullptr;

	int m_itemGetCount = 0;
	int m_starSum = 0;

	SkyCube* m_skyCube = nullptr;		//�X�J�C�L���[�u�B
	Vector3 m_skyCubePos = Vector3::Zero;
	int m_skyCubeType = enSkyCubeType_Day;
};