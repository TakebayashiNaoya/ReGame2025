/// <summary>
/// �Q�[���J�������Ǘ�����N���X�B
/// </summary>
#pragma once

class Player;

class GameCamera :public IGameObject
{
private:
	bool Start()override final;
	void Update()override final;

	Player* m_player = nullptr;

	Vector3 m_toCameraPos = Vector3::Zero;
};

