/// <summary>
/// �Q�[���N���A��ʂ��Ǘ�����N���X�B
/// </summary>
#pragma once
class GameClear :public IGameObject
{
public:
	~GameClear();

private:
	bool Start() override final;
	void Update() override final;
	void Render(RenderContext& rc)override final;

	SpriteRender m_spriteRender;
};

