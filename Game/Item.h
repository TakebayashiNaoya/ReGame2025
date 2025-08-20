/// <summary>
/// �A�C�e�����Ǘ�����N���X�B
/// </summary>
#pragma once

class Player;

class Item :public IGameObject
{
public:
	/// <summary>
	/// �ʒu�x�N�g����ݒ肵�܂��B
	/// </summary>
	/// <param name="pos">�ݒ肷��ʒu��\�� Vector3 �^�̎Q�ƁB</param>
	void SetPosition(Vector3 pos)
	{
		m_position = pos;
	}

private:
	bool Start()override final;
	void Update()override final;
	void Render(RenderContext& rc)override final;

	/// <summary>
	/// �A�C�e���̉�]�����B
	/// </summary>
	void Rotation();

	/// <summary>
	/// �A�C�e�����폜���܂��B
	/// </summary>
	void DeleteItem();

	Player* m_player = nullptr;

	ModelRender m_modelRender;
	Vector3 m_position = Vector3::Zero;
	Quaternion m_rotation;
};