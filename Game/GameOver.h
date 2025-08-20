/// <summary>
/// ゲームオーバー画面を管理するクラス。
/// </summary>
#pragma once
class GameOver :public IGameObject
{
public:
	~GameOver();

private:
	bool Start() override final;
	void Update() override final;
	void Render(RenderContext& rc)override final;

	SpriteRender m_spriteRender;
};
