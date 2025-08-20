/// <summary>
/// ステージを管理するクラス。
/// </summary>
#pragma once
class BackGround :public IGameObject
{
private:
	bool Start()override final;
	void Render(RenderContext& rc)override final;

	ModelRender m_modelRender;
	PhysicsStaticObject physicsStaticObject;
};

