/// <summary>
/// アイテムを管理するクラス。
/// </summary>
#pragma once

class Player;

class Item :public IGameObject
{
public:
	/// <summary>
	/// 位置ベクトルを設定します。
	/// </summary>
	/// <param name="pos">設定する位置を表す Vector3 型の参照。</param>
	void SetPosition(Vector3 pos)
	{
		m_position = pos;
	}

private:
	bool Start()override final;
	void Update()override final;
	void Render(RenderContext& rc)override final;

	/// <summary>
	/// アイテムの回転処理。
	/// </summary>
	void Rotation();

	/// <summary>
	/// アイテムを削除します。
	/// </summary>
	void DeleteItem();

	Player* m_player = nullptr;

	ModelRender m_modelRender;
	Vector3 m_position = Vector3::Zero;
	Quaternion m_rotation;
};